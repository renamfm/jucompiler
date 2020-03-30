#ifndef STRUCTURES_H
#define STRUCTURES_H

/*
typedef struct integer{
    char *id;
}Integer;

typedef struct _double{
    char *id;
}Double;

typedef struct _bolean{
        char* id;
}Bool;

typedef struct _string{
        char* id;
}String;

typedef struct _strlit{
        char* strlit;
}Strlit;

typedef enum{Intlit, Reallit, Boolit, Id}lit_type;
typedef struct _someLit{
        lit_type type;
        char *id;
}

typedef struct _operation1{
    int t;
    struct expr* operation;
}Operador_1;

typedef enum{Plus, Minus, Star, Div, Mod, And, Or, Xor, Lshift, Rshift, Eq, Ge, Gt, Le, Lt, Ne }op_type;
typedef struct _operation2{
        op_type type;
        struct expr* operation1;
        struct expr* operation2;
}Operation2;

typedef struct expr{
        //
}Expr;

typedef struct assignStat{
        char* id;
        Expr* expr;
}Assign;

typedef struct parseArgsStat{
        char* id;
        Expr* expr;
}ParseArgs;

typedef enum{is_exp, is_strlit} print_type;
typedef struct callStat{
        print_type type;
        union{
                Expr* exp;
                Strlit* strlit;
        }type;
}Print;

typedef struct callStat{
        char* id;
        Expr* expr;
        Expr* next; //call?
}Call;

typedef struct returnStat{
        Expr* expr;
}Return;

typedef struct whileStat{
        Expr* expr;
        //ver se statements devem ser block
        struct statement* stat;
}While;

typedef struct ifStat{
        Expr* expr;
        //ver se statements devem ser block
        struct statement* stat;
        struct statement* ElseStat;
}If;

//voltar a ver este
typedef struct block{
        int n_statements //contar no. statements
        //?
}Block;

//Statement---Statement esta mal ha mais repetiçoes
typedef enum{is_block, is_if, is_while, is_return, is_assign, is_methodInv, is_parseArgs, is_print} statement_type;
typedef struct statement{
        statement_type type;
        union{  
                Block* block;
                If* ifStat;
                While* whileStat;
                Return* returnStat;
                Call* callStat;
                Print* printStat;
                ParseArgs* parseArgsStat;
                Assign* assignStat;                
        }stat;
}Statement;

//Vardec
typedef struct _vardcl{
        CommaID* commaID;
}VarDecl;

//StatementOrVardec
typedef enum{is_statement, is_vardec}st_or_vadec_type;
typedef struct statement_or_vadec{
        st_or_vadec_type type;
        union{
                Statement* statement;
                VarDecl* vardec;
        }stOrVd;
        struct statement_or_vadec *next;
}StatementOrVardec;

//ComaTypeID
typedef struct comma_type_id{
        int type;
        struct comma_type_id* next;
}CommaTypeID;

//CommaID
typedef struct comma_id{
        struct comma_id* next;
}CommaID;

//MethodBody
typedef struct method_body{
        StatementOrVardec* stOrVardec;
}MethodBody;

//Formal Params
typedef struct formal_params{
        int type;
        CommaTypeID* commaTypeId;
}FormalParams;


//MethodHeader
typedef enum{is_FormalOnly, is_FormalAndType} method_header_type;

typedef struct formal_and_type{
        int type;
        FormalParams* formalParams;
}FormalAndType;

typedef struct method_header{
        method_header_type type;
        union{
                FormalAndType* formalnType;
                FormalParams* formalParams;
        }mhs;
}MethodHeader;

*/
//FieldDecl
typedef struct field_decl{
        /*
        int type;
        CommaID* commaID;
        */
}FieldDecl;

//MethodDecl
typedef struct method_decl{
        /*
        MethodHeader* header;
        MethodBody* body;
        */
}MethodDecl;

//Declaration
typedef enum {is_methodDecl, is_fieldDecl} dec_type;
typedef struct declaration{
        dec_type type;
        union{
                MethodDecl* methodDecl;
                FieldDecl* fieldDecl;
        }dec;
        struct declaration* next;
}Declaration;

//Program:
typedef struct program{
        char* id;
        Declaration* decList;
}Program;

#endif
