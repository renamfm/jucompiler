lex jucompiler.l
bison -y -d -t -v jucompiler.y
cc -o jucompiler tree.c symbol_table.c semantics.c lex.yy.c y.tab.c
zip -r jucompiler.zip jucompiler.l jucompiler.y tree.h tree.c symbol_table.h symbol_table.c semantics.c
