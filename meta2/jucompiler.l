	// Developed by:
	// Renato Matos 2015257602
	// Sergio Machado 2017265620

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	//#include "functions.h"

	#define ADDLINE currentLine++; currentCol = 1;
	#define ADDCOL currentCol += yyleng;


	char *str;
	int flag = 0, flagInvalidChar = 0;
	int currentLine = 1, currentCol = 1;
	int commentLine=1, commentCol = 1;
	int stringLine = 1, stringCol = 1;

%}

digit0				[0-9]
digit				[1-9]
letter				[a-zA-Z_$]
number              {digit0}(({digit0}|"_")*{digit0})*

%X STR COMMENT COMMENT2

%%

" "|\f|\t												{ADDCOL;}
\n|\r|\r\n												{ADDLINE;}

\"														{BEGIN STRING;strcpy(str, ""); stringLine = currentLine, stringCol = currentCol; ADDCOL;}
<STR>\"													{if(flag==1 && flagInvalidChar==0){printf("STRLIT(\"%s\")\n", str);} BEGIN 0; flagInvalidChar=0; ADDCOL;}
<STR>\n|\r												{printf("Line %d, col %d: unterminated string literal\n", stringLine, stringCol); BEGIN 0; flagInvalidChar=0; ADDLINE;}
<STR>\\(f|n|r|t|\\|\")									{strcat(str, yytext); ADDCOL;}
<STR>\\.|\\												{flagInvalidChar=1; printf("Line %d, col %d: invalid escape sequence (%s)\n", currentLine, currentCol, yytext); ADDCOL;}
<STR>.													{strcat(str, yytext); ADDCOL;}
<STR><<EOF>>											{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", stringLine, stringCol); ADDCOL;}

"/*"													{BEGIN COMMENT; commentLine =  currentLine; commentCol = currentCol; ADDCOL;}
<COMMENT>"*/"											{BEGIN 0; ADDCOL;}
<COMMENT>\n|\r|\r\n										{ADDLINE;}
<COMMENT>.												{ADDCOL;}
<COMMENT><<EOF>>										{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", commentLine, commentCol); ADDCOL;}

"//"													{BEGIN COMMENT2; ADDCOL;}
<COMMENT2>\n|\r|\r\n									{BEGIN 0; ADDLINE;}
<COMMENT2>.												{ADDCOL;}

true|false												{if(flag==1){printf("BOOLLIT(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext); return BOOLLIT;}}
"&&"													{if(flag==1){printf("AND\n");} ADDCOL;if(flag == 2){return AND;}}
"="														{if(flag==1){printf("ASSIGN\n");} ADDCOL; if(flag == 2){return ASSIGN;}}
"*"														{if(flag==1){printf("STAR\n");} ADDCOL; if(flag == 2){return STAR;}}
","														{if(flag==1){printf("COMMA\n");} ADDCOL; if(flag == 2){return COMMA;}}
"/"														{if(flag==1){printf("DIV\n");} ADDCOL; if(flag == 2){return DIV;}}
"=="													{if(flag==1){printf("EQ\n");} ADDCOL; if(flag == 2){return EQ;}}
">="													{if(flag==1){printf("GE\n");} ADDCOL; if(flag == 2){return GE;}}
">"														{if(flag==1){printf("GT\n");} ADDCOL; if(flag == 2){return GT;}}
"{"														{if(flag==1){printf("LBRACE\n");} ADDCOL; if(flag == 2){return LBRACE;}}
"<="													{if(flag==1){printf("LE\n");} ADDCOL; if(flag == 2){return LE;}}
"("														{if(flag==1){printf("LPAR\n");} ADDCOL; if(flag == 2){return LPAR;}}
"["														{if(flag==1){printf("LSQ\n");} ADDCOL; if(flag == 2){return LSQ;}}
"<"														{if(flag==1){printf("LT\n");} ADDCOL; if(flag == 2){return LT;}}
"-"														{if(flag==1){printf("MINUS\n");} ADDCOL; if(flag == 2){return MINUS;}}
"%"														{if(flag==1){printf("MOD\n");} ADDCOL; if(flag == 2){return MOD;}}
"!="													{if(flag==1){printf("NE\n");} ADDCOL; if(flag == 2){return NE;}}
"!"														{if(flag==1){printf("NOT\n");} ADDCOL; if(flag == 2){return NOT;}}
"||"													{if(flag==1){printf("OR\n");} ADDCOL; if(flag == 2){return OR;}}
"+"														{if(flag==1){printf("PLUS\n");} ADDCOL; if(flag == 2){return PLUS;}}
"}"														{if(flag==1){printf("RBRACE\n");} ADDCOL; if(flag == 2){return RBRACE;}}
")"														{if(flag==1){printf("RPAR\n");} ADDCOL; if(flag == 2){return RPAR;}}
"]"														{if(flag==1){printf("RSQ\n");} ADDCOL; if(flag == 2){return RSQ;}}
";"														{if(flag==1){printf("SEMICOLON\n");} ADDCOL; if(flag == 2){return SEMICOLON;}}
"->"													{if(flag==1){printf("ARROW\n");} ADDCOL; if(flag == 2){return ARROW;}}
"<<"													{if(flag==1){printf("LSHIFT\n");} ADDCOL; if(flag == 2){return LSHIFT;}}
">>"													{if(flag==1){printf("RSHIFT\n");} ADDCOL; if(flag == 2){return RSHIFT;}}
"^"														{if(flag==1){printf("XOR\n");} ADDCOL; if(flag == 2){return XOR;}}
boolean													{if(flag==1){printf("BOOL\n");} ADDCOL; if(flag == 2){return BOOL;}}
class													{if(flag==1){printf("CLASS\n");} ADDCOL; if(flag == 2){return CLASS;}}
"."length												{if(flag==1){printf("DOTLENGTH\n");} ADDCOL; if(flag == 2){return DOTLENGTH;}}
double													{if(flag==1){printf("DOUBLE\n");} ADDCOL; if(flag == 2){return DOUBLE;}}
else													{if(flag==1){printf("ELSE\n");} ADDCOL; if(flag == 2){return ELSE;}}
if														{if(flag==1){printf("IF\n");} ADDCOL; if(flag == 2){return IF;}}
int														{if(flag==1){printf("INT\n");} ADDCOL; if(flag == 2){return INT;}}
System"."out"."printf									{if(flag==1){printf("PRINT\n");} ADDCOL; if(flag == 2){return PRINT;}}
Integer"."parseInt										{if(flag==1){printf("PARSEINT\n");} ADDCOL; if(flag == 2){return PARSEINT;}}
public													{if(flag==1){printf("PUBLIC\n");} ADDCOL; if(flag == 2){return PUBLIC;}}
return													{if(flag==1){printf("RETURN\n");} ADDCOL; if(flag == 2){return RETURN;}}
static													{if(flag==1){printf("STATIC\n");} ADDCOL; if(flag == 2){return STATIC;}}
String													{if(flag==1){printf("STRING\n");} ADDCOL; if(flag == 2){return STRING;}}
void													{if(flag==1){printf("VOID\n");} ADDCOL; if(flag == 2){return VOID;}}
while													{if(flag==1){printf("WHILE\n");} ADDCOL; if(flag == 2){return WHILE;}}

"++"|"--"|null|Integer|System|abstract|continue|switch|assert|default|package|synchronized|do|goto|private|for|new|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super				{if(flag==1){printf("RESERVED(%s)\n", yytext);} ADDCOL; if(flag == 2){return RESERVED;}}

{letter}({letter}|{digit0})*						    {if(flag==1){printf("ID(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext); return ID;}}									
0|({digit}{digit0}*(_+{digit0}+)*)						{if(flag==1){printf("INTLIT(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext);return INTLIT;}}
{number}"."{number}?((e|E)("+"|"-")?{number})?          {if(flag==1){printf("REALLIT(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext);return REALLIT;}}
"."{number}((e|E)("+"|"-")?{number})?                   {if(flag==1){printf("REALLIT(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext);return REALLIT;}}
{number}(e|E)("+"|"-")?{number}                         {if(flag==1){printf("REALLIT(%s)\n", yytext);} ADDCOL; if(flag == 2){yylval.id = strdup(yytext);return REALLIT;}}

.														{printf("Line %d, col %d: illegal character (%s)\n", currentLine, currentCol, yytext); ADDCOL;}

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
		}
		else if(strcmp(argv[1], "-e2") == 0){
			//erros sintaticos e lexicais
			yyparse();
		}
	}
	else{
		//erros sintaticos e lexicais
		yyparse();
	}

	free(str);
	return 0;
}

int yywrap(){
	return 1;
}

void yyerror(char *msg) {
    printf("%s\n", msg);
}