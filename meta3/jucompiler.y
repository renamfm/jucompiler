%{
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
%}

%union{
    struct identifier* id;
    struct ASTREE* ast;
}

%token ID INTLIT REALLIT STRLIT BOOLLIT AND ASSIGN STAR COMMA DIV EQ GE  
%token GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ 
%token SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS DOTLENGTH DOUBLE ELSE IF 
%token INT PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE RESERVED


%type <ast>Program FieldDecl SEMICOLON ParseArgs Expr2
%type <ast>Declarations
%type <ast>MethodDecl
%type <ast>CommaID
%type <ast>Type
%type <ast>MethodHeader
%type <ast>FormalParams
%type <ast>CommaTypeID
%type <ast>MethodBody
%type <ast>StatementOrVardecl VarDecl
%type <ast>Statements Statement
%type <ast>MethodInvocation
%type <ast>CommaExpr
%type <ast>Assignment
%type <ast>Expr
%type <id>ID INTLIT REALLIT BOOLLIT STRLIT 
%type <id> ASSIGN PLUS MINUS STAR DIV MOD
%type <id> AND OR XOR LSHIFT RSHIFT EQ GE GT LE LT NE
%type <id> RETURN VOID PARSEINT NOT


%right ELSE
%right ASSIGN
%left OR 
%left AND
%left XOR
%left EQ NE
%left GE GT LE LT 
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%nonassoc LPAR RPAR LSQ RSQ

%%

Program: CLASS ID LBRACE Declarations RBRACE    {   
                                                    root = create_node("Program", "", linha, coluna);
                                                    add_son(root, create_identifier_node("Id", $2));
                                                    add_brother(root->filho, $4);
                                                    $$ = root;
                                                }

Declarations: /*empty*/                         {   $$ = NULL;  }  
 
    | Declarations MethodDecl                   {
                                                    
                                                    if ($1 != NULL){
                                                        $$ = $1; 
                                                        add_brother($1, $2);
                                                        } 
                                                    else {$$ = $2;}                                               
                                                }

    | Declarations FieldDecl                    {
                                                    
                                                    if ($1 != NULL){
                                                        $$ = $1; 
                                                        add_brother($1, $2);
                                                        } 
                                                    else {$$ = $2;}                                               
                                                }

    | Declarations SEMICOLON                    {
                                                    if ($1 != NULL)
                                                        $$ = $1;
                                                    else    
                                                        $$=NULL;                                               
                                                }
    ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody   {
                                                        $$ = create_node("MethodDecl", "", linha, coluna);                                                       
                                                        add_son($$, $3);
                                                        add_brother($3, $4);
                                                    }
    ;

FieldDecl: PUBLIC STATIC Type ID CommaID SEMICOLON      {   
                                                            $$ = create_node("FieldDecl", "", linha, coluna);
                                                            add_son($$, $3);
                                                            //printf("----> ID(%s) col%d\n", $4->id, $4->col);
                                                            add_brother($3, create_identifier_node("Id", $4));
                                                            while($5!=NULL){
                                                                //printf("----> ID(%s) Valor(%s) line%d col%d\n", $5->nome, $5->valor, $5->linha, $5->coluna);
                                                                aux = create_node("FieldDecl", "", linha, coluna);
                                                                aux2 = create_node($3->nome, "", linha, coluna);
                                                                add_brother(aux2, create_node($5->nome, $5->valor, $5->linha, $5->coluna));
                                                                add_son(aux, aux2);
                                                                add_brother($$, aux);
                                                                $5=$5->irmao;
                                                            }
                                                            
                                                            add_brother($$->filho->irmao, $5);
                                                        }
    | error SEMICOLON                                   {
                                                            $$ = NULL;
                                                        }
    ;

CommaID: /*empty*/                  {   $$ = NULL;  } 
    | CommaID COMMA ID              {                                                   
                                        if ($1 != NULL){
                                            $$ = $1; 
                                            add_brother($1, create_identifier_node("Id", $3));
                                        } 
                                        else {$$ = create_identifier_node("Id", $3);}                                               
                                    }                            
    ;

Type: BOOL              {$$ = create_node("Bool", "", linha, coluna);}
    | INT               {$$ = create_node("Int", "", linha, coluna);}
    | DOUBLE            {$$ = create_node("Double", "", linha, coluna);}
    ;

MethodHeader: Type ID LPAR FormalParams RPAR        { 
                                                        $$ = create_node("MethodHeader","", linha, coluna);
                                                        add_son($$, $1);
                                                        add_brother($1, create_identifier_node("Id", $2));
                                                        add_brother($1->irmao, $4);
                                                        
                                                    }
    |  Type ID LPAR RPAR                            { 
                                                        $$ = create_node("MethodHeader","", linha, coluna);
                                                        add_son($$, $1);
                                                        add_brother($1, create_identifier_node("Id", $2));
                                                        add_brother($1, create_node("MethodParams", "", linha, coluna));
                                                        
                                                    }                                               
    | VOID ID LPAR FormalParams RPAR                {
                                                        $$ = create_node("MethodHeader","", linha, coluna);
                                                        add_son($$, create_node("Void","", $1->line, $1->col));
                                                        add_brother($$->filho, create_identifier_node("Id", $2));
                                                        add_brother($$->filho, $4);                                                    
                                                    }
    | VOID ID LPAR RPAR                             {
                                                        $$ = create_node("MethodHeader","", linha, coluna);
                                                        add_son($$, create_node("Void","", $1->line, $1->col));
                                                        add_brother($$->filho, create_identifier_node("Id", $2));
                                                        add_brother($$->filho, create_node("MethodParams", "", linha, coluna));                                                
                                                    }                                                
    ;

FormalParams:Type ID CommaTypeID    {
                                        $$ = create_node("MethodParams", "", linha, coluna);
                                        add_son($$, create_node("ParamDecl", "", linha, coluna));
                                        add_son($$->filho, $1);
                                        add_brother($1, create_identifier_node("Id", $2));
                                        while($3!=NULL){
                                            //printf("----> ID(%s) Valor(%s) line%d col%d\n", $3->irmao->nome, $3->irmao->valor, $3->irmao->linha, $3->irmaocoluna);
                                            aux = create_node("ParamDecl", "", linha, coluna);
                                            add_son(aux, create_node($3->nome, "", linha, coluna));
                                            add_brother(aux->filho, create_node($3->irmao->nome, $3->irmao->valor, $3->irmao->linha, $3->irmao->coluna));
                                            add_brother($$->filho, aux);
                                            $3 = $3->irmao->irmao;
                                        }
                                    }
    | STRING LSQ RSQ ID             {
                                    $$ = create_node("MethodParams", "", linha, coluna);
                                    add_son($$, create_node("ParamDecl", "", linha, coluna));
                                    add_son($$->filho, create_node("StringArray", "", linha, coluna));
                                    add_brother($$->filho->filho, create_identifier_node("Id", $4));
                                    }
    ;

CommaTypeID: /*empty*/              {$$ = NULL;}
    | CommaTypeID COMMA Type ID    {                                                   
                                        if ($1 != NULL){
                                            $$ = $1; 
                                            add_brother($1, $3);
                                            add_brother($3, create_identifier_node("Id", $4));
                                        } 
                                        else {$$ = $3; add_brother($3, create_identifier_node("Id", $4));}                                               
                                    }
    ;

MethodBody: LBRACE StatementOrVardecl RBRACE    {
                                                    $$ = create_node("MethodBody", "", linha, coluna);
                                                    add_son($$, $2);
                                                }
    ;

StatementOrVardecl: /*empty*/           {$$ = NULL;}
    | StatementOrVardecl Statement      {
                                                    
                                             if ($1 != NULL){
                                                $$ = $1; 
                                                add_brother($1, $2);
                                            } 
                                            else {$$ = $2;}                                               
                                        }
    | StatementOrVardecl VarDecl        {
                                                    
                                            if ($1 != NULL){
                                                $$ = $1; 
                                                add_brother($1, $2);
                                            } 
                                            else {$$ = $2;}                                               
                                        }
    ;

VarDecl: Type ID CommaID SEMICOLON      { 
                                            $$ = create_node("VarDecl", "", linha, coluna);
                                            add_son($$, $1);
                                            add_brother($1, create_identifier_node("Id", $2));
                                            
                                            while($3!=NULL){
                                                aux = create_node("VarDecl", "", linha, coluna);
                                                add_son(aux, create_node($1->nome, "", linha, coluna));
                                                add_brother(aux->filho, create_node($3->nome, $3->valor, $3->linha, $3->coluna));
                                                add_brother($$, aux);
                                                $3 = $3->irmao;
                                            }
                                        }
        ;

Statement: LBRACE Statements RBRACE                 {   
                                                        if(count_brothers($2)>1){
                                                            $$ = create_node("Block", "", linha, coluna);
                                                            add_son($$, $2);  
                                                        }
                                                        else
                                                           $$ = $2;
                                                    }
    | IF LPAR Expr RPAR Statement %prec ELSE        {
                                                        $$ = create_node("If", "", linha, coluna); 
                                                        add_son($$, $3); 
                                                        add_brother($3, $5);
                                                        if($5==NULL)
                                                            add_brother($3, create_node("Block", "", linha, coluna));
                                                        if(count_brothers($5)<=1){
                                                            add_brother($3, create_node("Block", "", linha, coluna));
                                                        }
                                                    }
    | IF LPAR Expr RPAR Statement ELSE Statement    {
                                                        $$ = create_node("If", "", linha, coluna); 
                                                        add_son($$, $3); 
                                                        add_brother($3, $5);
                                                        if(count_brothers($5)==0){
                                                            add_brother($3, create_node("Block", "", linha, coluna));
                                                        }
                                                        add_brother($3, $7);
                                                        if(count_brothers($7)==0){
                                                            add_brother($3, create_node("Block", "", linha, coluna));
                                                        }
                                                    }
    | WHILE LPAR Expr RPAR Statement                {
                                                        $$ = create_node("While", "", linha, coluna);
                                                        add_son($$, $3);
                                                        add_brother($3, $5);
                                                        if(count_brothers($5)==0){
                                                            add_brother($3, create_node("Block", "", linha, coluna));
                                                        }
                                                    }
    | RETURN Expr SEMICOLON                         {
                                                        $$ = create_node("Return", "", $1->line, $1->col);
                                                        add_son($$, $2);
                                                    }
    | RETURN SEMICOLON                              {   
                                                        $$ = create_node("Return", "", $1->line, $1->col);
                                                    }
    | MethodInvocation SEMICOLON                    {
                                                        $$ = $1;
                                                    }
    | Assignment SEMICOLON                          {
                                                        $$ = $1;
                                                    }
    | ParseArgs SEMICOLON                           {   
                                                        $$ = $1;
                                                    }
    | SEMICOLON                                     {
                                                        $$ = NULL;
                                                    }
    | PRINT LPAR Expr RPAR SEMICOLON                {
                                                        $$ = create_node("Print", "", linha, coluna);
                                                        add_son($$, $3);
                                                    }
    | PRINT LPAR STRLIT RPAR SEMICOLON              {
                                                        $$ = create_node("Print", "", linha, coluna);
                                                        add_son($$, create_identifier_node("StrLit", $3));                                                     
                                                    }
    | error SEMICOLON                               {   $$ = NULL;  }
    ;

Statements: /*empty*/               {$$ = NULL;}
    | Statements Statement          {                    
                                        if ($1 != NULL){
                                            $$ = $1; 
                                            add_brother($1, $2);
                                    } 
                                        else {$$ = $2;}                                               
                                    }
    ;

MethodInvocation: ID LPAR Expr CommaExpr RPAR       {
                                            $$ = create_node("Call", "", linha, coluna);
                                            add_son($$, create_identifier_node("Id", $1));
                                            add_brother($$->filho, $3);
                                            add_brother($$->filho->irmao, $4);
                                        }
    | ID LPAR RPAR          {
                                            $$ = create_node("Call", "", linha, coluna);
                                            add_son($$, create_identifier_node("Id", $1));
                                        }
    | ID LPAR error RPAR              {
                                        $$ = NULL;
                                    }
    ;

CommaExpr: /*empty*/            {$$ = NULL;}
    | CommaExpr COMMA Expr  {                                              
                                if ($1 != NULL){
                                    $$ = $1; 
                                    add_brother($1, $3);
                                } 
                                else {$$ = $3;}                                               
                            }
    ;

Assignment: ID ASSIGN Expr  {
                                $$ = create_node("Assign", "", $2->line, $2->col);
                                add_son($$, create_identifier_node("Id", $1));
                                add_brother($$->filho, $3);                               
                                }
    ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR   {
                                                    $$ = create_node("ParseArgs", "", $1->line, $1->col);
                                                    add_son($$, create_identifier_node("Id", $3));
                                                    add_brother($$->filho, $5);    
                                                }
    | PARSEINT LPAR error RPAR                  {
                                                    $$ = NULL;
                                                }
    ;

Expr: Expr2                                     {$$ = $1;}
    | Assignment                                {$$ = $1;}
;

Expr2: Expr2 PLUS Expr2                                 {
                                                            $$ = create_node("Add", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 MINUS Expr2                                 {
                                                            $$ = create_node("Sub", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 STAR Expr2                                  {
                                                            $$ = create_node("Mul", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 DIV Expr2                                   {
                                                            $$ = create_node("Div", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 MOD Expr2                                   {
                                                             $$ = create_node("Mod", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 AND Expr2                                   {
                                                            $$ = create_node("And", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 OR Expr2                                    {
                                                            $$ = create_node("Or", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 XOR Expr2                                   {
                                                            $$ = create_node("Xor", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 LSHIFT Expr2                                {
                                                            $$ = create_node("Lshift", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 RSHIFT Expr2                                {
                                                            $$ = create_node("Rshift", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 EQ Expr2                                    {
                                                            $$ = create_node("Eq", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 GE Expr2                                    {
                                                            $$ = create_node("Ge", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 GT Expr2                                    {
                                                            $$ = create_node("Gt", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 LE Expr2                                    {
                                                            $$ = create_node("Le", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 LT Expr2                                    {
                                                            $$ = create_node("Lt", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | Expr2 NE Expr2                                    {
                                                            $$ = create_node("Ne", "", $2->line, $2->col);
                                                            add_son($$,$1);
						                                    add_brother($1,$3);
                                                        }
    | MINUS Expr2 %prec NOT                             {
                                                            $$ = create_node("Minus","", linha, coluna);
							                                add_son($$,$2);
                                                        }
    | NOT Expr2                                         {
                                                            $$ = create_node("Not","", $1->line, $1->col);
							                                add_son($$,$2);
                                                        }
    | PLUS Expr2  %prec NOT                             {
                                                            $$ = create_node("Plus","", linha, coluna);
							                                add_son($$,$2);
                                                        }
    | LPAR Expr RPAR                                    {
                                                            $$ = $2;
                                                        }
    | MethodInvocation                                  {
                                                            $$ = $1;
                                                        }
    | ParseArgs                                         {
                                                            $$ = $1;
                                                        }
    | ID DOTLENGTH                                      {
                                                            $$ = create_node("Length","", linha, coluna);
                                                            add_son($$,create_identifier_node("Id",$1));
                                                        }
    | ID                                                {
                                                            $$ = create_identifier_node("Id",$1);
                                                        }
    | INTLIT                                            {
                                                            $$ = create_identifier_node("DecLit",$1);
                                                        }
    | REALLIT                                           {
                                                            $$ = create_identifier_node("RealLit",$1);
                                                        }
    | BOOLLIT                                           {
                                                            $$ = create_identifier_node("BoolLit",$1);
                                                        }
    | LPAR error RPAR                                   {
                                                            $$ = NULL;
                                                        }   
;

%%


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
        if(!containsErrors){
            check_tree(root);          
        }
	}

	free(str);
	return 0;
}