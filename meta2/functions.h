#include "structures.h"

Program* create_program(char* id, Declaration* declist);
void print_program(Program* program);
Declaration* create_dec_method(Declaration* list, MethodDecl* methodDecl);
Declaration* create_dec_field(Declaration* list, FieldDecl* fieldDecl);
void print_declaration(Declaration* declaration);
MethodDecl* create_methodDecl();
FieldDecl* create_fieldDecl();


