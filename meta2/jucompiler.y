%{
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "functions.h"
//#include "y.tab.h"

int yylex (void);
void yyerror (const char *s);

/*
Program *programa:
Declarations *declaracao;
MethodDeclaration *declaracaoMetodo;
FieldDeclaration *declaracaoCampo;
CommaId *virgulaId;                     
Type *tipo;
MethodHeader *cabecalhoMetodo;
FormalParams *parametrosFormais;
CommaTypeId *virgulaTipoId;
MethodBody *corpoMetodo;
StatemOrVardec *VardecOuStatement;
Statements *singleStatement;
MethodInvocation *invacacaoMetodo;
CommaExpr *virgulaExpr;
Assignment *atribuicao;
Expr *expressao;
*/
%}

%token ID INTLIT REALLIT STRLIT BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE  
%token GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ 
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF 
%token INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED



%type <p>Program
%type <dec>Declarations
%type <mdec>MethodDecl
%type <cmid>CommaID
%type <tp>Type
%type <mh>MethodHeader
%type <fpm>FormalParams
%type <cmtid>CommaTypeID
%type <mbd>MethodBody
%type <stvd>StatementOrVardecl
%type <st>Statements
%type <miv>MethodInvocation
%type <tp>CommaExpr
%type <asgn>Assignment
%type <expr>Expr
%type <id>ID


%union{
	/*Program *p:
	Declarations *dec;
	MethodDeclaration *mdec;
	FieldDeclaration *fdec;
	CommaId *cmid;
	Type *tp;
	MethodHeader *mh;
	FormalParams *fpm;
	CommaTypeId cmtid;
	MethodBody *mbd;
	StatemOrVardec *stvd;
	Statements *st;
	MethodInvocation *miv;
	CommaExpr *cmexpr;
	Assignment *asgn;
	Expr *expr;*/
    char *id;
}

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ GE LE LT GT NE
%left LSHIFT RSHIFT
%left STAR DIV MOD
%left NOT MINUS PLUS
%left LPAR RPAR LSQ RSQ

%nonassoc ELSE


%%

Program: CLASS ID LBRACE Declarations RBRACE    {printf("Program\n"); printf("Id(%s)\n", $2);}

Declarations: /*empty*/                       {;}     
    | Declarations MethodDecl                 {printf("Declarations\n");}
    | Declarations FieldDecl                  {printf("Declarations\n");}
    | Declarations SEMICOLON                  {printf("Declarations\n");}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {printf("MethodDecl\n");}
    ;

FieldDecl: PUBLIC STATIC Type ID CommaID SEMICOLON  {printf("FieldDecl\n");}
    ;

CommaID: /*empty*/      {;} 
    | CommaID COMMA ID      {printf("Comma\n Id(%s)\n", $3);}
    ;

Type: BOOL    {printf("BOOL\n");}
    | INT     {printf("INT\n");}
    | DOUBLE  {printf("DOUBLE\n");}
    ;

MethodHeader: Type ID LPAR FormalParams RPAR      {printf("MethodHeader\n");}
    | VOID ID LPAR FormalParams RPAR              {printf("MethodHeader\n");}
    | Type ID LPAR RPAR                           {printf("MethodHeader\n");}
    | VOID ID LPAR RPAR                           {printf("MethodHeader\n");}
    ;

FormalParams: Type ID CommaTypeID   {printf("FormalParams\n");}
    | STRING LSQ RSQ ID                 {printf("FormalParams\n");}
    ;

CommaTypeID: /*empty*/      {;}
    | CommaTypeID COMMA Type ID    {printf("COMMA\n Type\n Id(%s)\n", $4);}
    ;

MethodBody: LBRACE StatementOrVardecl RBRACE    {printf("MethodBody\n");}
    ;

StatementOrVardecl: /*empty*/         {;}
    | StatementOrVardecl Statement    {printf("Statement\n");}
    | StatementOrVardecl VarDecl      {printf("VarDecl\n");}
    ;

VarDecl: Type ID CommaID SEMICOLON    {printf("VarDecl\n");}
    ;

Statement: LBRACE Statements RBRACE                 {printf("Statement\n");}
    | IF LPAR Expr RPAR Statement                   {printf("Statement\n");}
    | IF LPAR Expr RPAR Statement ELSE Statement    {printf("Statement\n");}
    | WHILE LPAR Expr RPAR Statement                {printf("Statement\n");}
    | RETURN Expr SEMICOLON                         {printf("Statement\n");}
    | RETURN SEMICOLON                              {printf("Statement\n");}
    | MethodInvocation SEMICOLON                    {printf("Statement\n");}
    | Assignment SEMICOLON                          {printf("Statement\n");}
    | ParseArgs SEMICOLON                           {printf("Statement\n");}
    | SEMICOLON                                     {printf("Statement\n");}
    | PRINT LPAR Expr RPAR SEMICOLON                {printf("Statement\n");}
    | PRINT LPAR STRLIT RPAR SEMICOLON              {printf("Statement\n");}
    ;

Statements: /*empty*/          {;}
    | Statements Statement    {printf("Statement\n");}
    ;

MethodInvocation: ID LPAR RPAR          {printf("MethodInvocation\n");}
    | ID LPAR Expr CommaExpr RPAR     {printf("MethodInvocation\n");}
    ;

CommaExpr: /*empty*/      {;}
    | CommaExpr COMMA Expr    {printf("COMMA\n Exp\n");}
    ;

Assignment: ID ASSIGN Expr  {printf("Assignment\n");}
    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR   {printf("ParseArgs\n");}
    ;

Expr: Expr PLUS Expr     {printf("Expr\n");}
    | Expr MINUS Expr    {printf("Expr\n");}
    | Expr STAR Expr     {printf("Expr\n");}
    | Expr DIV Expr      {printf("Expr\n");}
    | Expr MOD Expr      {printf("Expr\n");}
    | Expr AND Expr      {printf("Expr\n");}
    | Expr OR Expr       {printf("Expr\n");}
    | Expr XOR Expr      {printf("Expr\n");}
    | Expr LSHIFT Expr   {printf("Expr\n");}
    | Expr RSHIFT Expr   {printf("Expr\n");}
    | Expr EQ Expr       {printf("Expr\n");}
    | Expr GE Expr       {printf("Expr\n");}
    | Expr GT Expr       {printf("Expr\n");}
    | Expr LE Expr       {printf("Expr\n");}
    | Expr LT Expr       {printf("Expr\n");}
    | Expr NE Expr       {printf("Expr\n");}
    | MINUS Expr         {printf("Expr\n");}
    | NOT Expr           {printf("Expr\n");}
    | PLUS Expr          {printf("Expr\n");}
    | LPAR Expr RPAR     {printf("Expr\n");}
    | MethodInvocation   {printf("Expr\n");}
    | Assignment         {printf("Expr\n");}
    | ParseArgs          {printf("Expr\n");}
    | ID                 {printf("Expr\n");}
    | ID DOTLENGTH       {printf("Expr\n");}
    | INTLIT             {printf("Expr\n");}
    | REALLIT            {printf("Expr\n");}
    | BOOLLIT            {printf("Expr\n");}
    ;

%%


