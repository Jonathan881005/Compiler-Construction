/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

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

    struct symbol_node {
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        int isarray;
        char* element_type;
        struct symbol_node *next;
    };

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
    int notlogic = 0;
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
    : VAR ID TypeName { insert_symbol($2, $3, "-"); }
    | VAR ID TypeName ASSIGN Expression { insert_symbol($2, $3, "-"); }
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
    : EL {exptype = eltype;} 
    | boolexp  
      LAND Expression { if(strcmp(betype, "bool") != 0) printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, betype);
                        printf("LAND\n"); exptype = "bool"; }
    | Expression LOR boolexp {if(strcmp(betype, "bool") != 0)
                                        printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, betype);
                                        printf("LOR\n"); exptype = "bool"; }
   
;


EL
    : EL GTR Term {printf("GTR\n");} {eltype = "bool";}
    | EL LSS Term {printf("LSS\n");} {eltype = "bool";}
    | EL GEQ Term {printf("GEQ\n");} {eltype = "bool";}
    | EL LEQ Term {printf("LEQ\n");} {eltype = "bool";}
    | EL EQL Term {printf("EQL\n");} {eltype = "bool";}
    | EL NEQ Term {printf("NEQ\n");} {eltype = "bool";}
    | EL ADD Term {if(strcmp(eltype, termtype)!=0)
                        {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        printf("ADD\n");}
    | EL SUB Term {if(strcmp(eltype, termtype)!=0)
                        {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        printf("SUB\n");}
    | Term {eltype = termtype;}
;


Term
    : Term MUL factor {printf("MUL\n");}
    | Term QUO factor {printf("QUO\n");}
    | Term REM factor { if(strcmp(factortype, "int32") != 0 || strcmp(remtype, "int32"))
                            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, "float32"); 
                            
                            printf("REM\n");}
    | factor {termtype = factortype;remtype = factortype;}
;

factor
    : Operand {factortype = optype;}
    | INT '(' factor ')'    {printf("F to I\n");
                            factortype = strdup("int32");}
    | FLOAT '(' factor ')'  {printf("I to F\n");
                            factortype = strdup("float32");}
    | ADD factor {printf("POS\n");}
    | SUB factor {printf("NEG\n");}
    | NOT factor {printf("NOT\n");}
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
            if( address == -1) 
                printf("error:%d: undefined: %s\n", yylineno+1, $<s_val>1);
            else
                printf("IDENT (name=%s, address=%d)\n", $1, address);
            }
    | '(' Expression ')' 
;


Literal
    : INT_LIT { printf("INT_LIT %d\n", $1); LIT_type = "int32";}
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n", $1); LIT_type = "float32";}
    | TRUE { printf("TRUE\n"); LIT_type = "bool";}
    | FALSE { printf("FALSE\n"); LIT_type = "bool";}
    | '\"' STRING_LIT '\"' { printf("STRING_LIT %s\n", $2); LIT_type = "string";}
;



SimpleStmt 
    : AssignmentStmt 
    | ExpressionStmt
    | IncDecStmt
;

AssignmentStmt
    : Expression {if(assign_type) free(assign_type);
                assign_type = strdup(factortype);}  ASSIGN EL 
                {if((strcmp(assign_type, eltype)!=0) && (strcmp(assign_type,"")!= 0 ) )
                {
                    printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, assign_type, eltype);
                }printf("ASSIGN\n");}
    | Expression { if(isLit) badassign = 1;} ADD_ASSIGN EL 
        { if(badassign){
            badassign = 0;
            printf("error:%d: cannot assign to %s\n", yylineno, LIT_type);
        } printf("ADD_ASSIGN\n"); }
    | Expression SUB_ASSIGN EL { printf("SUB_ASSIGN\n"); }
    | Expression MUL_ASSIGN EL { printf("MUL_ASSIGN\n"); }
    | Expression QUO_ASSIGN EL { printf("QUO_ASSIGN\n"); }
    | Expression REM_ASSIGN EL { printf("REM_ASSIGN\n"); }
;

ExpressionStmt
    : Expression
;

IncDecStmt
    : Expression INC { printf("INC\n");}
    | Expression DEC { printf("DEC\n");}
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
    : boolexp {contype = betype; }{if(strcmp(contype,"bool")!=0) 
                    printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, contype);}
;

ForStmt
    : FOR Condition Block
    | FOR ForClause Block
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
    : PRINT '(' Expression ')' { printf("PRINT %s\n", exptype); }
    | PRINTLN '(' Expression ')' { printf("PRINTLN %s\n", exptype); }
;


%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    create_symbol();
    yylineno = 0;
    yyparse();
    dump_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
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
    if(!table[scope_level])
        table[scope_level] = node;
    else{
        struct symbol_node *temp = table[scope_level];
        while(temp->next) temp = temp->next;
        node->index = temp->index+1;
        temp->next = node;
    }
    printf("> Insert {%s} into symbol table (scope level: %d)\n", name, scope_level);
    
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
    printf("> Dump symbol table (scope level: %d)\n", scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(struct symbol_node *temp = table[scope_level]; temp; temp = temp->next)
        printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            temp->index, temp->name, temp->type, temp->address, temp->lineno, temp->element_type);
    scope_level -= 1;

}
