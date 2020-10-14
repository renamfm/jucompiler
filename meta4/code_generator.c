#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "symbol_table.h"

int flagMain = 0;

void generator(AST_pointer root){
    //AST_pointer temp;
    if(root != NULL){
        if(strcmp(root->nome, "Program") == 0){
            printf("@.str.int = constant [3 x i8] c\"%%d\\00\"\n");
            printf("@.str.double = constant [6 x i8] c\"%%.16e\\00\"\n");
            printf("@.str.true = constant [5 x i8] c\"true\\00\"\n");
            printf("@.str.false = constant [6 x i8] c\"false\\00\"\n");
            printf("@.str.0 = constant [2 x i8] c\"\\0A\\00\"\n");
            method_gen(root->filho->irmao);
        }
    }
}

void method_gen(AST_pointer node){
    AST_pointer method = node;
    while(method != NULL){ 
        //gerar method_header
        AST_pointer header = method->filho;
        if(strcmp(header->filho->irmao->valor, "main")==0){
            flagMain = 1;
            main_method_gen(header);
        }
        else{
            printf("define %s @%s(", llvm_types(header->filho->nome), header->filho->irmao->valor); //tipo que retorna e nome
            AST_pointer arg = header->filho->irmao->irmao->filho;
            while(arg != NULL){
                printf("%s %%.%s", llvm_types(arg->filho->nome), arg->filho->irmao->valor);
                arg = arg->irmao;
            }
            printf("){\n");
            //gerar method_body
            method_body_gen(header->irmao);
            printf("}\n");
        }
        method = method->irmao;
    }
    if(flagMain == 0){
        printf("define i32 @main(i32 %%.size,i8** %%.args){\nret i32 0\n}\n");
    }
    printf("declare i32 @printf(i8*, ...)\n");
    printf("declare i32 @atoi(i8*)\n");
}

void method_body_gen(AST_pointer node){
    int varIndex = 1;
    AST_pointer temp = node->filho;
    while(temp != NULL){
        if(strcmp(temp->nome, "VarDecl") == 0){
        printf("%%%s = alloca %s\n", temp->filho->irmao->valor, llvm_types(temp->filho->nome));
        }
        else if(strcmp(temp->nome, "Assign") == 0){
            //Declaracao de INT ou DOUBLE
            if(strcmp(temp->filho->irmao->nome, "DecLit") == 0){
                printf("%%.%d = add i32 0, %s\n", varIndex, temp->filho->irmao->valor);
                //Apenas para DOUBLE
                if(strcmp(temp->filho->anotar, "double") == 0){
                    printf("%%.%d = sitofp i32 %%.%d to double\n", varIndex+1, varIndex);
                    varIndex += 1;
                }
                printf("store %s %%.%d, %s* %%%s\n", llvm_types(temp->filho->anotar), varIndex, llvm_types(temp->filho->anotar), temp->filho->valor);
                varIndex += 1;
            }
            else if(strcmp(temp->filho->irmao->nome, "RealLit") == 0){
                printf("%%.%d = fadd double 0.000000, %s\n", varIndex, temp->filho->irmao->valor);
                printf("store %s %%.%d, %s* %%%s\n", llvm_types(temp->filho->anotar), varIndex, llvm_types(temp->filho->anotar), temp->filho->valor);
                varIndex += 1;
            }
            //Declaracao BOOLEAN
            else if(strcmp(temp->filho->irmao->nome, "BoolLit") == 0){
                printf("%%.%d = or i1 false, true\n", varIndex);
                printf("store i1 %%.%d, i1* %%%s\n", varIndex, temp->filho->valor);
                varIndex += 1;
            }
            //ADICAO
            else if(strcmp(temp->filho->irmao->nome, "Add") == 0){
                printf("%%.%d = load %s, %s* %%%s\n", varIndex, llvm_types(temp->filho->irmao->filho->anotar), llvm_types(temp->filho->irmao->filho->anotar), temp->filho->irmao->filho->valor);
                varIndex += 1;
                printf("%%.%d = load %s, %s* %%%s\n", varIndex, llvm_types(temp->filho->irmao->filho->irmao->anotar), llvm_types(temp->filho->irmao->filho->irmao->anotar), temp->filho->irmao->filho->irmao->valor);    
                varIndex += 1;
                if(strcmp(temp->filho->irmao->filho->anotar, "double") == 0){
                    printf("%%.%d = sitofp i32 %%.%d to double\n", varIndex, varIndex-2);
                    varIndex += 1;
                }
                if(strcmp(temp->filho->irmao->filho->irmao->anotar, "double") == 0){
                    printf("%%.%d = sitofp i32 %%.%d to double\n", varIndex, varIndex-2);
                    varIndex += 1;
                }
                printf("%%.%d = fadd %s %%.%d, %%.%d\n", varIndex, temp->filho->irmao->anotar, varIndex-1, varIndex-2);
                varIndex +=1;
                printf("store double %%.%d, double* %%%s\n", varIndex-1, temp->filho->valor);
            }
            //DIVISAO
            else if(strcmp(temp->filho->irmao->nome, "Div") == 0){
                printf("%%.%d = load %s, %s* %%%s\n", varIndex, llvm_types(temp->filho->irmao->filho->anotar), llvm_types(temp->filho->irmao->filho->anotar), temp->filho->irmao->filho->valor);
                varIndex += 1;
                printf("%%.%d = load %s, %s* %%%s\n", varIndex, llvm_types(temp->filho->irmao->filho->irmao->anotar), llvm_types(temp->filho->irmao->filho->irmao->anotar), temp->filho->irmao->filho->irmao->valor);    
                varIndex += 1;
                if(strcmp(temp->filho->irmao->filho->anotar, "double") == 0){
                    printf("%%.%d = sitofp i32 %%.%d to double\n", varIndex, varIndex-2);
                    varIndex += 1;
                }
                if(strcmp(temp->filho->irmao->filho->irmao->anotar, "double") == 0){
                    printf("%%.%d = sitofp i32 %%.%d to double\n", varIndex, varIndex-2);
                    varIndex += 1;
                }
                printf("%%.%d = fdiv %s %%.%d, %%.%d\n", varIndex, temp->filho->irmao->anotar, varIndex-1, varIndex-2);
                varIndex +=1;
                printf("store double %%.%d, double* %%%s\n", varIndex-1, temp->filho->valor);
            }
        }
        //PRINT
        else if(strcmp(temp->nome, "Print") == 0){
            if(strcmp(temp->filho->anotar, "int") == 0){
                printf("%%.%d = load i32, i32* %%%s\n", varIndex, temp->filho->valor);
                varIndex += 1;
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %%.%d)\n", varIndex, varIndex-1);
                varIndex += 1;
            }
            else if(strcmp(temp->filho->anotar, "double") == 0){
                printf("%%.%d = load double, double* %%%s\\n", varIndex, temp->filho->valor);
                varIndex += 1;
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %%.%d)\n", varIndex, varIndex-1);
                varIndex += 1;
            }
            else if(strcmp(temp->filho->anotar, "boolean") == 0){
                printf("%%.%d = load i1, i1* %%%s\n", varIndex, temp->filho->valor);
                printf("br i1 %%.%d, label %%then1, label %%else1\n", varIndex);
                varIndex +=1;
                printf("then1:\n");
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))\n", varIndex);
                varIndex += 1;
                printf("br label %%ifCont1\n");
                printf("else1:\n");
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))\n", varIndex);
                varIndex += 1;
                printf("br label %%ifCont1\n");
                printf("ifCont1:\n");
                printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))\n", varIndex);
                varIndex += 1;
            }
            else if(strcmp(temp->filho->anotar, "String") == 0){
                if(strcmp(temp->filho->valor, "\\n") == 0){
                    printf("%%.%d = call i32 (i8*, ...) @printf(i8* getelementptr  ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))", varIndex);
                    varIndex += 1;
                }
            }
        }

        else if(strcmp(temp->nome, "Return") == 0){
            printf("%%.%d = load %s, %s* %%%s\n", varIndex, llvm_types(temp->filho->anotar), llvm_types(temp->filho->anotar), temp->filho->valor);
            printf("ret %s %%.%d\n", llvm_types(temp->filho->anotar), varIndex);
            if(strcmp(temp->filho->anotar, "double") == 0)
                printf("ret %s 0.0\n", llvm_types(temp->filho->anotar));
            else
                printf("ret %s 0\n", llvm_types(temp->filho->anotar));
            varIndex += 1;
        }
        else if(strcmp(temp->nome, "Call") == 0){
            printf("%%.%d = call %s @%s()\n", varIndex, llvm_types(temp->anotar), temp->filho->valor);
            varIndex += 1;
        }
        else if(strcmp(temp->nome, "If") == 0){
            //printf("É IF caramba!\n");
        }
        temp = temp->irmao;
    }
} 

void main_method_gen(AST_pointer node){
    printf("define void @main.entry(i32 %%.size.,i8** %%.args) {\n");
    
    //Esta hardcoded. Ver se e preciso ser de maneira diferente
    printf("%%size. = alloca i32\n");
    printf("store i32 %%.size., i32* %%size.\n");
    printf("%%args = alloca i8**\n");
    printf("store i8** %%.args, i8*** %%args\n");
    method_body_gen(node->irmao);
    printf("ret void\n");
    printf("}\n");

    printf("define i32 @main(i32 %%.size,i8** %%.args){\n");
    printf("call void @main.entry(i32 %%.size, i8** %%.args)\n");
    printf("ret i32 0\n");
    printf("}\n");

}

char* llvm_types(char* type){
    if(strcmp(type, "Bool")==0 || strcmp(type, "boolean")==0){
        return "i1";
    }
    else if(strcmp(type, "Int")==0 || strcmp(type, "int")==0){
        return "i32";
    }
    else if(strcmp(type, "Double")==0 || strcmp(type, "double")==0){
        return "double";
    }
    else if(strcmp(type, "Void")==0){
        return "void";
    }
    else if(strcmp(type, "StringArray")==0){
        //por ver
        return "i32 %.size,i8**";
    }
    else
        return "";
    

}