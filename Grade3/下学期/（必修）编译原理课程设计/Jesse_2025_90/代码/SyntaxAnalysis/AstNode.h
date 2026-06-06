// AstNode.h
#ifndef ASTNODE_H
#define ASTNODE_H
#include <string>
#include <vector>
#include <iostream>
#include "Token.h"
enum NodeType
{
    NODE_PROGRAM,
    NODE_DECLARATION,
    NODE_BLOCK,
    NODE_FUNCTION_DECL,
    NODE_VAR_DECL,
    NODE_TYPE,
    NODE_ID,
    NODE_ASSIGN,
    NODE_EXPRESSION_STMT,
    NODE_IF,
    NODE_WHILE,
    NODE_RETURN,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_LITERAL,
    NODE_CALL,
};
// 抽象语法树节点
struct AstNode
{
    virtual ~AstNode() = default;
    virtual NodeType getType() const = 0;
};
// 程序节点
struct ProgramNode : AstNode
{
    std::vector<AstNode *> declarations;
    NodeType getType() const override { return NODE_PROGRAM; }
};
// 代码块节点
//  表示代码块的 BlockNode
struct BlockNode : AstNode
{
    std::vector<AstNode *> statements;
    NodeType getType() const override { return NODE_BLOCK; }
};
// 声明节点
struct DeclarationNode : AstNode
{
    AstNode *type;
    std::string name;
    NodeType getType() const override { return NODE_DECLARATION; }
};
// 函数声明节点
struct FunctionDeclNode : DeclarationNode
{
    std::vector<AstNode *> params;
    AstNode *body;
    NodeType getType() const override { return NODE_FUNCTION_DECL; }
};
// 变量声明节点
struct VarDeclNode : DeclarationNode
{
    AstNode *initValue;
    NodeType getType() const override { return NODE_VAR_DECL; }
};
// 类型节点
struct TypeNode : AstNode
{
    int typeId; // TID_TYPE_INT 等
    NodeType getType() const override { return NODE_TYPE; }
};
// 标识符节点
struct IdNode : AstNode
{
    std::string name;
    NodeType getType() const override { return NODE_ID; }
};
// 赋值语句
struct AssignNode : AstNode
{
    std::string varName;
    AstNode *expr;
    NodeType getType() const override { return NODE_ASSIGN; }
};
//  表达式语句
struct ExpressionStmtNode : AstNode
{
    AstNode *expr;
    NodeType getType() const override { return NODE_EXPRESSION_STMT; }
};
// if 语句
struct IfStmtNode : AstNode
{
    AstNode *condition;
    AstNode *thenBranch;
    AstNode *elseBranch;
    NodeType getType() const override { return NODE_IF; }
};
// while 语句
struct WhileStmtNode : AstNode
{
    AstNode *condition;
    AstNode *body;
    NodeType getType() const override { return NODE_WHILE; }
};
// return 语句
struct ReturnStmtNode : AstNode
{
    AstNode *returnValue;
    NodeType getType() const override { return NODE_RETURN; }
};
// 二元运算符节点
struct BinaryOpNode : AstNode
{
    int op;
    AstNode *left;
    AstNode *right;
    NodeType getType() const override { return NODE_BINARY_OP; }
};
// 一元运算符节点
struct UnaryOpNode : AstNode
{
    int op;
    AstNode *operand;
    NodeType getType() const override { return NODE_UNARY_OP; }
};
//具体值节点
struct LiteralNode : AstNode
{
    int type; // TID_INT, TID_STRING 等
    std::string value;
    NodeType getType() const override { return NODE_LITERAL; }
};
//函数调用节点
struct CallNode : public AstNode
{
    std::string funcName;
    std::vector<AstNode *> args;

    NodeType getType() const override { return NODE_CALL; }
};
#endif // ASTNODE_H