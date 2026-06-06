// Scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
#include "Token.h" // 假设Token定义在一个单独的头文件中

class Scanner
{
public:
    explicit Scanner(const char *src);
    Token LA(int n);
    Token next(int n);

private:
    void fetchN(int n);

private:
    std::vector<Token> m_LAList;
    const char *m_src;
};

#endif // SCANNER_H