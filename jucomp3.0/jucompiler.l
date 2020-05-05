	// Developed by:
	// Renato Matos 2015257602
	// Sergio Machado 2017265620

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	#include "tree.h"
	#include "symbol_table.h"

	#define ADDLINE currentLine++; currentCol = 1;
	#define ADDCOL currentCol += yyleng;

	extern char *str;
	extern int flag, containsErrors;
	extern int linha, coluna;
	int flagInvalidChar = 0;
	int currentLine = 1, currentCol = 1;
	int commentLine=1, commentCol = 1;
	int stringLine = 1, stringCol = 1;
	int activeString = 0;

	void countLines(){if((strcmp(yytext,"\n")==0)||strcmp(yytext,"\r")==0||strcmp(yytext,"\r\n")==0){currentLine++;currentCol=1;}else{currentCol+=yyleng;}}

%}

digit0				[0-9]
digit				[1-9]
letter				[a-zA-Z_$]
number              {digit0}(({digit0}|"_")*{digit0})*

%X STR COMMENT COMMENT2

%%

" "|\f|\t												{ADDCOL;}
\n|\r|\r\n												{ADDLINE;}

\"                										{stringLine=currentLine; stringCol=currentCol;BEGIN STR;flagInvalidChar=0;strcpy(str,""); ADDCOL;}
<STR>\"        											{if(flag == 1){ if(flagInvalidChar==0){printf("STRLIT(\"%s\")\n",str);}} if(flagInvalidChar==0){if(flag==2){activeString=1; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; BEGIN 0; return STRLIT;};};}
<STR>\n|\r|\r\n         								{printf("Line %d, col %d: unterminated string literal\n", stringLine, stringCol);ADDLINE;stringLine=1; stringCol=1;flagInvalidChar=1;BEGIN 0;}
<STR>\\(f|n|r|t|\\|\")  								{strcat(str,yytext);countLines();}
<STR>\\.|\\             								{printf("Line %d, col %d: invalid escape sequence (%s)\n", currentLine, currentCol, yytext);flagInvalidChar=1;ADDCOL;}
<STR>.                  								{strcat(str,yytext);ADDCOL;}
 
"/*"													{BEGIN COMMENT; commentLine =  currentLine; commentCol = currentCol; ADDCOL;}
<COMMENT>"*/"											{BEGIN 0; ADDCOL;}
<COMMENT>\n|\r|\r\n										{ADDLINE;}
<COMMENT>.												{ADDCOL;}
<COMMENT><<EOF>>										{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", commentLine, commentCol);}

"//"													{BEGIN COMMENT2; ADDCOL;}
<COMMENT2>\n|\r|\r\n									{BEGIN 0; ADDLINE;}
<COMMENT2>.												{ADDCOL;}

true|false												{if(flag==1){printf("BOOLLIT(%s)\n", yytext);} if(flag == 2){yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; activeString = 0; return BOOLLIT;}}
"&&"													{if(flag==1){printf("AND\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return AND;}}
"="														{if(flag==1){printf("ASSIGN\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return ASSIGN;}}
"*"														{if(flag==1){printf("STAR\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return STAR;}}
","														{if(flag==1){printf("COMMA\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return COMMA;}}
"/"														{if(flag==1){printf("DIV\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return DIV;}}
"=="													{if(flag==1){printf("EQ\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return EQ;}}
">="													{if(flag==1){printf("GE\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return GE;}}
">"														{if(flag==1){printf("GT\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return GT;}}
"{"														{if(flag==1){printf("LBRACE\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LBRACE;}}
"<="													{if(flag==1){printf("LE\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LE;}}
"("														{if(flag==1){printf("LPAR\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LPAR;}}
"["														{if(flag==1){printf("LSQ\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LSQ;}}
"<"														{if(flag==1){printf("LT\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LT;}}
"-"														{if(flag==1){printf("MINUS\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return MINUS;}}
"%"														{if(flag==1){printf("MOD\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return MOD;}}
"!="													{if(flag==1){printf("NE\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return NE;}}
"!"														{if(flag==1){printf("NOT\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return NOT;}}
"||"													{if(flag==1){printf("OR\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return OR;}}
"+"														{if(flag==1){printf("PLUS\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return PLUS;}}
"}"														{if(flag==1){printf("RBRACE\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RBRACE;}}
")"														{if(flag==1){printf("RPAR\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RPAR;}}
"]"														{if(flag==1){printf("RSQ\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RSQ;}}
";"														{if(flag==1){printf("SEMICOLON\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return SEMICOLON;}}
"->"													{if(flag==1){printf("ARROW\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return ARROW;}}
"<<"													{if(flag==1){printf("LSHIFT\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return LSHIFT;}}
">>"													{if(flag==1){printf("RSHIFT\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RSHIFT;}}
"^"														{if(flag==1){printf("XOR\n");} linha = currentLine; coluna = currentCol; yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(str); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return XOR;}}
boolean													{if(flag==1){printf("BOOL\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return BOOL;}}
class													{if(flag==1){printf("CLASS\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return CLASS;}}
"."length												{if(flag==1){printf("DOTLENGTH\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return DOTLENGTH;}}
double													{if(flag==1){printf("DOUBLE\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return DOUBLE;}}
else													{if(flag==1){printf("ELSE\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return ELSE;}}
if														{if(flag==1){printf("IF\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return IF;}}
int														{if(flag==1){printf("INT\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return INT;}}
System"."out"."print									{if(flag==1){printf("PRINT\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return PRINT;}}
Integer"."parseInt										{if(flag==1){printf("PARSEINT\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return PARSEINT;}}
public													{if(flag==1){printf("PUBLIC\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return PUBLIC;}}
return													{if(flag==1){printf("RETURN\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RETURN;}}
static													{if(flag==1){printf("STATIC\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return STATIC;}}
String													{if(flag==1){printf("STRING\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return STRING;}}
void													{if(flag==1){printf("VOID\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return VOID;}}
while													{if(flag==1){printf("WHILE\n");} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return WHILE;}}

"++"|"--"|null|Integer|System|abstract|continue|switch|assert|default|package|synchronized|do|goto|private|for|new|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super		{if(flag==1){printf("RESERVED(%s)\n", yytext);} linha = currentLine; coluna = currentCol; ADDCOL; if(flag == 2){ activeString = 0; return RESERVED;}}

{letter}({letter}|{digit0})*						    {if(flag==1){printf("ID(%s)\n", yytext);} yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine ; yylval.id->col = currentCol; ADDCOL; if(flag == 2){activeString = 0; return ID;}}									
0|({digit}{digit0}*(_+{digit0}+)*)						{if(flag==1){printf("INTLIT(%s)\n", yytext);} yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){activeString = 0; return INTLIT;}}
{number}"."{number}?((e|E)("+"|"-")?{number})?          {if(flag==1){printf("REALLIT(%s)\n", yytext);} yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){activeString = 0; return REALLIT;}}
"."{number}((e|E)("+"|"-")?{number})?                   {if(flag==1){printf("REALLIT(%s)\n", yytext);} yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){activeString = 0; return REALLIT;}}
{number}(e|E)("+"|"-")?{number}                         {if(flag==1){printf("REALLIT(%s)\n", yytext);} yylval.id = (Identifier*)malloc(sizeof(Identifier)); yylval.id->id = strdup(yytext); yylval.id->line = currentLine; yylval.id->col = currentCol; ADDCOL; if(flag == 2){activeString = 0; return REALLIT;}}

.														{printf("Line %d, col %d: illegal character (%s)\n", currentLine, currentCol, yytext); ADDCOL;}

%%

int yywrap(){
	return 1;
}

void yyerror(char *s) {
	containsErrors = 1;

	if(activeString == 0){
		printf("Line %d, col %d: %s: %s\n", currentLine, (int)(currentCol - strlen(yytext)), s, yytext);
	}else{
		printf("Line %d, col %d: %s: \"%s\"\n", stringLine, stringCol, s, str);				
	}    
}