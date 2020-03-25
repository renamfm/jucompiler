	// Developed by:
	// Renato Matos 2015257602
	// Sergio Machado 2017265620

%{
	#include <stdlib.h>
	#include <string.h>

	#define ADDLINE currentLine++; currentCol = 1;
	#define ADDCOL currentCol += yyleng;

	char *str;
	int flagLex = 0, flagInvalidChar = 0;
	int currentLine = 1, currentCol = 1;
	int commentLine=1, commentCol = 1;
	int stringLine = 1, stringCol = 1;

%}

digit0				[0-9]
digit				[1-9]
letter				[a-zA-Z_$]
number              {digit0}(({digit0}|"_")*{digit0})*

%X STRING COMMENT COMMENT2

%%

" "|\f|\t												{ADDCOL;}
\n|\r|\r\n												{ADDLINE;}

\"														{BEGIN STRING;strcpy(str, ""); stringLine = currentLine, stringCol = currentCol; ADDCOL;}
<STRING>\"												{if(flagLex==1 && flagInvalidChar==0){printf("STRLIT(\"%s\")\n", str);} BEGIN 0; flagInvalidChar=0; ADDCOL;}
<STRING>\n|\r											{printf("Line %d, col %d: unterminated string literal\n", stringLine, stringCol); BEGIN 0; flagInvalidChar=0; ADDLINE;}
<STRING>\\(f|n|r|t|\\|\")								{strcat(str, yytext); ADDCOL;}
<STRING>\\.|\\											{flagInvalidChar=1; printf("Line %d, col %d: invalid escape sequence (%s)\n", currentLine, currentCol, yytext); ADDCOL;}
<STRING>.												{strcat(str, yytext); ADDCOL;}
<STRING><<EOF>>											{BEGIN 0; printf("Line %d, col %d: unterminated string literal\n", stringLine, stringCol); ADDCOL;}

"/*"													{BEGIN COMMENT; commentLine =  currentLine; commentCol = currentCol; ADDCOL;}
<COMMENT>"*/"											{BEGIN 0; ADDCOL;}
<COMMENT>\n|\r|\r\n										{ADDLINE;}
<COMMENT>.												{ADDCOL;}
<COMMENT><<EOF>>										{BEGIN 0; printf("Line %d, col %d: unterminated comment\n", commentLine, commentCol); ADDCOL;}

"//"													{BEGIN COMMENT2; ADDCOL;}
<COMMENT2>\n|\r|\r\n									{BEGIN 0; ADDLINE;}
<COMMENT2>.												{ADDCOL;}

true|false												{if(flagLex==1){printf("BOOLLIT(%s)\n", yytext);} ADDCOL;}
"&&"													{if(flagLex==1){printf("AND\n");} ADDCOL;}
"="														{if(flagLex==1){printf("ASSIGN\n");} ADDCOL;}
"*"														{if(flagLex==1){printf("STAR\n");} ADDCOL;}
","														{if(flagLex==1){printf("COMMA\n");} ADDCOL;}
"/"														{if(flagLex==1){printf("DIV\n");} ADDCOL;}
"=="													{if(flagLex==1){printf("EQ\n");} ADDCOL;}
">="													{if(flagLex==1){printf("GE\n");} ADDCOL;}
">"														{if(flagLex==1){printf("GT\n");} ADDCOL;}
"{"														{if(flagLex==1){printf("LBRACE\n");} ADDCOL;}
"<="													{if(flagLex==1){printf("LE\n");} ADDCOL;}
"("														{if(flagLex==1){printf("LPAR\n");} ADDCOL;}
"["														{if(flagLex==1){printf("LSQ\n");} ADDCOL;}
"<"														{if(flagLex==1){printf("LT\n");} ADDCOL;}
"-"														{if(flagLex==1){printf("MINUS\n");} ADDCOL;}
"%"														{if(flagLex==1){printf("MOD\n");} ADDCOL;}
"!="													{if(flagLex==1){printf("NE\n");} ADDCOL;}
"!"														{if(flagLex==1){printf("NOT\n");} ADDCOL;}
"||"													{if(flagLex==1){printf("OR\n");} ADDCOL;}
"+"														{if(flagLex==1){printf("PLUS\n");} ADDCOL;}
"}"														{if(flagLex==1){printf("RBRACE\n");} ADDCOL;}
")"														{if(flagLex==1){printf("RPAR\n");} ADDCOL;}
"]"														{if(flagLex==1){printf("RSQ\n");} ADDCOL;}
";"														{if(flagLex==1){printf("SEMICOLON\n");} ADDCOL;}
"->"													{if(flagLex==1){printf("ARROW\n");} ADDCOL;}
"<<"													{if(flagLex==1){printf("LSHIFT\n");} ADDCOL;}
">>"													{if(flagLex==1){printf("RSHIFT\n");} ADDCOL;}
"^"														{if(flagLex==1){printf("XOR\n");} ADDCOL;}
boolean													{if(flagLex==1){printf("BOOL\n");} ADDCOL;}
class													{if(flagLex==1){printf("CLASS\n");} ADDCOL;}
"."length												{if(flagLex==1){printf("DOTLENGTH\n");} ADDCOL;}
double													{if(flagLex==1){printf("DOUBLE\n");} ADDCOL;}
else													{if(flagLex==1){printf("ELSE\n");} ADDCOL;}
if														{if(flagLex==1){printf("IF\n");} ADDCOL;}
int														{if(flagLex==1){printf("INT\n");} ADDCOL;}
System"."out"."print									{if(flagLex==1){printf("PRINT\n");} ADDCOL;}
Integer"."parseInt										{if(flagLex==1){printf("PARSEINT\n");} ADDCOL;}
public													{if(flagLex==1){printf("PUBLIC\n");} ADDCOL;}
return													{if(flagLex==1){printf("RETURN\n");} ADDCOL;}
static													{if(flagLex==1){printf("STATIC\n");} ADDCOL;}
String													{if(flagLex==1){printf("STRING\n");} ADDCOL;}
void													{if(flagLex==1){printf("VOID\n");} ADDCOL;}
while													{if(flagLex==1){printf("WHILE\n");} ADDCOL;}

"++"|"--"|null|Integer|System|abstract|continue|switch|assert|default|package|synchronized|do|goto|private|for|new|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super				{if(flagLex==1){printf("RESERVED(%s)\n", yytext);} ADDCOL;}

{letter}({letter}|{digit0})*						    {if(flagLex==1){printf("ID(%s)\n", yytext);} ADDCOL;}									
0|({digit}{digit0}*(_+{digit0}+)*)						{if(flagLex==1){printf("INTLIT(%s)\n", yytext);} ADDCOL;}
{number}"."{number}?((e|E)("+"|"-")?{number})?          {if(flagLex==1){printf("REALLIT(%s)\n", yytext);} ADDCOL;}
"."{number}((e|E)("+"|"-")?{number})?                   {if(flagLex==1){printf("REALLIT(%s)\n", yytext);} ADDCOL;}
{number}(e|E)("+"|"-")?{number}                         {if(flagLex==1){printf("REALLIT(%s)\n", yytext);} ADDCOL;}

.														{printf("Line %d, col %d: illegal character (%s)\n", currentLine, currentCol, yytext); ADDCOL;}

%%

int main(int argc,char* argv[]){
	str = malloc(256*sizeof(char));
	if(argv[1] != NULL){
		if(strcmp(argv[1], "-l") == 0)
			flagLex = 1;
	}
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
