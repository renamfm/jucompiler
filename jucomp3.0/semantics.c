#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "symbol_table.h"
#define MAX 100


void check_tree(AST_pointer root){
    if(root == NULL){
        return;
    }
     
    //O primeiro no e o programa adicionar class e o nome a tabela
    AST_pointer temp = root->filho;
    AST_pointer temp2 = root->filho;
    char declaration[MAX];
    
    //Inicio aqui fora porque o program e a raiz e no ciclo while vamos ver os filhos
    if(temp != NULL){
        strcpy(declaration, "Class ");
        strcat(declaration, temp->valor);
        global_table = create_table(declaration);
    }

     while(temp2 != NULL){
        if(strcmp(temp2->nome, "MethodDecl")==0){
            check_methoddecl(temp2, 1);

        }
        temp2 = temp2->irmao;
    }   

    while(temp != NULL){
        if(strcmp(temp->nome, "MethodDecl")==0){
            //AST_pointer header = temp->filho;
            check_methoddecl(temp, 0);

        }else{
            //Se nao for uma declaracao de uma funcao e uma var global
            check_vardec(temp, global_table);
        }
        temp = temp->irmao;
    }   
}

void check_methoddecl(AST_pointer node, int first_search){
        AST_pointer temp = node->filho;
        //char declaration[MAX];

        while(temp != NULL){
            if(strcmp(temp->nome, "MethodHeader") ==0){
                //cria um simbolo para a funcao
                AST_pointer header = temp->filho;
                symbol_pointer symbol = create_symbol( header->irmao->valor, id_to_type(header->nome), 0, 0,1,NULL);
                table_pointer new_function = NULL;  

                //Verifica se ha declaracao de parametros
                if(header->irmao->irmao != NULL){
                    //passa o simbolo funcao
                    //retorna tabela para a funcao ja com o nome dela
                    new_function = check_func_params(header->irmao->irmao, symbol, first_search);
                    //adicionar agora o simbolo return
                                    
                }

                if(strcmp(temp->irmao->nome, "MethodBody") ==0 && first_search == 0){
                    check_func_body(temp->irmao, new_function);
                }
            }
            
            temp = temp->irmao->irmao;
        }      
}

//Verificar a declaracao de parametros de uma funcao
table_pointer check_func_params(AST_pointer node, symbol_pointer func_table, int first_search){
    AST_pointer temp = node->filho;
    char declaration[MAX];

    while(temp != NULL){
         if(strcmp(temp->nome, "ParamDecl")==0){
            put_param(func_table, create_param(id_to_type(temp->filho->nome), temp->filho->irmao->valor));
            
         }
        temp = temp->irmao;
    }

    if(first_search == 1){
    //Cria nova tabela para as variaveis funcao
    put_symbol(global_table, func_table);
    }
    strcpy(declaration, "Method ");
    strcat(declaration, func_table->nome);
    
    param_pointer aux = func_table->params;
    strcat(declaration, "(");
    if(aux != NULL){
        strcat(declaration, aux->tipo);
        aux = aux->next;
    }
    while (aux != NULL){
        strcat(declaration, ",");
        strcat(declaration, aux->tipo);
        aux = aux->next;     
    }
    strcat(declaration, ")");
    //printf("%s", declaration);
    table_pointer new_function = create_table(declaration);
    put_symbol(new_function, create_symbol("return", id_to_type(func_table->tipo), 0, 0, 0, NULL));

    param_pointer pt = func_table->params;
    
    while (pt != NULL)
    {
        put_symbol(new_function, create_symbol(pt->nome, pt->tipo, 0, 0, 2, NULL));
        pt = pt->next;
    }
    

    return new_function;
}

//Verificar body de uma funcao
void check_func_body(AST_pointer node, table_pointer func_table){
    AST_pointer temp = node->filho;
    while(temp != NULL){
             
        if(strcmp(temp->nome, "VarDecl")==0){
            put_symbol(func_table, create_symbol(temp->filho->irmao->valor, id_to_type(temp->filho->nome), 0, 0, 0, NULL));
        }else{
            //e porque e um statement
            check_statement(temp, func_table, 0);
        }
        
        temp = temp -> irmao;
    }

    put_table(global_table, func_table);
}

void check_statement(AST_pointer node, table_pointer func_table, int is_Call){
        if(node == NULL){
            return;
        }


        //printf("%s\n", node->nome);
        if(strcmp(node->nome, "Block") == 0){
            check_statement(node->filho, func_table, 0);
        
        }else if(strcmp(node->nome, "If") == 0){
            check_statement(node->filho, func_table, 0);
            check_statement(node->filho->irmao, func_table, 0);
            if(node->filho->irmao != NULL){
                check_statement(node->filho->irmao->irmao, func_table, 0);
            }
        }
        else if(strcmp(node->nome, "While") == 0){
            check_statement(node->filho, func_table, 0);
            check_statement(node->filho->irmao, func_table, 0);
        }
        else if(strcmp(node->nome, "Return") == 0){
        
            if( node->filho != NULL){
                check_return_statement(node, func_table, 1);
            }else{
                check_return_statement(node, func_table, 0);
            }
        }
        else if(strcmp(node->nome, "Print") == 0){
            check_print_statement(node, func_table, "System.out.print");
        }
        else if(strcmp(node->nome, "Call") == 0){
            
            //Faco isto porque dentro do call pode haver outras operaçoes sei la :/
            AST_pointer temp = node->filho->irmao;
            while (temp != NULL)
            {
                //exists(temp, func_table);
                check_statement(temp, func_table, 0);
                temp = temp->irmao;
            }
            
            /*
            //Faco isto porque dentro do call pode haver outras operaçoes sei la :/
            //AST_pointer temp = node->filho->irmao;
            AST_pointer temp = node->filho;
            //printf("Nome:%s Valor:%s\n", temp->nome, temp->valor);
            //printf("Nome:%s Valor:%s\n", temp->irmao->nome, temp->irmao->valor);
            while (temp != NULL){
                if(strcmp(temp->nome, "Id")==0)
                    exists(temp, func_table, 1);
                else
                if(temp->is_call==1)
                    check_statement(temp, func_table, 0);
                temp = temp->irmao;
            }*/
            
            check_call_statement(node, func_table, "Call");

        }
        else if(strcmp(node->nome, "Assign") == 0){     
            //check_statement(node->filho->irmao, func_table); esta comentado porque senao ha erros repetidos
            check_assign_operation(node, func_table, "=");
        }
        else if(strcmp(node->nome, "ParseArgs") == 0){
            //check_statement(node->filho->irmao, func_table);
            check_parseArs_statement(node, func_table, "Integer.ParseInt");
        }
       else if(strcmp(node->nome, "Add") == 0){
            check_numbers_operation(node, func_table, "+");
        }
        else if(strcmp(node->nome, "Sub") == 0){
            check_numbers_operation(node, func_table, "-");
        }
        else if(strcmp(node->nome, "Mul") == 0){
            check_numbers_operation(node, func_table, "*");
        }
        else if(strcmp(node->nome, "Div") == 0){
            check_numbers_operation(node, func_table, "/");
        }
        else if(strcmp(node->nome, "Mod") == 0){
            check_numbers_operation(node, func_table, "%");
        }
        else if(strcmp(node->nome, "And") == 0){
            check_logical_operation(node, func_table, "&&");
        }
        else if(strcmp(node->nome, "Or") == 0){
            check_logical_operation(node, func_table, "||");
        }
        else if(strcmp(node->nome, "Xor") == 0){
            check_logical_operation(node, func_table, "^");
        }
        else if(strcmp(node->nome, "Lshift") == 0){
            check_shift_operation(node, func_table, "<<");
        }
        else if(strcmp(node->nome, "Rshift") == 0){
            check_shift_operation(node, func_table, ">>");
        }
        else if(strcmp(node->nome, "Eq") == 0){
            check_comparation_operation(node, func_table, "==");
        }
        else if(strcmp(node->nome, "Ge") == 0){
            check_comparation_operation(node, func_table, ">=");
        }
        else if(strcmp(node->nome, "Gt") == 0){
            check_comparation_operation(node, func_table, ">");
        }
        else if(strcmp(node->nome, "Le") == 0){
            check_comparation_operation(node, func_table, "<=");
        }
        else if(strcmp(node->nome, "Lt") == 0){
            check_comparation_operation(node, func_table, "<");
        }
        else if(strcmp(node->nome, "Ne") == 0){
            check_comparation_operation(node, func_table, "!=");
        }
        //aqui vamos separar o minus e o not pk o not so da para doubles e o minus/plus para int ou double
        else if(strcmp(node->nome, "Minus") == 0){
            check_unary_operation(node, func_table, "-");
        }
        //ja o not tb da para booleans
        else if(strcmp(node->nome, "Not") == 0){
            check_unary_not_operation(node, func_table, "!");
        }
        else if(strcmp(node->nome, "Plus") == 0){
            check_unary_operation(node, func_table, "+");
        }else if(node->anotar == NULL){
            exists(node, func_table, is_Call);
        }
}

//nesta funcao vemos se a variavel existe se for ID
//e anotamos a arvore
int exists(AST_pointer node, table_pointer func_table, int is_Call){
    symbol_pointer temp = symbol_exists(func_table, node->valor, is_Call, node);
    //printf("\n%s - %s \n",node->nome, node->valor);
    //se for o id e pk e uma variavel definida ou devia tar 
    if(strcmp(node->nome, "Id") == 0){
        
        //nao ta definida? entao ta undef ou e funcao
        if(temp == NULL){
            //Se nao for call tudo bem
            if(is_Call == 0){
                printf("Line %d, col %d: Cannot find symbol %s\n", node->linha,node->coluna, node->valor);
            }
            //se for e preciso dar print do tipo de argumentos
            else{
                printf("Line %d, col %d: Cannot find symbol %s", node->linha,node->coluna, node->valor);
                printf("(");
                if(node->irmao != NULL){
                    printf("%s", node->irmao->anotar);
                    AST_pointer aux;
                    aux = node->irmao->irmao;

                    while (aux != NULL){
                        printf(",%s", aux->anotar);
                        aux = aux->irmao;
                    }        
                }
                printf(")");
                printf("\n");
            }

            node->return_id = (char*)malloc(strlen(id_to_type("undef")) * sizeof(char)+1);
            strcpy(node->return_id, "undef"); 
            node->anotar = (char*)malloc(strlen("undef") * sizeof(char)+1);
            strcpy(node->anotar, "undef");
            node->is_call = 0;
            
            return 0;

        // e funcao
        }else if(temp->data_type == 1){

            char declarations[MAX];
            strcpy(declarations, "");
            AST_pointer aux10 = node->irmao;

            if(aux10 != NULL){
                strcat(declarations, aux10->anotar );
                aux10 = aux10->irmao;
            }
            
           while(aux10 != NULL){
                strcat(declarations, ",");
                strcat(declarations,aux10->anotar );
                aux10 = aux10->irmao;
                
            }

            //printf("%s: %s\n", node->valor, temp->tipo);
            
            node->return_id = (char*)malloc(strlen(id_to_type(temp->tipo)) * sizeof(char)+1);
            strcpy(node->return_id, id_to_type(temp->tipo)); 

            /*node->anotar = (char*)malloc(strlen(declarations) * sizeof(char)+1);
            strcpy(node->anotar, declarations); */
            node->is_call = 1;
            return 0;
        }
        
    }
    //nao e ID? entao e uma variavel nao definida
    else if(strcmp(node->nome, "DecLit") == 0){
        node->anotar = (char*)malloc(strlen("int") * sizeof(char) + 1);
        strcpy(node->anotar, "int");
        return 0;    
    }else if(strcmp(node->nome, "RealLit") == 0){
        node->anotar = (char*)malloc(strlen("double") * sizeof(char) + 1);
        strcpy(node->anotar, "double");
        return 0;
    }else if(strcmp(node->nome, "BoolLit") == 0){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
        return 0;
    }
    
    
    //aqui vem ter os ids definidos
    if(temp != NULL){
        
        node->anotar = (char*)malloc(strlen(temp->tipo) * sizeof(char) + 1);
        strcpy(node->anotar, id_to_type(temp->tipo));
    }

    return 1;
}

void check_numbers_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho,func_table, 0);
    check_statement(node->filho->irmao,func_table, 0);

    
    if(strcmp(node->filho->anotar, "int") == 0 && strcmp(node->filho->irmao->anotar, "int") == 0){
        node->anotar = (char*)malloc(strlen("int") * sizeof(char) + 1);
        strcpy(node->anotar, "int");
    }
    else if(strcmp(node->filho->anotar, "double") == 0 && strcmp(node->filho->irmao->anotar, "double") == 0){
        node->anotar = (char*)malloc(strlen("double") * sizeof(char) + 1);
        strcpy(node->anotar, "double");
    }else if((strcmp(node->filho->anotar, "int") == 0 && strcmp(node->filho->irmao->anotar, "double") == 0) || (strcmp(node->filho->anotar, "double") == 0 && strcmp(node->filho->irmao->anotar, "int") == 0)){
        node->anotar = (char*)malloc(strlen("double") * sizeof(char) + 1);
        strcpy(node->anotar, "double");
    }
    //acrescentei este por causa do testeProblemaE.java (adicao de booleans)
    else if((strcmp(node->filho->anotar, "boolean") == 0 && strcmp(node->filho->irmao->anotar, "boolean") == 0) || (strcmp(node->filho->anotar, "double") == 0 && strcmp(node->filho->irmao->anotar, "int") == 0)){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
    }
    else{
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, node->filho->anotar, node->filho->irmao->anotar);
    }
}

void check_logical_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);
    check_statement(node->filho->irmao, func_table, 0);

    if(strcmp(node->filho->anotar, "boolean") == 0 && strcmp(node->filho->irmao->anotar, "boolean") == 0){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
    }else{
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, node->filho->anotar, node->filho->irmao->anotar);
    }
    
}

void check_shift_operation(AST_pointer node, table_pointer func_table, char* operation){
    //check_statement(node->filho, func_table, 0);
    //check_statement(node->filho->irmao, func_table, 0);
    //Parece que o shift nao tem tipo...
    node->filho->anotar = (char*)malloc(strlen("none") * sizeof(char) + 1);
    strcpy(node->filho->anotar, "none");

    node->filho->irmao->anotar = (char*)malloc(strlen("none") * sizeof(char) + 1);
    strcpy(node->filho->irmao->anotar, "none");


    if(strcmp(node->filho->anotar, node->filho->irmao->anotar) == 0){
        node->anotar = (char*)malloc(strlen(node->filho->irmao->anotar) * sizeof(char) + 1);
        strcpy(node->anotar, node->filho->irmao->anotar);
    }else{
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, node->filho->anotar, node->filho->irmao->anotar);
    }
    
}

void check_unary_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);

    if(strcmp(node->filho->anotar, "int") == 0 && strcmp(node->filho->anotar, "double") == 0){
        node->anotar = (char*)malloc(strlen(node->filho->anotar) * sizeof(char) + 1);
        strcpy(node->anotar, node->filho->anotar);
    }else{
        printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", node->linha, node->coluna, operation, node->filho->anotar);
    }

}

void check_comparation_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);
    check_statement(node->filho->irmao, func_table, 0);

    if(strcmp(node->filho->anotar, "none") == 0 || strcmp(node->filho->irmao->anotar, "none") == 0){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, id_to_type(node->filho->anotar), node->filho->irmao->anotar);
    }else if(strcmp(node->filho->anotar, "undef") != 0 && strcmp(node->filho->irmao->anotar, "undef") != 0){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
    }else{
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
    }

}

void check_unary_not_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);

    if(strcmp(node->filho->anotar, "boolean") == 0){
        node->anotar = (char*)malloc(strlen("boolean") * sizeof(char) + 1);
        strcpy(node->anotar, "boolean");
    }else{
        printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", node->linha, node->coluna, operation, node->filho->anotar);
    }

}

void check_assign_operation(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);
    check_statement(node->filho->irmao, func_table, 0);

   if(strcmp(node->filho->anotar, node->filho->irmao->anotar) != 0 && strcmp(node->filho->anotar, "undef") == 0){
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
        printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, node->filho->anotar, node->filho->irmao->anotar);
    }else
    {   
        node->anotar = (char*)malloc(strlen(node->filho->anotar) * sizeof(char) + 1);
        strcpy(node->anotar, node->filho->anotar);
        if(strcmp(node->filho->anotar, node->filho->irmao->anotar) != 0){
            printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n",node->linha, node->coluna, operation, node->filho->anotar, node->filho->irmao->anotar);
        }
    }
}

void check_parseArs_statement(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);
    check_statement(node->filho->irmao, func_table, 0);

    if(strcmp(node->filho->irmao->anotar, "int") == 0){
        node->anotar = (char*)malloc(strlen("int") * sizeof(char) + 1);
        strcpy(node->anotar, "int");
    }else
    {
       node->anotar = (char*)malloc(strlen("int") * sizeof(char) + 1);
        strcpy(node->anotar, "int");
        printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->linha, node->coluna, node->filho->irmao->anotar, operation);
    }
    

}

void check_print_statement(AST_pointer node, table_pointer func_table, char* operation){
    check_statement(node->filho, func_table, 0);

    if(strcmp(node->filho->nome, "StrLit") == 0){
        return;
    }else if(strcmp(node->filho->anotar, "undef") == 0){
        /*node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");*/
        printf("Line %d, col %d: Incompatible type %s in %s statement\n", node->filho->filho->linha, node->filho->filho->coluna, node->filho->anotar, operation);
    }else
    {
        /*node->anotar = (char*)malloc(strlen(node->filho->anotar) * sizeof(char) + 1);
        strcpy(node->anotar, node->filho->anotar);*/
    }
    
}

void check_call_statement(AST_pointer node, table_pointer func_table, char* operation){
    //int nArgs;

    //Verificar variaveis dentro de Call
    AST_pointer temp = node->filho;
    while (temp != NULL){
        //printf("-----Nome:%s Valor:%s Linha:%d Coluna:%d-----\n", temp->nome, temp->valor, temp->linha, temp->coluna);
        check_statement(temp, func_table, 1);
        temp = temp->irmao;
    }

    //funcao nao esta definida
    if(strcmp(node->filho->return_id, "undef") == 0){
        node->anotar = (char*)malloc(strlen("undef") * sizeof(char) + 1);
        strcpy(node->anotar, "undef");
    }//esta definida
    else{
        //fiz isto no exists

        //contar numero de args para ver se sao iguais
        //contar a ver se os parametros sao iguais
        //printf("ciouwjcui :%s\n", node->filho->anotar);
        node->anotar = (char*)malloc(strlen(node->filho->return_id) * sizeof(char) + 1);
        strcpy(node->anotar, node->filho->return_id);
        if(strcmp(node->filho->return_id, "void")==0){
            strcpy(node->filho->return_id, "");
        }
    }

}

void check_return_statement(AST_pointer node, table_pointer func_table, int returns_something){
    if(returns_something == 1){
        check_statement(node->filho, func_table, 0);
        //printf("\n%s - %s\n", func_table->next_sym->tipo,node->filho->anotar );
    
        if(strcmp(node->filho->anotar, func_table->next_sym->tipo) != 0){
            printf("Line %d, col %d: Incompatible type %s in return statement\n", node->filho->linha, node->filho->coluna,node->filho->anotar);
        }
    }
}

//Verificar declaracao de variavel
table_pointer check_vardec(AST_pointer node, table_pointer table){
    AST_pointer temp = node->filho;

    
    while (temp != NULL){
        symbol_pointer new_symbol = create_symbol(temp->irmao->valor, id_to_type(temp->nome), 0, 0,0,NULL);
        if(symbol_exists(table, temp->irmao->valor, 0, node) == NULL){
            //printf("%s\n", new_symbol->nome);
            put_symbol(table, new_symbol);
        }else{
            printf("Line %d, col %d: Symbol %s already defined\n", temp->irmao->linha, temp->irmao->coluna, temp->irmao->valor);
        }
        
        temp = temp->irmao->irmao;
    }
    
    return table;
}

char* id_to_type(char *id){
    if(strcmp(id, "StringArray") == 0){
        return "String[]";
    }else if(strcmp(id, "DecLit") == 0 || strcmp(id, "Int") == 0){
        return "int";
    }else if(strcmp(id, "BoolLit") == 0){
        return "bool";
    }else if(strcmp(id, "Bool") == 0){
        return "boolean";
    }else if(strcmp(id, "Void") == 0){
        return "void";
    }else if(strcmp(id, "Double") == 0 || strcmp(id, "Realit") == 0){
        return "double";
    }

    return id;
}