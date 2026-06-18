// Lexemes.h
#ifndef LEXEMES_H
#define LEXEMES_H
#include <vector>
#include <string>
class Lexemes {
public:
    //define and init all identifiers in C-Minus
    Lexemes() : lexemes({
        "(", ")", "{", "}", "[", "]", ",", ";",
        "if", "else", "for", "while", "continue", "break", "return",
        "!", "++", "--",
        "=",
        "&&", "||",
        "+", "-", "*", "/", "%", 
        "<", "<=", ">", ">=", "==", "!=",
        "int", "string", "void",
        "true", "false",
    }) {}
    //return n-index lexeme
    std::string getLexeme(int index) const;
    //return length of lexemes
    int getLexemesLen() const;

private:
    std::vector<std::string> lexemes;
};
#endif // LEXEMES_