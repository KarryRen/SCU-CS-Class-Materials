// Parser.h
#ifndef PARSER_H
#define PARSER_H
#include "Scanner.h"
#include "Token.h"
#include "AstNode.h"
class Parser
{
public:
    Parser(Scanner *scanner); //根据之前的Scanner初始化
    void parse(); // 语法分析接口函数
    AstNode *getAstRoot() { return astRoot; } // 获取 AST 根节点

private:
    Scanner *scanner;
    Token token; // 当前token
    int cur_index = 0; //构建指针

    AstNode *astRoot = nullptr; //语法树根节点

    void advance(); //获取下一个token
    void match(int expected_tid); //匹配当前token

    // 声明与语句
    AstNode *program();
    AstNode *declarationList();
    AstNode *declaration();
    AstNode *typeSpecifier();
    AstNode *typeDeclaration();
    AstNode *compoundStmt();
    AstNode *localDeclarations();
    AstNode *statementList();
    AstNode *statement();

    // 表达式相关
    AstNode *expressionStmt();
    AstNode *ifStmt();
    AstNode *whileStmt();
    AstNode *returnStmt();
    AstNode *expression();
    AstNode *assignmentExpr();
    AstNode *logicalOrExpr();
    AstNode *logicalAndExpr();
    AstNode *equalityExpr();
    AstNode *relationalExpr();
    AstNode *additiveExpr();
    AstNode *multiplicativeExpr();
    AstNode *unaryExpr();
    AstNode *primaryExpr();
};
#endif //PARSER_H
