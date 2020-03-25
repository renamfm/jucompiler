%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "y.tab.h"

int yylex (void);

/*POR MUDAR
is_program* myprogram;
is_vardec_list* lista_vardec;
is_vardec* vardec;
is_statement_list* lista_statement;
is_statement* statement;
*/

%}

%token ID INTLIT REALLIT STRLIT BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE  
%token GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ 
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF 
%token INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED

/*POR MUDAR
%token INTEGER CHARACTER LET IN END WRITE
%token<id>IDENTIFIER
%type<ip>program
%type<ivl>vardeclist
%type<iv>vardec
%type<isl>statementlist
%type<is>statement

%union{
    char *id;
    is_program* ip;
    is_vardec_list* ivl;
    is_vardec* iv;
    is_statement_list* isl;
    is_statement* is;
}
*/
%%

Program: CLASS ID LBRACE Declarations RBRACE    {;}

Declarations: /*empty*/                       {;}      
    | Declarations MethodDecl                 {;}
    | Declarations FieldDecl                  {;}
    | Declarations SEMICOLON                  {;}
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {;}
    ;

FieldDecl: PUBLIC STATIC Type ID CommaOrID SEMICOLON  {;}
    ;

CommaOrID: /*empty*/      {;} 
    | CommaOrID COMMA     {;}
    | CommaOrID ID        {;}
    ;

Type: BOOL    {;}
    | INT     {;}
    | DOUBLE  {;}
    ;

MethodHeader: Type ID LPAR FormalParams RPAR      {;}
    | VOID ID LPAR FormalParams RPAR              {;}
    | Type ID LPAR RPAR                           {;}
    | VOID ID LPAR RPAR                           {;}
    ;

FormalParams: Type ID CommaOrTypeOrID   {;}
    | STRING LSQ RSQ ID                 {;}
    ;

CommaOrTypeOrID: /*empty*/      {;}
    | CommaOrTypeOrID COMMA     {;}
    | CommaOrTypeOrID Type      {;}
    | CommaOrTypeOrID ID        {;}    
    ;

MethodBody: LBRACE StatementOrVardecl RBRACE    {;}
    ;

StatementOrVardecl: /*empty*/         {;}
    | StatementOrVardecl Statement    {;}
    | StatementOrVardecl VarDecl      {;}
    ;

VarDecl: Type ID CommaOrID SEMICOLON    {;}
    ;

Statement: LBRACE Statements RBRACE                 {;}
    | IF LPAR Expr RPAR Statement ELSE Statement    {;}
    | IF LPAR Expr RPAR Statement                   {;}
    | WHILE LPAR Expr RPAR Statement                {;}
    | RETURN Expr SEMICOLON                         {;}
    | RETURN SEMICOLON                              {;}
    | MethodInvocation SEMICOLON                    {;}
    | Assignment SEMICOLON                          {;}
    | ParseArgs SEMICOLON                           {;}
    | SEMICOLON                                     {;}
    | PRINT LPAR Expr RPAR SEMICOLON                {;}
    | PRINT LPAR STRLIT RPAR SEMICOLON              {;}
    ;

Statements: /*empty*/ 
    | Statements Statement    {;}
    ;

MethodInvocation: ID LPAR RPAR          {;}
    | ID LPAR Expr CommaOrExpr RPAR     {;}
    ;

CommaOrExpr: /*empty*/      {;}
    | CommaOrExpr COMMA     {;}
    | CommaOrExpr Expr      {;}
    ;

Assignment: ID ASSIGN Expr  {;}
    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ LPAR   {;}
    ;

Expr: Expr PLUS Expr     {;}
    | Expr MINUS Expr    {;}
    | Expr STAR Expr     {;}
    | Expr DIV Expr      {;}
    | Expr MOD Expr      {;}
    | Expr AND Expr      {;}
    | Expr OR Expr       {;}
    | Expr XOR Expr      {;}
    | Expr LSHIFT Expr   {;}
    | Expr RSHIFT Expr   {;}
    | Expr EQ Expr       {;}
    | Expr GE Expr       {;}
    | Expr GT Expr       {;}
    | Expr LE Expr       {;}
    | Expr LT Expr       {;}
    | Expr NE Expr       {;}
    | MINUS Expr         {;}
    | NOT Expr           {;}
    | PLUS Expr          {;}
    | LPAR Expr RPAR     {;}
    | MethodInvocation   {;}
    | Assignment         {;}
    | ParseArgs          {;}
    | ID                 {;}
    | ID DOTLENGTH       {;}
    | INTLIT             {;}
    | REALLIT            {;}
    | BOOLLIT            {;}
    ;

%%

int main(int argc,char* argv[]){	
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
		}
		else if(strcmp(argv[1], "-e2") == 0){
			//erros sintaticos e lexicais
		}
	}

	//erros sintaticos e lexicais

	free(str);
	return 0;
}
