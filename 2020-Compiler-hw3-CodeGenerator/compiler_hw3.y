/*	Definition section */
%{
    #include "common.h" 

    FILE *file;
    int HAS_ERROR = 0;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol();
    static int lookup_symbol();
    static void dump_symbol();
    void compare2code();
    void compare();
    void andor2code();

    struct symbol_node {
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        int isarray;
        int reg;
        char* element_type;
        struct symbol_node *next;
    };

    struct regst {
        int inum;   // 0
        float fnum; // 1
        int boo;    // 2
        char* str;  // 3
        int type; 
        int isarray;
        int array[5];
    };
    struct regst r[105];
    int totalreg = 0;
    int lookreg;
    int assreg;
    int looktype; //type: 0=int 1=float 2=string 3=bool 4=array
    int lookarrtype; //arrtype: 0=int 1=float 2=string 3=bool
    int cplabel1 = 0, cplabel2 = 1; // label for compare & if
    int forlabel = 0;

    int errortype = 0;
    int tempint;
    float tempfloat;
    int tempbool;
    char* tempstr;
    int temptype;

    int scope_level = -1;
    struct symbol_node *table[10] = {};
    int current_address = 0;
    char *arraytype = NULL;

    char *contype = NULL;
    char *exptype = NULL;
    char *eltype = NULL;
    char *termtype = NULL;
    char *factortype = NULL;
    char *optype = NULL;

    char *betype = NULL;
    char *LIT_type = NULL;
    char *ID_type = NULL;
    char *arrayidtype = NULL;
    char *remtype = NULL;
    char *assign_type = NULL;
    int isLit = 0;
    int badassign = 0;
    
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union{
    int i_val;
    float f_val;
    char *s_val;
    struct ii_val{
        int i_val;
        int isdigit;
    }
    /* ... */
}

/* Token without return */
%token GTR LSS GEQ LEQ EQL NEQ
%token ADD SUB MUL QUO REM INC DEC 
%token ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR NOT 
%token NEWLINE PRINT PRINTLN IF ELSE FOR
%token INT FLOAT BOOL TRUE FALSE STRING VAR

/* 
var x int32 = 5
Declaration
VAR ID INT assign INT_LIT
*/

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type TypeName ArrayType

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%
Program
    : StatementList
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclatationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
;

DeclatationStmt 
    : VAR ID TypeName { 
            insert_symbol($2, $3, "-"); 
            switch(typestr2int($3)){
                case 0: fprintf(file, "ldc 0\n"); // int
                        fprintf(file, "istore %d\n", totalreg-1);
                        break;
                case 1: fprintf(file, "ldc 0.0\n"); // float
                        fprintf(file, "fstore %d\n", totalreg-1);
                        break;
                case 3: fprintf(file, "ldc \"\"\n"); // string
                        fprintf(file, "astore %d\n", totalreg-1);
            }
        }
    | VAR ID TypeName ASSIGN Expression { 
            insert_symbol($2, $3, "-"); 
            switch(typestr2int($3)){
                case 0: fprintf(file, "istore %d\n", totalreg-1);
                        break;
                case 1: fprintf(file, "fstore %d\n", totalreg-1);
                        break;
                case 3: fprintf(file, "astore %d\n", totalreg-1);
            }
        }
    | VAR ID ArrayType { insert_symbol($2, "array", $3); }
    | VAR ID ArrayType ASSIGN Expression { insert_symbol($2, "array", $3); }

;

Type 
    : TypeName 
    | ArrayType
;

TypeName
    : INT {$$ = "int32"; }
    | FLOAT {$$ = "float32";}
    | STRING {$$ = "string";}
    | BOOL {$$ = "bool";}
;

ArrayType
    : '[' Expression ']' Type {$$ = $4;}
;

boolexp
    : Expression {betype = exptype;}
;

Expression
    : EL {exptype = eltype; } 
    | boolexp LAND Expression 
    { 
        if(strcmp(betype, "bool") != 0) { errortype = 1; printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, betype); HAS_ERROR = 1; }
        printf("LAND\n"); exptype = "bool"; 
        fprintf(file, "iand\n");
        }
    | Expression LOR boolexp 
    { 
        if(strcmp(betype, "bool") != 0){ errortype = 2; printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, betype); HAS_ERROR = 1;}
        printf("LOR\n"); exptype = "bool"; 
        fprintf(file, "ior\n");
    }
;


EL
    : EL GTR Term {printf("GTR\n"); compare("GTR"); eltype = "bool";}
    | EL LSS Term {printf("LSS\n"); compare("LSS"); eltype = "bool";}
    | EL GEQ Term {printf("GEQ\n"); compare("GEQ"); eltype = "bool";}
    | EL LEQ Term {printf("LEQ\n"); compare("LEQ"); eltype = "bool";} { fprintf(file, "here is LEQ\n"); }
    | EL EQL Term {printf("EQL\n"); compare("EQL"); eltype = "bool";}
    | EL NEQ Term {printf("NEQ\n"); compare("NEQ"); eltype = "bool";}
    | EL ADD Term {if(strcmp(eltype, termtype)!=0)
                        {   errortype = 3;
                            HAS_ERROR = 1;
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        switch(typestr2int(termtype)){
                            case 0: fprintf(file, "iadd\n");
                                    break;
                            case 1: fprintf(file, "fadd\n");
                                    break;
                            }
                        }
    | EL SUB Term {if(strcmp(eltype, termtype)!=0)
                        {   errortype = 4;
                            HAS_ERROR = 1;
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        switch(typestr2int(termtype)){
                            case 0: fprintf(file, "isub\n");
                                    break;
                            case 1: fprintf(file, "fsub\n");
                                    break;
                            }
                        }
    | Term {eltype = termtype;}
;


Term
    : Term MUL factor {printf("MUL\n");
                        switch(typestr2int(termtype)){
                            case 0: fprintf(file, "imul\n");
                                    break;
                            case 1: fprintf(file, "fmul\n");
                                    break;
                            }
                        }
    | Term QUO factor {printf("DIV\n");
                        switch(typestr2int(termtype)){
                            case 0: fprintf(file, "idiv\n");
                                    break;
                            case 1: fprintf(file, "fdiv\n");
                                    break;
                            }
                        }
    | Term REM factor { if(strcmp(factortype, "int32") != 0 || strcmp(remtype, "int32")){
                            errortype = 5;
                            HAS_ERROR = 1;
                            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, "float32"); 
                            }
                            printf("REM\n");
                        fprintf(file, "irem\n");}
    | factor {termtype = factortype;remtype = factortype;}
;

factor
    : Operand {factortype = optype;}
    | INT '(' factor ')'    {printf("F to I\n");
                            fprintf(file,"f2i\n");
                            factortype = strdup("int32");}
    | FLOAT '(' factor ')'  {printf("I to F\n");
                            fprintf(file,"i2f\n");
                            factortype = strdup("float32");}
    | ADD factor {printf("POS\n");}
    | SUB factor {printf("NEG\n"); 
                    if(factortype[0] == 'f') fprintf(file, "fneg\n");
                    else fprintf(file, "ineg\n");}
    | NOT factor {printf("NOT\n");
                    fprintf(file, "iconst_1\n");
                    fprintf(file, "ixor\n");}
    | factor {arrayidtype = factortype;} '[' Expression ']' {factortype = arrayidtype;}
;

Operand
    : Literal {isLit = 1; optype = LIT_type;}
    | ID 
        {   isLit = 0;
            char *temp;
            int address = lookup_symbol($<s_val>1, &temp);
            ID_type = strdup(temp);
            optype = ID_type;
            if( address == -1) {
                errortype = 6;
                HAS_ERROR = 1;
                printf("error:%d: undefined: %s\n", yylineno+1, $<s_val>1);
                }
            else
                printf("IDENT (name=%s, address=%d)\n", $1, address);
            
                switch(typestr2int(ID_type)){
                    case 0: fprintf(file, "iload %d\n", lookreg);
                            break;
                    case 1: fprintf(file, "fload %d\n", lookreg);
                            break;
                    case 3: fprintf(file, "aload %d\n", lookreg);
                }

        }
    | '(' Expression ')' 
;


Literal
    : INT_LIT { tempint = $1; temptype = 0; LIT_type = "int32";
            fprintf(file, "ldc %d\n", tempint);    
            }
    | FLOAT_LIT { tempfloat = $1; temptype = 1; LIT_type = "float32";
            fprintf(file, "ldc %f\n", tempfloat);
            }
    | TRUE { tempbool = 1; temptype = 2; LIT_type = "bool";
            fprintf(file, "iconst_1\n"); 
            }
    | FALSE { tempbool = 0; temptype = 2; LIT_type = "bool";
            fprintf(file, "iconst_0\n"); 
            }
    | '\"' STRING_LIT '\"' { tempstr = $2; temptype = 3; LIT_type = "string";
            fprintf(file, "ldc \"%s\"\n", tempstr); 
            }
;




SimpleStmt 
    : AssignmentStmt 
    | ExpressionStmt
    | IncDecStmt
;

AssignmentStmt
    : Expression {if(assign_type) free(assign_type); assign_type = strdup(factortype); assreg = lookreg;}  
        ASSIGN EL
        { if((strcmp(assign_type, eltype)!=0) && (strcmp(assign_type,"")!= 0 ) )
            {
                errortype = 7;
                HAS_ERROR = 1;
                printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, assign_type, eltype);
            }
            printf("ASSIGN\n");
                switch(eltype[0]){
                    case 'i': fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f': fprintf(file, "fstore %d\n",assreg);
                                break;
                    case 's': fprintf(file, "astore %d\n",assreg);
                }
            }
    | Expression { if(isLit) badassign = 1; assreg = lookreg;} ADD_ASSIGN EL 
        { if(badassign)
            {
                badassign = 0;
                errortype = 8;
                HAS_ERROR = 1;
                printf("error:%d: cannot assign to %s\n", yylineno, LIT_type);
            } 
            printf("ADD_ASSIGN\n");
                switch(eltype[0]){
                    case 'i':   fprintf(file, "iadd\n");
                                fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f':   fprintf(file, "fadd\n");
                                fprintf(file, "fstore %d\n",assreg);
                }
            }
    | Expression SUB_ASSIGN EL { 
                printf("SUB_ASSIGN\n");
                switch(eltype[0]){
                    case 'i':   fprintf(file, "isub\n");
                                fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f':   fprintf(file, "fsub\n");
                                fprintf(file, "fstore %d\n",assreg);
                } 
            }
    | Expression MUL_ASSIGN EL {
                printf("MUL_ASSIGN\n"); 
                switch(eltype[0]){
                    case 'i':   fprintf(file, "imul\n");
                                fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f':   fprintf(file, "fmul\n");
                                fprintf(file, "fstore %d\n",assreg);
                }
            }
    | Expression QUO_ASSIGN EL { 
                printf("QUO_ASSIGN\n"); 
                switch(eltype[0]){
                    case 'i':   fprintf(file, "idiv\n");
                                fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f':   fprintf(file, "fdiv\n");
                                fprintf(file, "fstore %d\n",assreg);
                }
            }
    | Expression REM_ASSIGN EL {
                printf("REM_ASSIGN\n"); 
                switch(eltype[0]){
                    case 'i':   fprintf(file, "irem\n");
                                fprintf(file, "istore %d\n",assreg);
                                break;
                    case 'f':   fprintf(file, "frem\n");
                                fprintf(file, "fstore %d\n",assreg);
                }
            }
;

ExpressionStmt
    : Expression
;

IncDecStmt
    : Expression INC {  printf("INC\n");
                        switch(typestr2int(exptype)){
                            case 0: fprintf(file, "ldc 1\niadd\nistore %d\n", lookreg); 
                                break;   
                            case 1: fprintf(file, "ldc 1.0\nfadd\nfstore %d\n", lookreg); 
                                break;   
                        }
                        }
    | Expression DEC {  printf("DEC\n");
                        switch(typestr2int(exptype)){
                            case 0: fprintf(file, "ldc 1\nisub\nistore %d\n", lookreg); 
                                break;   
                            case 1: fprintf(file, "ldc 1.0\nfsub\nfstore %d\n", lookreg); 
                                break;   
                        }
                        }
;


Block
    : '{' {create_symbol();} StatementList '}' {dump_symbol();}
;

IfStmt
    : IF Condition Block 
    | IF Condition Block ELSE Block 
    | IF Condition Block ELSE IfStmt 
;

Condition
    : boolexp {contype = betype; }{

                    // if(strcmp(contype,"bool")!=0) {
                    //     printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, contype);
                    //     errortype = 9;
                    //     HAS_ERROR = 1;
                    //     }
                    }
;

ForStmt
    : SimpleFor

    | FOR { fprintf(file, "label%d_begin:\n",forlabel); }  
      ForClause { fprintf(file, "ifeq label%d_end\n",forlabel); } 
      Block { fprintf(file, "goto label%d_begin\n",forlabel); }
            { fprintf(file, "label%d_end:\n",forlabel++); }  

;

SimpleFor
    : FOR { fprintf(file, "label%d_begin:\n",forlabel); }  
      Expression { fprintf(file, "ifeq label%d_end\n",forlabel); } 
      Block { fprintf(file, "goto label%d_begin\n",forlabel); }
            { fprintf(file, "label%d_end:\n",forlabel++); }  
;


ForClause
    : InitStmt ';' Condition ';' PostStmt 
;

InitStmt 
    : SimpleStmt
;

PostStmt
    : SimpleStmt
;

PrintStmt
    : PRINT  '(' Expression ')' 
            {   
                switch(typestr2int(exptype)){
                    case 0: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(I)V\n");
                            break;
                    case 1: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(F)V\n");
                            break;
                    case 2: andor2code();
                    case 3: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                            break;
                }
            }
    | PRINTLN  '(' Expression ')' 
            {   
                switch(typestr2int(exptype)){
                    case 0: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
                            break;
                    case 1: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
                            break;
                    case 2: andor2code();
                    case 3: fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                            break;
                }
            }
;


%%

/* C code section */
int main(int argc, char *argv[])
{
    file = fopen("hw3.j","w");
    // fprintf(file,"%d\n",typestr2int("int32"));
    // fprintf(file,"%d\n",typestr2int("float32"));
    // fprintf(file,"%d\n",typestr2int("bool"));
    // fprintf(file,"%d\n",typestr2int("string"));
    // fprintf(file,"%d\n",typestr2int("array"));
	fprintf(file, ".source hw3.j\n");
	fprintf(file, ".class public Main\n");
	fprintf(file, ".super java/lang/Object\n");
	fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
	fprintf(file, ".limit stack 100\n");
	fprintf(file, ".limit locals 100 ;\n");

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    create_symbol();

    yylineno = 0;
    yyparse();

    dump_symbol();

    fclose(yyin);

	fprintf(file, "return\n");
	fprintf(file, ".end method\n");

    if (HAS_ERROR) {
        remove("hw3.j");
        fprintf(file,"error type = %d\n",errortype);
    }
    return 0;
}


static void create_symbol() {
    scope_level += 1;
    table[scope_level] = NULL;
}

static void insert_symbol(char* name, char* type, char* element_type) {
    for (struct symbol_node *temp = table[scope_level]; temp; temp = temp -> next  ){
        if(strcmp(temp->name, name) == 0){
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, name, temp->lineno);
            return;
        }
    }

    struct symbol_node *node = malloc(sizeof(struct symbol_node));
    node->index = 0;
    node->name = name;
    node->type = type;
    node->address = current_address++;
    node->lineno = yylineno;
    node->element_type = element_type;
    node->next = NULL;
    node->reg = totalreg++;
    if(!table[scope_level])
        table[scope_level] = node;
    else{
        struct symbol_node *temp = table[scope_level];
        while(temp->next) temp = temp->next;
        node->index = temp->index+1;
        temp->next = node;
    }
    lookreg = node->reg;
}

static int lookup_symbol(char* name, char **type) {
    int level = scope_level;
    struct symbol_node *temp = table[level];
    while(level > 0 && !temp){
        level--;
        temp = table[level];
    }

    while(strcmp(name, temp->name) != 0){
        if(!temp->next){
            if(level == 0){
                temp = NULL;
                break;
            }
            else{
                level--;
                temp = table[level];
            }
        }
        else   
            temp = temp->next;
    }
    

    if(temp){
        lookreg = temp->reg; // 找到的node的reg存在lookreg
        looktype = typestr2int(temp->type);
        if(looktype == 4) lookarrtype = typestr2int(temp->element_type);
        if(strcmp(temp->type, "array") == 0)
            *type = temp->element_type;
        else
            *type = temp->type;
        return temp->address;
    }
    else
        return -1;
}

static void dump_symbol() {
    // printf("> Dump symbol table (scope level: %d)\n", scope_level);
    // printf("%-10s%-10s%-10s%-10s%-10s%s\n",
    //        "Index", "Name", "Type", "Address", "Lineno", "Element type");
    // for(struct symbol_node *temp = table[scope_level]; temp; temp = temp->next)
    //     printf("%-10d%-10s%-10s%-10d%-10d%s\n",
    //         temp->index, temp->name, temp->type, temp->address, temp->lineno, temp->element_type);
    scope_level -= 1;

}

int typestr2int(char* str){
    switch(str[0]){
        case 'i': return 0; // int32
        case 'f': return 1; // float32
        case 'b': return 2; // bool
        case 's': return 3; // string
        case 'a': return 4; // array
    };
}

void compare2code(char ifstmt[5])
{   
	fprintf(file, "%s L_cmp_%d\n",ifstmt, cplabel1);
	fprintf(file, "iconst_0\n");
	fprintf(file, "goto L_cmp_%d\n",cplabel2);
	fprintf(file, "L_cmp_%d:\n",cplabel1);
	fprintf(file, "iconst_1\n");
	fprintf(file, "L_cmp_%d:\n",cplabel2);
    cplabel1 = cplabel1 + 2;
    cplabel2 = cplabel2 + 2;
}

void compare(char str[5])	
{
    if(strcmp(exptype, "int32") == 0)
	    fprintf(file, "isub\n");
    else if(strcmp(exptype, "float32") == 0)
	    fprintf(file, "fcmpl\n");

	if(strcmp(str,"EQL")==0)
		compare2code("ifeq");
	else if(strcmp(str,"NEQ")==0)
		compare2code("ifnq");
	else if(strcmp(str,"GTR")==0)
		compare2code("ifgt");
	else if(strcmp(str,"LSS")==0)
		compare2code("iflt");
	else if(strcmp(str,"GEQ")==0)
		compare2code("ifge");
	else if(strcmp(str,"LEQ")==0)
		compare2code("ifle");
}

void andor2code()
{   
	fprintf(file, "ifne L_cmp_%d\n", cplabel1);
	fprintf(file, "ldc \"false\"\n");
	fprintf(file, "goto L_cmp_%d\n",cplabel2);
	fprintf(file, "L_cmp_%d:\n",cplabel1);
	fprintf(file, "ldc \"true\"\n");
	fprintf(file, "L_cmp_%d:\n",cplabel2);
    cplabel1 = cplabel1 + 2;
    cplabel2 = cplabel2 + 2;
}