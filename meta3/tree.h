#include <stdio.h>
#include <stdlib.h>

typedef struct identifier{
        char* id;
        int line;
        int col;
}Identifier;

typedef struct ASTREE* AST_pointer;
typedef struct ASTREE{
    char * nome;
    char* valor;
    char* anotar;
    char* return_id;
    int is_call;
    int linha, coluna;
    AST_pointer pai;
    AST_pointer filho;
    AST_pointer irmao;
}ASTREE;

int yylex(void);
int yyparse();

//ASTREE functions
AST_pointer create_node(char* nome, char* valor, int linha, int coluna);
AST_pointer create_identifier_node(char* nome, Identifier* id);
void add_son(AST_pointer pai, AST_pointer new_node);
void add_brother(AST_pointer initial_brother, AST_pointer new_brother);
int count_brothers(AST_pointer root);
void print_tree(AST_pointer n, int depth);
void print_tree_anoted(AST_pointer root, int depth);