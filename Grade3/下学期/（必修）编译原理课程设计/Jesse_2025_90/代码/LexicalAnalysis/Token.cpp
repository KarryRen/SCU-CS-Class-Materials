// Token.cpp
#include "Token.h"
#include "Lexemes.h"
#include <string>
#include <map>
using namespace std;
//build map between token id and according token string
map<string, Token> setupBuildinTokens() {
    map<string, Token> tokens;
    Lexemes lexemes;
    for (int i = 0; i < lexemes.getLexemesLen(); ++i) {
        Token token((TokenID)i, lexemes.getLexeme(i));
        tokens[lexemes.getLexeme(i)] = token;
    }
    return tokens; 
}
//find token using c_str from part of test file
Token* getBuildinToken(const string &lexeme) {
    static map<string, Token> s_tokens(setupBuildinTokens());
    map<string, Token>::iterator iter = s_tokens.find(lexeme);
    return iter == s_tokens.end() ? NULL : &iter->second;
}