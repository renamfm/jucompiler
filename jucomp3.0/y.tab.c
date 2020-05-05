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
#line 1 "jucompiler.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "tree.h"
#include "symbol_table.h"

int yylex (void);
void yyerror (char *s);

char* str;
int flag = 0, containsErrors = 0;
AST_pointer root = NULL , aux = NULL, aux2 = NULL;
int linha = 0;
int coluna = 0;

#line 84 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INTLIT = 259,
    REALLIT = 260,
    STRLIT = 261,
    BOOLLIT = 262,
    AND = 263,
    ASSIGN = 264,
    STAR = 265,
    COMMA = 266,
    DIV = 267,
    EQ = 268,
    GE = 269,
    GT = 270,
    LBRACE = 271,
    LE = 272,
    LPAR = 273,
    LSQ = 274,
    LT = 275,
    MINUS = 276,
    MOD = 277,
    NE = 278,
    NOT = 279,
    OR = 280,
    PLUS = 281,
    RBRACE = 282,
    RPAR = 283,
    RSQ = 284,
    SEMICOLON = 285,
    ARROW = 286,
    LSHIFT = 287,
    RSHIFT = 288,
    XOR = 289,
    BOOL = 290,
    CLASS = 291,
    DOTLENGTH = 292,
    DOUBLE = 293,
    ELSE = 294,
    IF = 295,
    INT = 296,
    PRINT = 297,
    PARSEINT = 298,
    PUBLIC = 299,
    RETURN = 300,
    STATIC = 301,
    STRING = 302,
    VOID = 303,
    WHILE = 304,
    RESERVED = 305
  };
#endif
/* Tokens.  */
#define ID 258
#define INTLIT 259
#define REALLIT 260
#define STRLIT 261
#define BOOLLIT 262
#define AND 263
#define ASSIGN 264
#define STAR 265
#define COMMA 266
#define DIV 267
#define EQ 268
#define GE 269
#define GT 270
#define LBRACE 271
#define LE 272
#define LPAR 273
#define LSQ 274
#define LT 275
#define MINUS 276
#define MOD 277
#define NE 278
#define NOT 279
#define OR 280
#define PLUS 281
#define RBRACE 282
#define RPAR 283
#define RSQ 284
#define SEMICOLON 285
#define ARROW 286
#define LSHIFT 287
#define RSHIFT 288
#define XOR 289
#define BOOL 290
#define CLASS 291
#define DOTLENGTH 292
#define DOUBLE 293
#define ELSE 294
#define IF 295
#define INT 296
#define PRINT 297
#define PARSEINT 298
#define PUBLIC 299
#define RETURN 300
#define STATIC 301
#define STRING 302
#define VOID 303
#define WHILE 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "jucompiler.y" /* yacc.c:355  */

    struct identifier* id;
    struct ASTREE* ast;

#line 229 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 246 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    72,    74,    83,    92,   100,   107,   123,
     128,   131,   140,   141,   142,   145,   152,   159,   165,   173,
     187,   195,   196,   206,   212,   213,   221,   231,   246,   254,
     264,   276,   284,   288,   291,   294,   297,   300,   303,   307,
     311,   314,   315,   324,   330,   334,   339,   340,   349,   356,
     361,   366,   367,   370,   375,   380,   385,   390,   395,   400,
     405,   410,   415,   420,   425,   430,   435,   440,   445,   450,
     454,   458,   462,   465,   468,   471,   475,   478,   481,   484,
     487
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTLIT", "REALLIT", "STRLIT",
  "BOOLLIT", "AND", "ASSIGN", "STAR", "COMMA", "DIV", "EQ", "GE", "GT",
  "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR",
  "PLUS", "RBRACE", "RPAR", "RSQ", "SEMICOLON", "ARROW", "LSHIFT",
  "RSHIFT", "XOR", "BOOL", "CLASS", "DOTLENGTH", "DOUBLE", "ELSE", "IF",
  "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC", "STRING",
  "VOID", "WHILE", "RESERVED", "$accept", "Program", "Declarations",
  "MethodDecl", "FieldDecl", "CommaID", "Type", "MethodHeader",
  "FormalParams", "CommaTypeID", "MethodBody", "StatementOrVardecl",
  "VarDecl", "Statement", "Statements", "MethodInvocation", "CommaExpr",
  "Assignment", "ParseArgs", "Expr", "Expr2", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    18,    36,    13,   -66,   -66,    29,    -8,   -66,   -66,
      32,   -66,   -66,   -66,   110,   -66,   -66,   -66,    58,    71,
      59,    66,    69,   -66,   -66,   -15,    48,    28,    76,   -66,
      75,    93,    70,   -66,    80,    94,   -66,    74,     6,   -66,
     -66,   -66,    91,    92,    97,   184,   102,   109,   -66,   -66,
     100,   101,   103,   108,   -66,   -66,   -66,   -66,   -66,   225,
     175,   125,   225,   216,    63,     1,   -66,   -66,   -66,    64,
     249,   249,   249,   -66,   -66,   -66,   -66,   116,   264,   225,
     -66,   -66,   -66,   -66,   129,   136,   -66,   112,   -66,   -66,
     -66,   -66,   126,   128,   131,   132,   134,   -66,   138,   147,
      44,   -66,   -66,   -66,   -66,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   157,    61,   -66,    22,   -66,     3,   141,   139,   162,
     -66,   225,   -66,   -66,   316,   -66,   -66,   365,   117,   117,
     117,   117,    15,   -66,   365,   291,    15,   151,   151,   341,
     141,   -66,   159,   225,   -66,   155,   -66,   -66,   135,   -66,
     -66,   -66,   141,   167,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     6,
       0,     4,     5,     9,     0,    12,    14,    13,     0,     0,
       0,     0,    10,    24,     7,     0,     0,     0,     0,    18,
       0,     0,     0,    16,     0,     0,     8,     0,     0,    41,
      23,    37,     0,     0,     0,     0,     0,     0,    26,    25,
       0,     0,     0,     0,    21,    17,    15,    11,    40,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,     0,
       0,     0,     0,    33,    73,    52,    74,     0,    51,     0,
      10,    34,    35,    36,     0,    19,    48,     0,    44,    46,
      28,    42,     0,     0,     0,     0,     0,    75,     0,     0,
      76,    69,    70,    71,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,    45,     0,     0,     0,     0,
      50,     0,    80,    72,    58,    55,    56,    63,    64,    65,
      66,    67,    54,    57,    68,    59,    53,    61,    62,    60,
       0,    27,     0,     0,    43,    29,    39,    38,     0,    31,
      22,    47,     0,     0,    30,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   -66,   118,   -11,   -66,   171,   -66,
     -66,   -66,   -66,   -57,   -66,   -28,   -66,   -27,   -26,   -51,
     -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    11,    12,    27,    31,    20,    32,    85,
      24,    28,    48,    49,    61,    74,   126,    75,    76,    77,
      78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,    51,    52,    19,    91,   101,   102,   103,    86,    89,
      59,    92,    94,    29,   153,    59,     1,    47,    99,    60,
      15,     3,    13,    16,    60,   106,    17,   107,   121,     5,
       7,   154,    30,    50,    51,    52,     4,   114,    97,    35,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     8,    15,    36,     9,
      16,    21,    60,    17,    95,    98,    96,    65,    66,    67,
     155,    68,    35,    10,    22,    23,    33,    37,    14,    38,
     158,    97,    69,    15,    25,    70,    16,    26,    71,    17,
      72,   151,    39,   159,    53,    30,    54,    57,    55,    50,
      51,    52,   161,    40,    58,   164,    41,    44,    56,    62,
      63,    15,    80,   152,    16,    64,    42,    17,    43,    44,
      79,    45,    50,    51,    52,    46,    37,   106,    38,   107,
      81,    82,   123,    83,    50,    51,    52,    84,   113,   114,
     125,    39,    37,   117,    38,    15,   104,   124,    16,   118,
     119,    17,    90,   131,   127,    41,   128,    39,    18,   129,
     130,   106,   160,   107,   163,    42,   132,    43,    44,   156,
      45,    41,   113,   114,    46,   133,    87,   117,    65,    66,
      67,    42,    68,    43,    44,   150,    45,    65,    66,    67,
      46,    68,   157,    69,   162,   165,    70,    34,   122,    71,
       0,    72,    69,    88,     0,    70,     0,     0,    71,     0,
      72,     0,     0,     0,    73,     0,     0,     0,    44,    65,
      66,    67,    93,    68,     0,     0,     0,    44,    65,    66,
      67,     0,    68,     0,    69,     0,     0,    70,     0,     0,
      71,     0,    72,    69,     0,     0,    70,     0,     0,    71,
       0,    72,   100,    66,    67,     0,    68,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,    69,    44,     0,
      70,     0,   105,    71,   106,    72,   107,   108,   109,   110,
       0,   111,     0,     0,   112,   113,   114,   115,     0,   116,
     117,     0,    44,     0,     0,     0,   118,   119,   120,   105,
       0,   106,     0,   107,   108,   109,   110,     0,   111,     0,
       0,   112,   113,   114,   115,     0,     0,   117,     0,     0,
       0,     0,     0,   118,   119,   120,   106,     0,   107,   108,
     109,   110,     0,   111,     0,     0,   112,   113,   114,   115,
       0,     0,   117,     0,     0,     0,     0,     0,   118,   119,
     120,   106,     0,   107,   108,   109,   110,     0,   111,     0,
       0,   112,   113,   114,   115,     0,     0,   117,     0,     0,
       0,     0,     0,   118,   119,   106,     0,   107,     0,   109,
     110,     0,   111,     0,     0,   112,   113,   114,     0,     0,
       0,   117,     0,     0,     0,     0,     0,   118,   119
};

static const yytype_int16 yycheck[] =
{
      28,    28,    28,    14,    61,    70,    71,    72,    59,    60,
       9,    62,    63,    28,    11,     9,    36,    28,    69,    18,
      35,     3,    30,    38,    18,    10,    41,    12,    79,    16,
       1,    28,    47,    61,    61,    61,     0,    22,    37,    11,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    27,    35,    30,    30,
      38,     3,    18,    41,     1,     1,     3,     3,     4,     5,
     127,     7,    11,    44,     3,    16,    28,     1,    46,     3,
     131,    37,    18,    35,    18,    21,    38,    18,    24,    41,
      26,    30,    16,   150,    19,    47,     3,     3,    28,   127,
     127,   127,   153,    27,    30,   162,    30,    43,    28,    18,
      18,    35,     3,   124,    38,    18,    40,    41,    42,    43,
      18,    45,   150,   150,   150,    49,     1,    10,     3,    12,
      30,    30,     3,    30,   162,   162,   162,    29,    21,    22,
      28,    16,     1,    26,     3,    35,    30,    11,    38,    32,
      33,    41,    27,    19,    28,    30,    28,    16,    48,    28,
      28,    10,     3,    12,    29,    40,    28,    42,    43,    30,
      45,    30,    21,    22,    49,    28,     1,    26,     3,     4,
       5,    40,     7,    42,    43,    28,    45,     3,     4,     5,
      49,     7,    30,    18,    39,    28,    21,    26,    80,    24,
      -1,    26,    18,    28,    -1,    21,    -1,    -1,    24,    -1,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    43,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    43,     3,     4,
       5,    -1,     7,    -1,    18,    -1,    -1,    21,    -1,    -1,
      24,    -1,    26,    18,    -1,    -1,    21,    -1,    -1,    24,
      -1,    26,     3,     4,     5,    -1,     7,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    43,    -1,
      21,    -1,     8,    24,    10,    26,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,    25,
      26,    -1,    43,    -1,    -1,    -1,    32,    33,    34,     8,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    10,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    10,    -1,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    10,    -1,    12,    -1,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    52,     3,     0,    16,    53,     1,    27,    30,
      44,    54,    55,    30,    46,    35,    38,    41,    48,    57,
      58,     3,     3,    16,    61,    18,    18,    56,    62,    28,
      47,    57,    59,    28,    59,    11,    30,     1,     3,    16,
      27,    30,    40,    42,    43,    45,    49,    57,    63,    64,
      66,    68,    69,    19,     3,    28,    28,     3,    30,     9,
      18,    65,    18,    18,    18,     3,     4,     5,     7,    18,
      21,    24,    26,    30,    66,    68,    69,    70,    71,    18,
       3,    30,    30,    30,    29,    60,    70,     1,    28,    70,
      27,    64,    70,     6,    70,     1,     3,    37,     1,    70,
       3,    71,    71,    71,    30,     8,    10,    12,    13,    14,
      15,    17,    20,    21,    22,    23,    25,    26,    32,    33,
      34,    70,    56,     3,    11,    28,    67,    28,    28,    28,
      28,    19,    28,    28,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      28,    30,    57,    11,    28,    64,    30,    30,    70,    64,
       3,    70,    39,    29,    64,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     2,
       0,     3,     1,     1,     1,     5,     4,     5,     4,     3,
       4,     0,     4,     3,     0,     2,     2,     4,     3,     5,
       7,     5,     3,     2,     2,     2,     2,     1,     5,     5,
       2,     0,     2,     5,     3,     4,     0,     3,     3,     7,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     2,     1,     1,     1,     1,
       3
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
        case 2:
#line 65 "jucompiler.y" /* yacc.c:1646  */
    {   
                                                    root = create_node("Program", "", linha, coluna);
                                                    add_son(root, create_identifier_node("Id", (yyvsp[-3].id)));
                                                    add_brother(root->filho, (yyvsp[-1].ast));
                                                    (yyval.ast) = root;
                                                }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "jucompiler.y" /* yacc.c:1646  */
    {   (yyval.ast) = NULL;  }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 74 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    
                                                    if ((yyvsp[-1].ast) != NULL){
                                                        (yyval.ast) = (yyvsp[-1].ast); 
                                                        add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                                        } 
                                                    else {(yyval.ast) = (yyvsp[0].ast);}                                               
                                                }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    
                                                    if ((yyvsp[-1].ast) != NULL){
                                                        (yyval.ast) = (yyvsp[-1].ast); 
                                                        add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                                        } 
                                                    else {(yyval.ast) = (yyvsp[0].ast);}                                               
                                                }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    if ((yyvsp[-1].ast) != NULL)
                                                        (yyval.ast) = (yyvsp[-1].ast);
                                                    else    
                                                        (yyval.ast)=NULL;                                               
                                                }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("MethodDecl", "", linha, coluna);                                                       
                                                        add_son((yyval.ast), (yyvsp[-1].ast));
                                                        add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                                    }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 107 "jucompiler.y" /* yacc.c:1646  */
    {   
                                                            (yyval.ast) = create_node("FieldDecl", "", linha, coluna);
                                                            add_son((yyval.ast), (yyvsp[-3].ast));
                                                            //printf("----> ID(%s) col%d\n", $4->id, $4->col);
                                                            add_brother((yyvsp[-3].ast), create_identifier_node("Id", (yyvsp[-2].id)));
                                                            while((yyvsp[-1].ast)!=NULL){
                                                                aux = create_node("FieldDecl", "", linha, coluna);
                                                                aux2 = create_node((yyvsp[-3].ast)->nome, "", linha, coluna);
                                                                add_brother(aux2, create_node((yyvsp[-1].ast)->nome, (yyvsp[-1].ast)->valor, linha, coluna));
                                                                add_son(aux, aux2);
                                                                add_brother((yyval.ast), aux);
                                                                (yyvsp[-1].ast)=(yyvsp[-1].ast)->irmao;
                                                            }
                                                            
                                                            add_brother((yyval.ast)->filho->irmao, (yyvsp[-1].ast));
                                                        }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = NULL;
                                                        }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "jucompiler.y" /* yacc.c:1646  */
    {
                                        (yyval.ast) =  NULL;
                                    }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "jucompiler.y" /* yacc.c:1646  */
    {                                                   
                                        if ((yyvsp[-2].ast) != NULL){
                                            (yyval.ast) = (yyvsp[-2].ast); 
                                            add_brother((yyvsp[-2].ast), create_identifier_node("Id", (yyvsp[0].id)));
                                        } 
                                        else {(yyval.ast) = create_identifier_node("Id", (yyvsp[0].id));}                                               
                                    }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = create_node("Bool", "", linha, coluna);}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 141 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = create_node("Int", "", linha, coluna);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 142 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = create_node("Double", "", linha, coluna);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "jucompiler.y" /* yacc.c:1646  */
    { 
                                                        (yyval.ast) = create_node("MethodHeader","", linha, coluna);
                                                        add_son((yyval.ast), (yyvsp[-4].ast));
                                                        add_brother((yyvsp[-4].ast), create_identifier_node("Id", (yyvsp[-3].id)));
                                                        add_brother((yyvsp[-4].ast)->irmao, (yyvsp[-1].ast));
                                                        
                                                    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 152 "jucompiler.y" /* yacc.c:1646  */
    { 
                                                        (yyval.ast) = create_node("MethodHeader","", linha, coluna);
                                                        add_son((yyval.ast), (yyvsp[-3].ast));
                                                        add_brother((yyvsp[-3].ast), create_identifier_node("Id", (yyvsp[-2].id)));
                                                        add_brother((yyvsp[-3].ast), create_node("MethodParams", "", linha, coluna));
                                                        
                                                    }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 159 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("MethodHeader","", linha, coluna);
                                                        add_son((yyval.ast), create_node("Void","", linha, coluna));
                                                        add_brother((yyval.ast)->filho, create_identifier_node("Id", (yyvsp[-3].id)));
                                                        add_brother((yyval.ast)->filho, (yyvsp[-1].ast));                                                    
                                                    }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("MethodHeader","", linha, coluna);
                                                        add_son((yyval.ast), create_node("Void","", linha, coluna));
                                                        add_brother((yyval.ast)->filho, create_identifier_node("Id", (yyvsp[-2].id)));
                                                        add_brother((yyval.ast)->filho, create_node("MethodParams", "", linha, coluna));                                                
                                                    }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.ast) = create_node("MethodParams", "", linha, coluna);
                                    add_son((yyval.ast), create_node("ParamDecl", "", linha, coluna));
                                    add_son((yyval.ast)->filho, (yyvsp[-2].ast));
                                    add_brother((yyvsp[-2].ast), create_identifier_node("Id", (yyvsp[-1].id)));
                                    while((yyvsp[0].ast)!=NULL){
                                            aux = create_node("ParamDecl", "", linha, coluna);
                                            add_son(aux, create_node((yyvsp[0].ast)->nome, "", linha, coluna));
                                            add_brother(aux->filho, create_node((yyvsp[0].ast)->irmao->nome, (yyvsp[0].ast)->irmao->valor, linha, coluna));
                                            add_brother((yyval.ast)->filho, aux);
                                            (yyvsp[0].ast) = (yyvsp[0].ast)->irmao->irmao;
                                            }

                                    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 187 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.ast) = create_node("MethodParams", "", linha, coluna);
                                    add_son((yyval.ast), create_node("ParamDecl", "", linha, coluna));
                                    add_son((yyval.ast)->filho, create_node("StringArray", "", linha, coluna));
                                    add_brother((yyval.ast)->filho->filho, create_identifier_node("Id", (yyvsp[0].id)));
                                    }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 195 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "jucompiler.y" /* yacc.c:1646  */
    {                                                   
                                        if ((yyvsp[-3].ast) != NULL){
                                            (yyval.ast) = (yyvsp[-3].ast); 
                                            add_brother((yyvsp[-3].ast), (yyvsp[-1].ast));
                                            add_brother((yyvsp[-1].ast), create_identifier_node("Id", (yyvsp[0].id)));
                                        } 
                                        else {(yyval.ast) = (yyvsp[-1].ast); add_brother((yyvsp[-1].ast), create_identifier_node("Id", (yyvsp[0].id)));}                                               
                                    }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    (yyval.ast) = create_node("MethodBody", "", linha, coluna);
                                                    add_son((yyval.ast), (yyvsp[-1].ast));
                                                }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 212 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 213 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    
                                             if ((yyvsp[-1].ast) != NULL){
                                                (yyval.ast) = (yyvsp[-1].ast); 
                                                add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                            } 
                                            else {(yyval.ast) = (yyvsp[0].ast);}                                               
                                        }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 221 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    
                                            if ((yyvsp[-1].ast) != NULL){
                                                (yyval.ast) = (yyvsp[-1].ast); 
                                                add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                            } 
                                            else {(yyval.ast) = (yyvsp[0].ast);}                                               
                                        }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 231 "jucompiler.y" /* yacc.c:1646  */
    { 
                                            (yyval.ast) = create_node("VarDecl", "", linha, coluna);
                                            add_son((yyval.ast), (yyvsp[-3].ast));
                                            add_brother((yyvsp[-3].ast), create_identifier_node("Id", (yyvsp[-2].id)));
                                            
                                            while((yyvsp[-1].ast)!=NULL){
                                                aux = create_node("VarDecl", "", linha, coluna);
                                                add_son(aux, create_node((yyvsp[-3].ast)->nome, "", linha, coluna));
                                                add_brother(aux->filho, create_node((yyvsp[-1].ast)->nome, (yyvsp[-1].ast)->valor, linha, coluna));
                                                add_brother((yyval.ast), aux);
                                                (yyvsp[-1].ast) = (yyvsp[-1].ast)->irmao;
                                            }
                                        }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 246 "jucompiler.y" /* yacc.c:1646  */
    {   
                                                        if(count_brothers((yyvsp[-1].ast))>1){
                                                            (yyval.ast) = create_node("Block", "", linha, coluna);
                                                            add_son((yyval.ast), (yyvsp[-1].ast));  
                                                        }
                                                        else
                                                           (yyval.ast) = (yyvsp[-1].ast);
                                                    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 254 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("If", "", linha, coluna); 
                                                        add_son((yyval.ast), (yyvsp[-2].ast)); 
                                                        add_brother((yyvsp[-2].ast), (yyvsp[0].ast));
                                                        if((yyvsp[0].ast)==NULL)
                                                            add_brother((yyvsp[-2].ast), create_node("Block", "", linha, coluna));
                                                        if(count_brothers((yyvsp[0].ast))<=1){
                                                            add_brother((yyvsp[-2].ast), create_node("Block", "", linha, coluna));
                                                        }
                                                    }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("If", "", linha, coluna); 
                                                        add_son((yyval.ast), (yyvsp[-4].ast)); 
                                                        add_brother((yyvsp[-4].ast), (yyvsp[-2].ast));
                                                        if(count_brothers((yyvsp[-2].ast))==0){
                                                            add_brother((yyvsp[-4].ast), create_node("Block", "", linha, coluna));
                                                        }
                                                        add_brother((yyvsp[-4].ast), (yyvsp[0].ast));
                                                        if(count_brothers((yyvsp[0].ast))==0){
                                                            add_brother((yyvsp[-4].ast), create_node("Block", "", linha, coluna));
                                                        }
                                                    }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 276 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("While", "", linha, coluna);
                                                        add_son((yyval.ast), (yyvsp[-2].ast));
                                                        add_brother((yyvsp[-2].ast), (yyvsp[0].ast));
                                                        if(count_brothers((yyvsp[0].ast))==0){
                                                            add_brother((yyvsp[-2].ast), create_node("Block", "", linha, coluna));
                                                        }
                                                    }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 284 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("Return", "", linha, coluna);
                                                        add_son((yyval.ast), (yyvsp[-1].ast));
                                                    }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 288 "jucompiler.y" /* yacc.c:1646  */
    {   
                                                        (yyval.ast) = create_node("Return", "", linha, coluna);
                                                    }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = (yyvsp[-1].ast);
                                                    }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 294 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = (yyvsp[-1].ast);
                                                    }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 297 "jucompiler.y" /* yacc.c:1646  */
    {   
                                                        (yyval.ast) = (yyvsp[-1].ast);
                                                    }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 300 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = NULL;
                                                    }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 303 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("Print", "", linha, coluna);
                                                        add_son((yyval.ast), (yyvsp[-2].ast));
                                                    }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 307 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast) = create_node("Print", "", linha, coluna);
                                                        add_son((yyval.ast), create_identifier_node("StrLit", (yyvsp[-2].id)));                                                     
                                                    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "jucompiler.y" /* yacc.c:1646  */
    {   (yyval.ast) = NULL;  }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 314 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 315 "jucompiler.y" /* yacc.c:1646  */
    {                    
                                        if ((yyvsp[-1].ast) != NULL){
                                            (yyval.ast) = (yyvsp[-1].ast); 
                                            add_brother((yyvsp[-1].ast), (yyvsp[0].ast));
                                    } 
                                        else {(yyval.ast) = (yyvsp[0].ast);}                                               
                                    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 324 "jucompiler.y" /* yacc.c:1646  */
    {
                                            (yyval.ast) = create_node("Call", "", linha, coluna);
                                            add_son((yyval.ast), create_identifier_node("Id", (yyvsp[-4].id)));
                                            add_brother((yyval.ast)->filho, (yyvsp[-2].ast));
                                            add_brother((yyval.ast)->filho->irmao, (yyvsp[-1].ast));
                                        }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 330 "jucompiler.y" /* yacc.c:1646  */
    {
                                            (yyval.ast) = create_node("Call", "", linha, coluna);
                                            add_son((yyval.ast), create_identifier_node("Id", (yyvsp[-2].id)));
                                        }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 334 "jucompiler.y" /* yacc.c:1646  */
    {
                                        (yyval.ast) = NULL;
                                    }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 339 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 340 "jucompiler.y" /* yacc.c:1646  */
    {                                              
                                if ((yyvsp[-2].ast) != NULL){
                                    (yyval.ast) = (yyvsp[-2].ast); 
                                    add_brother((yyvsp[-2].ast), (yyvsp[0].ast));
                                } 
                                else {(yyval.ast) = (yyvsp[0].ast);}                                               
                            }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 349 "jucompiler.y" /* yacc.c:1646  */
    {
                                (yyval.ast) = create_node("Assign", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                add_son((yyval.ast), create_identifier_node("Id", (yyvsp[-2].id)));
                                add_brother((yyval.ast)->filho, (yyvsp[0].ast));                               
                                }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 356 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    (yyval.ast) = create_node("ParseArgs", "", linha, coluna);
                                                    add_son((yyval.ast), create_identifier_node("Id", (yyvsp[-4].id)));
                                                    add_brother((yyval.ast)->filho, (yyvsp[-2].ast));    
                                                }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 361 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    (yyval.ast) = NULL;
                                                }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 366 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 367 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 370 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Add", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 375 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Sub", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Mul", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 385 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Div", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 390 "jucompiler.y" /* yacc.c:1646  */
    {
                                                             (yyval.ast) = create_node("Mod", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("And", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 400 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Or", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 405 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Xor", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 410 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Lshift", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 415 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Rshift", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 420 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Eq", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 425 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Ge", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 430 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Gt", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 435 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Le", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 440 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Lt", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 445 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Ne", "", (yyvsp[-1].id)->line, (yyvsp[-1].id)->col);
                                                            add_son((yyval.ast),(yyvsp[-2].ast));
						                                    add_brother((yyvsp[-2].ast),(yyvsp[0].ast));
                                                        }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 450 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Minus","", linha, coluna);
							                                add_son((yyval.ast),(yyvsp[0].ast));
                                                        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 454 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Not","", linha, coluna);
							                                add_son((yyval.ast),(yyvsp[0].ast));
                                                        }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 458 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Plus","", linha, coluna);
							                                add_son((yyval.ast),(yyvsp[0].ast));
                                                        }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = (yyvsp[-1].ast);
                                                        }
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 465 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = (yyvsp[0].ast);
                                                        }
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 468 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = (yyvsp[0].ast);
                                                        }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 471 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_node("Length","", linha, coluna);
                                                            add_son((yyval.ast),create_identifier_node("Id",(yyvsp[-1].id)));
                                                        }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 475 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_identifier_node("Id",(yyvsp[0].id));
                                                        }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 478 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_identifier_node("DecLit",(yyvsp[0].id));
                                                        }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 481 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_identifier_node("RealLit",(yyvsp[0].id));
                                                        }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 484 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = create_identifier_node("BoolLit",(yyvsp[0].id));
                                                        }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 487 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            (yyval.ast) = NULL;
                                                        }
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2262 "y.tab.c" /* yacc.c:1646  */
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
#line 492 "jucompiler.y" /* yacc.c:1906  */



int main(int argc,char* argv[]){
	str = malloc(256*sizeof(char));	
	if(argv[1] != NULL){
		if(strcmp(argv[1], "-l") == 0){
			//analise lexical
            flag = 1;
            yylex();
		}
		else if(strcmp(argv[1], "-e1") == 0){
			//erros lexicais
            yylex(); 
		}
		else if(strcmp(argv[1], "-t") == 0){
			//arvore de sintaxe
			flag = 2;
            yyparse();
            //imprimir depois a arvore
			if(containsErrors == 0){
                print_tree(root, 0);
            }
		}
		else if(strcmp(argv[1], "-e2") == 0){
			//erros sintaticos e lexicais
			flag = 2;
			yyparse();
		}else if(strcmp(argv[1], "-s") == 0){
			//erros sintaticos e lexicais
			flag = 2;
			yyparse();
            if(!containsErrors){
                check_tree(root);
                show_table(global_table);
                print_tree_anoted(root, 0);          
            }
		}
	}
	else{
		//erros sintaticos e lexicais
		flag = 2;
		yyparse();
	}

	free(str);
	return 0;
}
