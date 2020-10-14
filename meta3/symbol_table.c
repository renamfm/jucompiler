#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "symbol_table.h"
#define MAX 100

/* Versao Totalmente Final */
/* ======================================== Table Related ======================================== */
//cria uma nova tabela tendo como parametro o nome da mesma
table_pointer create_table(char* nome){
    table_pointer temp = (table_pointer)malloc(sizeof(Table));
    temp->nome = (char*)malloc(strlen(nome)*sizeof(char)+1);
    strcpy(temp->nome, nome);
    temp->next_sym = NULL;
    temp->last_added = NULL;
    temp->next = NULL;
    temp->last_table = NULL;
    return temp;
}

void put_table(table_pointer global, table_pointer new){
    
    if (global->next == NULL){
        global->next = new;
        global->last_table = new;
    } else {
            global->last_table->next = new;
            global->last_table = new;       
    }
}


void show_table(table_pointer table){
    if(table == NULL){ return; }

    symbol_pointer temp = table->next_sym;
    printf("===== %s Symbol Table =====\n", table->nome);
        
    while(temp != NULL){
        //Estava a ser dificil nao imprimir underscores na tabela mas imprimir o seu tipo no header
        if(strcmp(temp->nome, "_")!=0){
            printf("%s\t", temp->nome);

            //Se a primeira palavra no nome for class e porque e a tabela global e as funçoes
            //desta precisam de parenteses
            if(strcmp(strtok(table->nome, " "), "Class")==0){
                if(temp->data_type == 1){printf("(");}
                
                if(temp->params != NULL){
                    printf("%s", temp->params->tipo);
                    param_pointer aux = temp->params->next;
                    while (aux != NULL){
                        printf(",%s", aux->tipo);
                        aux = aux->next;
                    }
                }

                if(temp->data_type == 1){printf(")");}
            }
            
            printf("\t");

            printf("%s", temp->tipo);
                
            if(temp->data_type == 2){
                printf("\tparam");
            }
                
            printf("\n");
        }
        temp = temp->next;
            
    }

    printf("\n");
    show_table(table->next);
}

/* ======================================== Symbol Related ======================================== */
//criar um novo simbolo
symbol_pointer create_symbol(char* nome, char* tipo, int linha, int coluna, int data_type, param_pointer params){
    symbol_pointer temp = (symbol_pointer)malloc(sizeof(Symbol));
    temp->nome = (char*)malloc(strlen(nome)*sizeof(char)+1);
    strcpy(temp->nome, nome);
    temp->tipo = (char*)malloc(strlen(tipo)*sizeof(char)+1);
    strcpy(temp->tipo, tipo);
    temp->data_type = data_type;
    temp->line = linha;
    temp->col = coluna;

    temp->next = NULL;
    return temp;
}

//adiciona simbolo
void put_symbol(table_pointer table, symbol_pointer symbol){
    if (table->next_sym == NULL){
        table->next_sym = symbol;
        table->last_added = symbol;
    } else {
        table->last_added->next = symbol;
        table->last_added = symbol;       
    }
}


symbol_pointer function_repetition(table_pointer table, char* symbol_name, int is_Call, AST_pointer node){
    symbol_pointer temp = table->next_sym;
    symbol_pointer temp2 = NULL;
    //int flag = 1;
    while(temp != NULL){
        int flag = 1;
        //int flag2 = 1;
        //printf("lets see:%s-%s-%d\n", temp->nome,symbol_name, is_Call);
        //printf("ff:%d\n",strcmp(temp->nome, symbol_name) == 0);  
        if(strcmp(temp->nome, symbol_name) == 0){
                //printf("222");
                int funcParams = 0;
                int nodeBrothers = 0;
            
               param_pointer aux = temp->params;
                while (aux != NULL){funcParams++;aux=aux->next;}
            
                AST_pointer aux2 = node->irmao->filho;
                while (aux2 != NULL){nodeBrothers++;aux2=aux2->irmao;}


                 if(funcParams == nodeBrothers && funcParams > 0 && nodeBrothers > 0){
                    

                        param_pointer aux5 = temp->params;
                        if(node->irmao->filho != NULL){
                            if(node->irmao->filho->filho != NULL){
                                
                            AST_pointer aux4 =  node->irmao->filho;

                            //printf("CHEKING %s-%s",aux5->tipo,id_to_type(aux4->nome));
                            while (aux5 != NULL && aux4->filho != NULL){
                                //printf("ff: %s-%s-%d\n",aux5->tipo, id_to_type(aux4->filho->nome), strcmp(aux5->tipo, id_to_type(aux4->filho->nome)) != 0);
                                if(strcmp(aux5->tipo, id_to_type(aux4->filho->nome)) != 0){
                                    flag = 0;
                                }
                               
                                aux5 = aux5->next;
                                aux4 = aux4->irmao;    
                            }
                            if(flag == 1){
                                temp2 = temp;
                                break;
                            }
                            }
                        }
                
                }else if(funcParams == 0 && nodeBrothers ==0){
                    return temp;
            }
        }
        temp = temp->next;
    }

    return temp2;
}

void put_param(symbol_pointer symbol, param_pointer param){
    if(symbol->params == NULL){
        symbol->params = param;
        symbol->params->last_added = param;
    }else
    {
        symbol->params->last_added->next = param;
        symbol->params->last_added = param;
    }  
}

symbol_pointer get_symbol(table_pointer table, char* symbol_name, int is_Call, AST_pointer node){
    symbol_pointer temp = table->next_sym;
    //printf("\nfdz: %s-%d\n", symbol_name, is_Call == 1);


    while(temp != NULL){
        int flag = 1;
        
        if(strcmp(temp->nome, symbol_name) == 0){
            if(is_Call == 1){
                int funcParams = 0;
                int nodeBrothers = 0;
            
                param_pointer aux = temp->params;
                while (aux != NULL){funcParams++;aux=aux->next;}
            
                AST_pointer aux2 = node->irmao;
                while (aux2 != NULL){nodeBrothers++;aux2=aux2->irmao;}


                if(funcParams == nodeBrothers && funcParams > 0 && nodeBrothers > 0){
                    
                        
                        param_pointer aux5 = temp->params;
                        AST_pointer aux4 =  node->irmao;

                        
                        while (aux5 != NULL || aux4 != NULL){
                            if(strcmp(aux5->tipo, aux4->anotar) != 0){
                                flag = 0;
                            }
                            aux5 = aux5->next;
                            aux4 = aux4->irmao;
                        }
                        
                        if(flag == 1){
                            

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
                            node->anotar = (char*)malloc(strlen(declarations) * sizeof(char)+1);
                            strcpy(node->anotar, declarations); 

                            return temp;
                        }
                
                }else if(funcParams == 0 && nodeBrothers ==0){
                    node->anotar = (char*)malloc(strlen("") * sizeof(char)+1);
            strcpy(node->anotar, "");
                    return temp;
                }

            }else{
                if(temp->data_type != 1)
                return temp;
                //printf("\ngande fidodio: %d-%d\n", 6, 6);
            }
        }
        
        temp = temp->next;
    }

     
     
  symbol_pointer temp5 = NULL;
   int t2 = 1;
    temp = table->next_sym;
    
    while(temp != NULL){
        int flag2 = 1;

        if(strcmp(temp->nome, symbol_name) == 0){
            if(is_Call == 1){
                int funcParams = 0;
                int nodeBrothers = 0;
            
                param_pointer aux = temp->params;
                while (aux != NULL){funcParams++;aux=aux->next;}
            
                AST_pointer aux2 = node->irmao;
                while (aux2 != NULL){nodeBrothers++;aux2=aux2->irmao;}


                if(funcParams == nodeBrothers && funcParams > 0 && nodeBrothers > 0){

                        
                       param_pointer aux5 = temp->params;
                        AST_pointer aux4 =  node->irmao;

                                                         
                            while (aux5 != NULL || aux4 != NULL){
                                if(!(strcmp(aux5->tipo, aux4->anotar)==0 || (strcmp(aux5->tipo, "int") == 0 && strcmp(aux4->anotar, "double") == 0))){
                                flag2 = 0; 
                               }
                         
                                aux5 = aux5->next;
                                aux4 = aux4->irmao;
                            }
                           if(flag2 == 1){

                            if(temp5 != NULL){
                               t2 = 0; 
                            }
                            temp5 = temp;
                        }                                                         
                }
            }
        }
        temp = temp->next;
    }

 
    if(is_Call ==1){
        if(t2 == 0){
            return create_symbol("ambiguous", "ambiguous", 0,0,0,NULL);
        }else if(temp5!=NULL && temp != NULL){
            char declarations[MAX];
            strcpy(declarations, "");
          
            param_pointer aux10 = temp->params;

            if(aux10 != NULL){
            strcat(declarations, aux10->tipo );
                aux10 = aux10->next;
            }
                            
            while(aux10 != NULL){
             strcat(declarations, ",");
                strcat(declarations, aux10->tipo );
                aux10 = aux10->next;
                                
                }
            node->anotar = (char*)malloc(strlen(declarations) * sizeof(char)+1);
            strcpy(node->anotar, declarations); 
            return temp5; 

        }
    }


  symbol_pointer temp2 = NULL;
  int t1 = 1;
  temp = table->next_sym;
   
    while(temp != NULL){
        int flag2 = 1;

       
        if(strcmp(temp->nome, symbol_name) == 0){
            
            if(is_Call == 1){
                int funcParams = 0;
                int nodeBrothers = 0;
            
                param_pointer aux = temp->params;
                while (aux != NULL){funcParams++;aux=aux->next;}
            
                AST_pointer aux2 = node->irmao;
                while (aux2 != NULL){nodeBrothers++;aux2=aux2->irmao;}

             
                if(funcParams == nodeBrothers && funcParams > 0 && nodeBrothers > 0){

                        
                       param_pointer aux5 = temp->params;
                        AST_pointer aux4 =  node->irmao;

                                                         
                            while (aux5 != NULL || aux4 != NULL){
                                if(!(strcmp(aux5->tipo, aux4->anotar)==0 || (strcmp(aux5->tipo, "double") == 0 && strcmp(aux4->anotar, "int") == 0))){
                                flag2 = 0; 
                               }
                         
                                aux5 = aux5->next;
                                aux4 = aux4->irmao;
                            }
                           if(flag2 == 1){

                            if(temp2 != NULL){
                               t1 = 0; 
                            }
                            temp2 = temp;
                        }                                                         
                }
            }
        }
        temp = temp->next;
    }
  
    if(is_Call ==1){
        if(t1 == 0){
            return create_symbol("ambiguous", "ambiguous", 0,0,0,NULL);
        }else if(temp2!=NULL && temp2 != NULL){
            char declarations[MAX];
            strcpy(declarations, "");
            param_pointer aux10 = temp2->params;


            if(aux10 != NULL){
                strcat(declarations, aux10->tipo );
                aux10 = aux10->next;
            }
                                
            while(aux10 != NULL){
            strcat(declarations, ",");
            strcat(declarations, aux10->tipo);
            aux10 = aux10->next;
                                    
            }
            node->anotar = (char*)malloc(strlen(declarations) * sizeof(char)+1);
            strcpy(node->anotar, declarations);
            return temp2; 

        }
    }
    
    return NULL;
}

symbol_pointer symbol_exists(table_pointer table, char* symbol_name, int is_Call, AST_pointer node){
    
    symbol_pointer aux = get_symbol(table, symbol_name,is_Call, node);
    if(aux != NULL){
        return aux;
    }else{
        
        return get_symbol(global_table, symbol_name,is_Call, node);
    }
    return NULL;
}


/* ======================================== Param Related ======================================== */
//criar novo parametro de funcao
param_pointer create_param(char* tipo, char* nome){
    param_pointer temp  = (param_pointer)malloc(sizeof(Param));
    temp->tipo = (char*)malloc(strlen(tipo)*sizeof(char)+1);
    strcpy(temp->tipo, tipo);
    temp->nome = (char*)malloc(strlen(nome)*sizeof(char)+1);
    strcpy(temp->nome, nome);
    
    temp->next = NULL;
    temp->last_added = NULL;
    return temp;
}
