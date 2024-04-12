/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 91 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    struct ii_val{
        int i_val;
        int isdigit;
    }
    /* ... */

#line 147 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
