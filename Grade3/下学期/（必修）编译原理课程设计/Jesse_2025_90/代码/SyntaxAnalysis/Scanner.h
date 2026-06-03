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
    Token next(); // 返回下一个Token
    Token getToken(int n); //开放接口以便后续语法分析器Parser调用
    private : 
    void fetch(); //扫描储存下一个char对应的token

private:
    std::vector<Token> m_LAList; //识别到的Token列表
    const char *m_src; //识别用到的指针
};

#endif // SCANNER_H