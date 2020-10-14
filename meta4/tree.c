#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//cria um novo no e retorna-o
AST_pointer create_node(char* nome, char* valor, int linha, int coluna){
    AST_pointer new_node = (AST_pointer)malloc(sizeof(ASTREE));   //alocar memoria para o no
    new_node->nome = (char*)malloc(strlen(nome) * sizeof(char) + 1);    //alocar memoria para o nome do simbolo 
    strcpy(new_node->nome, nome);   //copiar o nome do simbolo para a tree
    
    new_node->valor = (char*)malloc(strlen(valor) * sizeof(char) + 1);    //alocar memoria para o valor do simbolo 
    strcpy(new_node->valor, valor);   //copiar o valor do simbolo para a tree

    new_node->linha = linha;
    new_node->coluna = coluna;
    //colocar as  ligaçoes para os outros nos a null
    new_node->pai = NULL;
    new_node->filho = NULL;
    new_node->irmao = NULL;
    new_node->is_call = 0;

    return new_node;
}


AST_pointer create_identifier_node(char* nome, Identifier* id){
    AST_pointer new_node = (AST_pointer)malloc(sizeof(ASTREE));   //alocar memoria para o no
    new_node->nome = (char*)malloc(strlen(nome) * sizeof(char) + 1);    //alocar memoria para o nome do simbolo 
    strcpy(new_node->nome, nome);   //copiar o nome do simbolo para a tree
    
    new_node->valor = (char*)malloc(strlen(id->id) * sizeof(char) + 1);    //alocar memoria para o valor do simbolo 
    strcpy(new_node->valor, id->id);   //copiar o valor do simbolo para a tree

    //atribuir linha e coluna
    new_node->linha = id->line;
    new_node->coluna = id->col;

    //colocar as  ligaçoes para os outros nos a null
    new_node->pai = NULL;
    new_node->filho = NULL;
    new_node->irmao = NULL;
    new_node->is_call = 0;

    //printf("Identifier -> Nome:%s Valor:%s Linha:%d Coluna:%d\n", new_node->nome, new_node->valor, new_node->linha, new_node->coluna);

    return new_node;
}

//adicionar novo filho (quando se desce na gramatica)
void add_son(AST_pointer pai, AST_pointer new_node){
    if(new_node != NULL && pai!= NULL){
        pai->filho = new_node;
        new_node = pai;
    }
    return;
}

void add_brother(AST_pointer initial_brother, AST_pointer new_brother){
    if(initial_brother != NULL && new_brother != NULL){
        AST_pointer temp = initial_brother;

        //chegar ao fim dos irmaos
        while(temp->irmao != NULL){
            temp = temp->irmao;
        }

        temp->irmao = new_brother;

        if(new_brother->pai != NULL){
            new_brother->pai = temp->pai;
        }
    }
    return;
}

//contar o numero de irmaos para dar print aos Block;
int count_brothers(AST_pointer root){
    int brother_number = 0;
    AST_pointer temp;
    
    temp = root;

    while(temp != NULL){
        temp = temp->irmao;
        brother_number += 1;
    }
    return brother_number;
}

//imprimir a arvore
//sera que funciona?
void print_tree(AST_pointer root, int depth){
	if (root == NULL) return;
	for (int i = 0; i < depth; i++) printf("..");
	if(strcmp(root->valor, "") == 0 ){ 
        printf("%s\n", root->nome);
    }
    else if(strcmp(root->nome, "StrLit") == 0 ){
        printf("%s(\"%s\")\n", root->nome, root->valor);
    }
    else{
        printf("%s(%s)\n", root->nome, root->valor);
    }
  
	print_tree(root->filho, depth + 1);
	print_tree(root->irmao , depth);
}



//imprimir a arvore
void print_tree_anoted(AST_pointer root, int depth){
	if (root == NULL)
        return;
	
    for (int i = 0; i < depth; i++)
        printf("..");

	if(strcmp(root->valor, "") == 0 && strcmp(root->nome, "StrLit") != 0 ){ 
        printf("%s", root->nome);
    }
    else if(strcmp(root->nome, "StrLit") == 0 ){
        printf("%s(\"%s\")", root->nome, root->valor);
    }
    else{
        printf("%s(%s)", root->nome, root->valor);
    }

    if(root->anotar != NULL){
        if(root->is_call == 1){
            printf(" - (%s)", root->anotar);
        }else{
            if(strcmp(root->anotar, "none")!=0){
                printf(" - %s", root->anotar);
            }
        }
    }
    printf("\n");
  
	print_tree_anoted(root->filho, depth + 1);
	print_tree_anoted(root->irmao , depth);
}
