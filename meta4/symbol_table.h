#include <stdio.h>
#include <stdlib.h>

//Temos de fazer uma tabela para as variaveis globais e outro
//para as variaveis locais (de cada funcao)

//Tipo de parametros
typedef struct _param* param_pointer;
typedef struct _param{
    char *tipo;
    char *nome;
    param_pointer next;
    param_pointer last_added;
}Param;

//Simbolo
typedef struct _symbol* symbol_pointer;
typedef struct _symbol{
    char* nome;
    char* tipo;
    int line, col;
    int data_type;  //0 - VAR, 1 - function, 2,- param ? 
    param_pointer params;
    symbol_pointer next;
}Symbol;

//Tabela com nome para definir o tipo
typedef struct _table * table_pointer;
typedef struct _table{
    char* nome;
    symbol_pointer next_sym;
    symbol_pointer last_added;
    table_pointer next;
    table_pointer last_table;
}Table;


//Primeiro temos de comecar pelas tabelas de simbolos (valem mais pontos)
table_pointer create_table(char* nome);
void put_table(table_pointer global, table_pointer new);
void show_table(table_pointer table);
symbol_pointer create_symbol(char* nome, char* tipo, int linha, int coluna, int data_type, param_pointer params);
void put_symbol(table_pointer table, symbol_pointer symbol);
symbol_pointer get_symbol(table_pointer table, char* symbol_name, int is_Call, AST_pointer node);
symbol_pointer symbol_exists(table_pointer table, char* symbol_name, int is_Call, AST_pointer node);
param_pointer create_param(char* tipo, char* nome);
void put_param(symbol_pointer symbol, param_pointer param);
symbol_pointer function_repetition(table_pointer table, char* symbol_name, int is_Call, AST_pointer node);

table_pointer global_table; //definir o ponteiro aqui para nao ter delidar
//com ponteiro de ponteiro

//Por fim vamos tratar da semantica e erros
void check_tree(AST_pointer root);
void check_methoddecl(AST_pointer node, int first_search);
table_pointer check_func_params(AST_pointer node, symbol_pointer func_table, int first_search);
table_pointer check_vardec(AST_pointer node, table_pointer table);
void check_func_body(AST_pointer node, table_pointer func_table);
void check_statement(AST_pointer node, table_pointer func_table, int is_Call);
int exists(AST_pointer node, table_pointer func_table, int is_Call);
void check_numbers_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_logical_operation(AST_pointer node, table_pointer func_table, char* operation);
char* id_to_type(char *id);
void check_unary_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_unary_not_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_comparation_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_assign_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_parseArgs_statement(AST_pointer node, table_pointer func_table, char* operation);
void check_print_statement(AST_pointer node, table_pointer func_table, char* operation);
void check_call_statement(AST_pointer node, table_pointer func_table, char* operation);
void check_return_statement(AST_pointer node, table_pointer func_table, int returns_something);
void check_shift_operation(AST_pointer node, table_pointer func_table, char* operation);
void check_length_statement(AST_pointer node, table_pointer func_table, char* operation);
void check_if_statement(AST_pointer node, table_pointer func_table, char* operation);
int bits(long x);
char* retirarUnderscores(char* number);


//Header code_generator
void generator(AST_pointer root);
void method_gen(AST_pointer node);
void method_body_gen(AST_pointer node);
void main_method_gen(AST_pointer node);
char* llvm_types(char* type);