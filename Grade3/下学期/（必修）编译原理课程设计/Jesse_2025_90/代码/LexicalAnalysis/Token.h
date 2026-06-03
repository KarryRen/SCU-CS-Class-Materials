// Token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

enum TokenID {
    TID_LP, TID_RP, TID_LBRACE, TID_RBRACE, TID_LBRACKET, TID_RBRACKET, TID_COMMA, TID_SEMICELON,
    TID_IF, TID_ELSE, TID_FOR, TID_WHILE, TID_CONTINUE, TID_BREAK, TID_RETURN,
    TID_OP_NOT, TID_OP_INC, TID_OP_DEC,
    TID_OP_ASSIGN,
    TID_OP_AND, TID_OP_OR,
    TID_OP_ADD, TID_OP_SUB, TID_OP_MUL, TID_OP_DIV, TID_OP_MOD,   
    TID_OP_LESS, TID_OP_LESSEQ, TID_OP_GREATER, TID_OP_GREATEREQ, TID_OP_EQUAL, TID_OP_NEQUAL, 
    TID_TYPE_INT, TID_TYPE_STRING, TID_TYPE_VOID,
    TID_TRUE, TID_FALSE,
    // special 
    TID_INT, TID_ID, TID_STRING,
    TID_EOF,
};

struct Token {
    TokenID tid;
    std::string lexeme;
    Token(): tid(TID_EOF) {}
    explicit Token(TokenID _tt): tid(_tt) {}
    Token(TokenID _tt, const char *begin, const char *end) : tid(_tt), lexeme(begin,end) {}
    Token(TokenID _tt, std::string lexeme): tid(_tt), lexeme(lexeme){}
};

extern std::map<std::string, Token> setupBuildinTokens();
extern Token* getBuildinToken(const std::string &lexeme);

#endif // TOKEN_H