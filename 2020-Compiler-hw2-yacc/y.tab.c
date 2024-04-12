/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

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

#line 120 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GTR = 258,
    LSS = 259,
    GEQ = 260,
    LEQ = 261,
    EQL = 262,
    NEQ = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    QUO = 267,
    REM = 268,
    INC = 269,
    DEC = 270,
    ASSIGN = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    QUO_ASSIGN = 275,
    REM_ASSIGN = 276,
    LAND = 277,
    LOR = 278,
    NOT = 279,
    NEWLINE = 280,
    PRINT = 281,
    PRINTLN = 282,
    IF = 283,
    ELSE = 284,
    FOR = 285,
    INT = 286,
    FLOAT = 287,
    BOOL = 288,
    TRUE = 289,
    FALSE = 290,
    STRING = 291,
    VAR = 292,
    INT_LIT = 293,
    FLOAT_LIT = 294,
    STRING_LIT = 295,
    ID = 296
  };
#endif
/* Tokens.  */
#define GTR 258
#define LSS 259
#define GEQ 260
#define LEQ 261
#define EQL 262
#define NEQ 263
#define ADD 264
#define SUB 265
#define MUL 266
#define QUO 267
#define REM 268
#define INC 269
#define DEC 270
#define ASSIGN 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define QUO_ASSIGN 275
#define REM_ASSIGN 276
#define LAND 277
#define LOR 278
#define NOT 279
#define NEWLINE 280
#define PRINT 281
#define PRINTLN 282
#define IF 283
#define ELSE 284
#define FOR 285
#define INT 286
#define FLOAT 287
#define BOOL 288
#define TRUE 289
#define FALSE 290
#define STRING 291
#define VAR 292
#define INT_LIT 293
#define FLOAT_LIT 294
#define STRING_LIT 295
#define ID 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    struct ii_val{
        int i_val;
        int isdigit;
    }
    /* ... */

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    46,     2,     2,     2,     2,     2,
      44,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   105,   106,   110,   111,   112,   113,   114,
     115,   116,   120,   121,   122,   123,   128,   129,   133,   134,
     135,   136,   140,   144,   148,   149,   152,   160,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   166,
     171,   176,   181,   182,   183,   187,   191,   192,   194,   196,
     197,   198,   199,   199,   203,   204,   215,   220,   221,   222,
     223,   224,   230,   231,   232,   236,   236,   242,   242,   247,
     248,   249,   250,   254,   258,   259,   264,   264,   268,   269,
     270,   274,   274,   279,   280,   284,   288,   292,   296,   297
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GTR", "LSS", "GEQ", "LEQ", "EQL", "NEQ",
  "ADD", "SUB", "MUL", "QUO", "REM", "INC", "DEC", "ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR",
  "NOT", "NEWLINE", "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "INT",
  "FLOAT", "BOOL", "TRUE", "FALSE", "STRING", "VAR", "INT_LIT",
  "FLOAT_LIT", "STRING_LIT", "ID", "'['", "']'", "'('", "')'", "'\"'",
  "'{'", "'}'", "';'", "$accept", "Program", "StatementList", "Statement",
  "DeclatationStmt", "Type", "TypeName", "ArrayType", "boolexp",
  "Expression", "EL", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "Term",
  "factor", "$@7", "Operand", "Literal", "SimpleStmt", "AssignmentStmt",
  "$@8", "$@9", "ExpressionStmt", "IncDecStmt", "Block", "$@10", "IfStmt",
  "Condition", "$@11", "ForStmt", "ForClause", "InitStmt", "PostStmt",
  "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    91,    93,    40,    41,    34,   123,   125,    59
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     139,     9,     9,     9,   -50,   -39,     5,     9,     9,    27,
      28,   -50,   -50,   -12,   -50,   -50,   -50,     9,    26,   -50,
      52,   139,   -50,    53,    55,     7,    92,    63,    38,   -50,
     -50,    56,   -50,   -50,   -50,    57,    58,    66,    68,   -50,
     -50,   -50,     9,     9,    55,    88,    65,   -50,    65,    65,
      64,     9,     9,    37,    -3,    71,   139,   -50,   -50,   -50,
       9,   -50,   -50,     9,     9,     9,     9,     9,    98,   101,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,    78,   -50,   -50,   -50,   -50,   -50,    15,    22,   -50,
      93,   -50,   -50,     9,    76,    79,   -50,   -50,   -50,   -50,
       9,   107,   109,   -50,   -50,   106,    12,    92,    92,    92,
      92,    55,     9,     9,    63,    63,    63,    63,    63,    63,
      63,    63,    38,    38,    38,     9,   -50,   -50,    18,    77,
     -50,   -50,     8,     9,     9,   -50,    92,    92,   -50,   -50,
     -50,   -50,   -50,   -50,    16,   -50,   -50,     9,    37,    12,
      12,   -50,   -50,   -50,   -50,   -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,    59,    60,     0,    57,    58,    55,     0,     0,    76,
       0,     2,     4,     0,     0,    23,    24,    41,    45,    46,
      54,     0,    62,    63,    64,     0,     0,     0,     0,    49,
      50,    51,     0,     0,    81,    23,     0,    86,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     1,     3,     5,
       0,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    23,    23,    82,
      78,    83,    84,     0,    52,    52,    18,    19,    21,    20,
       0,    12,    14,    56,    61,     0,    25,    69,    70,    71,
      72,    26,     0,     0,    27,    29,    31,    33,    35,    37,
      39,    40,    42,    43,    44,     0,    88,    89,     0,     0,
      47,    48,    23,     0,     0,    77,    66,    68,    28,    30,
      32,    34,    36,    38,    23,    79,    80,     0,     0,    13,
      15,    53,    87,    85,    22,    16,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,    73,   -15,   -50,   -50,   -13,    -2,    -5,    -6,
     -49,   -50,   -50,   -50,   -50,   -50,   -50,    33,     6,   -50,
     -50,   -50,    -8,   -50,   -50,   -50,   -50,   -50,   -36,   -50,
      14,    -4,   -50,   -50,   -50,   -50,   -50,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,   154,   101,   102,    24,    25,
      26,   138,   139,   140,   141,   142,   143,    27,    28,    81,
      29,    30,    31,    32,    68,    69,    33,    34,    35,    56,
      36,    46,    89,    37,    49,    50,   153,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    45,    44,    44,    48,    42,    58,    39,    40,    41,
      90,    54,    91,    92,   107,   108,   109,   110,     1,     2,
      67,    61,    62,   -65,   -67,    63,    64,    65,    66,    53,
      67,    67,   -73,     3,   -23,    67,    87,    88,    67,    67,
       9,    10,   103,    11,    12,    67,     7,    14,    15,    43,
      16,   148,    57,    17,   106,    18,   -73,    94,    95,   151,
     126,    45,   111,   136,   137,    19,    55,   127,    96,    97,
      98,    51,    52,    99,    78,    79,    80,    60,    59,   100,
     -52,    82,    83,    84,   122,   123,   124,    45,    44,   129,
      58,    85,   145,    86,   132,    70,    71,    72,    73,    74,
      75,    76,    77,   114,   115,   116,   117,   118,   119,   120,
     121,    67,    19,    93,   112,     1,     2,   104,   113,   144,
     125,   130,   128,   133,   131,   134,   147,   149,   150,   105,
       3,     4,     5,     6,     7,   155,     8,     9,    10,   152,
      11,    12,   146,    13,    14,    15,   156,    16,     1,     2,
      17,     0,    18,    19,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     0,     8,
       9,    10,     0,    11,    12,     0,    13,    14,    15,     0,
      16,     0,     0,    17,     0,    18,    19
};

static const yytype_int16 yycheck[] =
{
       8,     7,     7,     8,     8,    44,    21,     1,     2,     3,
      46,    17,    48,    49,    63,    64,    65,    66,     9,    10,
      23,    14,    15,    16,    17,    18,    19,    20,    21,    41,
      23,    23,    25,    24,    22,    23,    42,    43,    23,    23,
      31,    32,    45,    34,    35,    23,    28,    38,    39,    44,
      41,    43,     0,    44,    60,    46,    49,    51,    52,    43,
      45,    67,    67,   112,   113,    47,    40,    45,    31,    32,
      33,    44,    44,    36,    11,    12,    13,    22,    25,    42,
      42,    25,    25,    25,    78,    79,    80,    93,    93,    93,
     105,    25,   128,    25,   100,     3,     4,     5,     6,     7,
       8,     9,    10,    70,    71,    72,    73,    74,    75,    76,
      77,    23,    47,    49,    16,     9,    10,    46,    17,   125,
      42,    45,    29,    16,    45,    16,    49,   133,   134,    56,
      24,    25,    26,    27,    28,   148,    30,    31,    32,   147,
      34,    35,   128,    37,    38,    39,   148,    41,     9,    10,
      44,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    34,    35,    -1,    37,    38,    39,    -1,
      41,    -1,    -1,    44,    -1,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    24,    25,    26,    27,    28,    30,    31,
      32,    34,    35,    37,    38,    39,    41,    44,    46,    47,
      51,    52,    53,    54,    58,    59,    60,    67,    68,    70,
      71,    72,    73,    76,    77,    78,    80,    83,    87,    68,
      68,    68,    44,    44,    58,    59,    81,    72,    81,    84,
      85,    44,    44,    41,    59,    40,    79,     0,    53,    25,
      22,    14,    15,    18,    19,    20,    21,    23,    74,    75,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    69,    25,    25,    25,    25,    25,    59,    59,    82,
      78,    78,    78,    49,    68,    68,    31,    32,    33,    36,
      42,    56,    57,    45,    46,    52,    59,    60,    60,    60,
      60,    58,    16,    17,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    42,    45,    45,    29,    81,
      45,    45,    59,    16,    16,    48,    60,    60,    61,    62,
      63,    64,    65,    66,    59,    78,    80,    49,    43,    59,
      59,    43,    72,    86,    55,    56,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    58,    59,    59,    59,    61,    60,    62,
      60,    63,    60,    64,    60,    65,    60,    66,    60,    60,
      60,    60,    67,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    68,    70,    70,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    74,    73,    75,    73,    73,
      73,    73,    73,    76,    77,    77,    79,    78,    80,    80,
      80,    82,    81,    83,    83,    84,    85,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     3,     5,     3,     5,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     3,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       3,     1,     3,     3,     3,     1,     1,     4,     4,     2,
       2,     2,     0,     5,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     0,     4,     0,     4,     3,
       3,     3,     3,     1,     2,     2,     0,     4,     3,     5,
       5,     0,     2,     3,     3,     5,     1,     1,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 12:
#line 120 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].s_val), (yyvsp[0].s_val), "-"); }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-3].s_val), (yyvsp[-2].s_val), "-"); }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].s_val), "array", (yyvsp[0].s_val)); }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-3].s_val), "array", (yyvsp[-2].s_val)); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.s_val) = "int32"; }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.s_val) = "float32";}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.s_val) = "string";}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.s_val) = "bool";}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.s_val) = (yyvsp[0].s_val);}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "compiler_hw2.y" /* yacc.c:1646  */
    {betype = exptype;}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    {exptype = eltype;}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp(betype, "bool") != 0) printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, betype);
                        printf("LAND\n"); exptype = "bool"; }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
    {if(strcmp(betype, "bool") != 0)
                                        printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, betype);
                                        printf("LOR\n"); exptype = "bool"; }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 160 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("GTR\n");}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("LSS\n");}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("GEQ\n");}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 162 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("LEQ\n");}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 163 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("EQL\n");}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 164 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 165 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("NEQ\n");}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = "bool";}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "compiler_hw2.y" /* yacc.c:1646  */
    {if(strcmp(eltype, termtype)!=0)
                        {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        printf("ADD\n");}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 171 "compiler_hw2.y" /* yacc.c:1646  */
    {if(strcmp(eltype, termtype)!=0)
                        {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno, eltype, factortype);
                        }
                        printf("SUB\n");}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 176 "compiler_hw2.y" /* yacc.c:1646  */
    {eltype = termtype;}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 181 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("MUL\n");}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 182 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("QUO\n");}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 183 "compiler_hw2.y" /* yacc.c:1646  */
    { if(strcmp(factortype, "int32") != 0 || strcmp(remtype, "int32"))
                            printf("error:%d: invalid operation: (operator REM not defined on %s)\n", yylineno, "float32"); 
                            
                            printf("REM\n");}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 187 "compiler_hw2.y" /* yacc.c:1646  */
    {termtype = factortype;remtype = factortype;}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 191 "compiler_hw2.y" /* yacc.c:1646  */
    {factortype = optype;}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 192 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("F to I\n");
                            factortype = strdup("int32");}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 194 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("I to F\n");
                            factortype = strdup("float32");}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 196 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("POS\n");}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 197 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("NEG\n");}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 198 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("NOT\n");}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {arrayidtype = factortype;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 199 "compiler_hw2.y" /* yacc.c:1646  */
    {factortype = arrayidtype;}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 203 "compiler_hw2.y" /* yacc.c:1646  */
    {isLit = 1; optype = LIT_type;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    {   isLit = 0;
            char *temp;
            int address = lookup_symbol((yyvsp[0].s_val), &temp);
            ID_type = strdup(temp);
            optype = ID_type;
            if( address == -1) 
                printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].s_val));
            else
                printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), address);
            }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 220 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\n", (yyvsp[0].i_val)); LIT_type = "int32";}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 221 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %.6f\n", (yyvsp[0].f_val)); LIT_type = "float32";}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 222 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("TRUE\n"); LIT_type = "bool";}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 223 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("FALSE\n"); LIT_type = "bool";}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 224 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); LIT_type = "string";}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 236 "compiler_hw2.y" /* yacc.c:1646  */
    {if(assign_type) free(assign_type);
                assign_type = strdup(factortype);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 238 "compiler_hw2.y" /* yacc.c:1646  */
    {if((strcmp(assign_type, eltype)!=0) && (strcmp(assign_type,"")!= 0 ) )
                {
                    printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, assign_type, eltype);
                }printf("ASSIGN\n");}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 242 "compiler_hw2.y" /* yacc.c:1646  */
    { if(isLit) badassign = 1;}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "compiler_hw2.y" /* yacc.c:1646  */
    { if(badassign){
            badassign = 0;
            printf("error:%d: cannot assign to %s\n", yylineno, LIT_type);
        } printf("ADD_ASSIGN\n"); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 247 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("SUB_ASSIGN\n"); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("MUL_ASSIGN\n"); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("QUO_ASSIGN\n"); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 250 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("REM_ASSIGN\n"); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 258 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("INC\n");}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 259 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("DEC\n");}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 264 "compiler_hw2.y" /* yacc.c:1646  */
    {create_symbol();}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 264 "compiler_hw2.y" /* yacc.c:1646  */
    {dump_symbol();}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 274 "compiler_hw2.y" /* yacc.c:1646  */
    {contype = betype; }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 274 "compiler_hw2.y" /* yacc.c:1646  */
    {if(strcmp(contype,"bool")!=0) 
                    printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, contype);}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 296 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("PRINT %s\n", exptype); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 297 "compiler_hw2.y" /* yacc.c:1646  */
    { printf("PRINTLN %s\n", exptype); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1874 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 301 "compiler_hw2.y" /* yacc.c:1906  */


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
