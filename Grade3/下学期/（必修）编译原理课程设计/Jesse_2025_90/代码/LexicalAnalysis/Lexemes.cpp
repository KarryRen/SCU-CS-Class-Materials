#include "Lexemes.h"
#include <vector>
#include <string>
using namespace std;
string Lexemes::getLexeme(int index) const
{
    return lexemes[index];
}

int Lexemes::getLexemesLen() const
{
    return lexemes.size();
}