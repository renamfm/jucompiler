lex jucompiler.l
yacc -d jucompiler.y
cc -o jucompiler y.tab.c lex.yy.c

