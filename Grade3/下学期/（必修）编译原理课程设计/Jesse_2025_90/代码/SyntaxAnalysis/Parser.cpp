// Parser.cpp
#include "Parser.h"
#include <stdexcept>
#include <string>
using namespace std;

Parser::Parser(Scanner *scanner)
    : scanner(scanner)
{
    token = scanner->getToken(cur_index); // 初始化前瞻 token
}

void Parser::parse()
{
    program();
}
// 匹配对应tid并前进
void Parser::match(int expected_tid)
{
    if (token.tid == expected_tid)
    {
        advance();
    }
    else
    {
        throw runtime_error("Syntax error: expected token " + to_string(expected_tid) +
                            ", got " + to_string(token.tid));
    }
}
// 前进,处理cur_token和cur_index
void Parser::advance()
{
    cur_index++;
    token = scanner->getToken(cur_index);
    cout<<token.lexeme<<" "<<token.tid<<endl;
}
// 语法分析
AstNode *Parser::program()
{
    auto *prog = new ProgramNode();
    astRoot = prog;

    while (token.tid == TID_TYPE_INT ||
           token.tid == TID_TYPE_STRING ||
           token.tid == TID_TYPE_VOID)
    {
        prog->declarations.push_back(declaration());
    }

    match(TID_EOF);
    return prog;
}
// 声明语句(函数声明与变量声明)
AstNode *Parser::declaration()
{
    AstNode *type = typeSpecifier(); // 返回 TypeNode
    std::string name = token.lexeme;
    match(TID_ID);
    if (token.tid == TID_LP)
    {
        auto *func = new FunctionDeclNode();
        // 函数声明
        advance(); // skip '('
        //解析参数列表 params()
        while(token.tid != TID_RP){
            auto *varDecl = new VarDeclNode();
            varDecl->type = typeDeclaration();
            varDecl->name = token.lexeme;
            match(TID_ID);
            func->params.push_back(varDecl);
            if(token.tid == TID_COMMA){
                match(TID_COMMA);
            }
        }
        match(TID_RP);
        AstNode *body = compoundStmt();
        func->type = type;
        func->name = name;
        func->body = body;
        return func;
    }
    else
    {
        // 变量声明
        AstNode *initValue = nullptr;
        if (token.tid == TID_OP_ASSIGN)
        {
            match(TID_OP_ASSIGN);
            initValue = expression();
        }
        match(TID_SEMICELON);

        auto *var = new VarDeclNode();
        var->type = type;
        var->name = name;
        var->initValue = initValue;
        return var;
    }
}

AstNode *Parser::typeSpecifier()
{
    if (token.tid == TID_TYPE_INT ||
        token.tid == TID_TYPE_STRING ||
        token.tid == TID_TYPE_VOID)
    {
        auto *typeNode = new TypeNode();
        typeNode->typeId = token.tid;
        advance();
        return typeNode;
    }
    else
    {
        throw runtime_error("Expected a type specifier");
    }
}

AstNode *Parser::typeDeclaration(){
    if (token.tid == TID_TYPE_INT ||
        token.tid == TID_TYPE_STRING)
    {
        auto *typeNode = new TypeNode();
        typeNode->typeId = token.tid;
        advance();
        return typeNode;
    }
    else
    {
        throw runtime_error("Expected a type declaration");
    }
}
//代码块
AstNode *Parser::compoundStmt()
{
    match(TID_LBRACE);
    AstNode *decls = localDeclarations();
    AstNode *stmts = statementList();
    match(TID_RBRACE);

    auto *block = dynamic_cast<BlockNode *>(decls);
    if (stmts != nullptr)
    {
        auto *stmtBlock = dynamic_cast<BlockNode *>(stmts);
        if (stmtBlock)
        {
            block->statements.insert(block->statements.end(),
                                     stmtBlock->statements.begin(),
                                     stmtBlock->statements.end());
        }
    }

    return block;
}
//变量声明
AstNode *Parser::localDeclarations()
{
    auto *block = new BlockNode();

    while (token.tid == TID_TYPE_INT || token.tid == TID_TYPE_STRING)
    {
        block->statements.push_back(declaration());
    }

    return block;
}
//多行语句声明
AstNode *Parser::statementList()
{
    auto *block = new BlockNode();

    while (token.tid != TID_RBRACE && token.tid != TID_EOF)
    {
        block->statements.push_back(statement());
    }

    return block;
}
// 语句声明
AstNode *Parser::statement()
{
    if (token.tid == TID_TYPE_INT ||
        token.tid == TID_TYPE_STRING)
    {
        return declaration(); // 处理变量声明语句
    }
    switch (token.tid)
    {
    case TID_IF:
        return ifStmt();
    case TID_WHILE:
        return whileStmt();
    case TID_RETURN:
        return returnStmt();
    default:
        return expressionStmt();
    }
}
// 表达式语句声明
AstNode *Parser::expressionStmt()
{
    auto *node = new ExpressionStmtNode();
    if (token.tid != TID_SEMICELON)
    {
        node->expr = expression();
    }
    match(TID_SEMICELON);
    return node;
}

AstNode *Parser::ifStmt()
{
    match(TID_IF);
    match(TID_LP);
    AstNode *cond = expression();
    match(TID_RP);
    AstNode *thenBranch = compoundStmt(); // 使用 compoundStmt 解析整个块

    AstNode *elseBranch = nullptr;
    if (token.tid == TID_ELSE)
    {
        match(TID_ELSE);
        elseBranch = compoundStmt();
    }

    auto *node = new IfStmtNode();
    node->condition = cond;
    node->thenBranch = thenBranch;
    node->elseBranch = elseBranch;
    return node;
}

AstNode *Parser::whileStmt()
{
    match(TID_WHILE);
    match(TID_LP);
    AstNode *cond = expression();
    match(TID_RP);

    AstNode *body = compoundStmt(); //compoundStmt 解析整个块

    auto *node = new WhileStmtNode();
    node->condition = cond;
    node->body = body;
    return node;
}

AstNode *Parser::returnStmt()
{
    match(TID_RETURN);
    AstNode *value = nullptr;
    if (token.tid != TID_SEMICELON)
    {
        value = expression();
    }
    match(TID_SEMICELON);

    auto *node = new ReturnStmtNode();
    node->returnValue = value;
    return node;
}
//运算符表达式识别
AstNode *Parser::expression()
{
    return assignmentExpr();
}

AstNode *Parser::assignmentExpr()
{
    AstNode *left = logicalOrExpr();

    if (token.tid == TID_OP_ASSIGN)
    {
        match(TID_OP_ASSIGN);
        AstNode *right = assignmentExpr();

        auto *assign = new AssignNode();
        assign->varName = dynamic_cast<IdNode *>(left)->name;
        assign->expr = right;
        return assign;
    }

    return left;
}

AstNode *Parser::logicalOrExpr()
{
    AstNode *left = logicalAndExpr();

    while (token.tid == TID_OP_OR)
    {
        int op = token.tid;
        advance();
        AstNode *right = logicalAndExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::logicalAndExpr()
{
    AstNode *left = equalityExpr();

    while (token.tid == TID_OP_AND)
    {
        int op = token.tid;
        advance();
        AstNode *right = equalityExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::equalityExpr()
{
    AstNode *left = relationalExpr();

    while (token.tid == TID_OP_EQUAL || token.tid == TID_OP_NEQUAL)
    {
        int op = token.tid;
        advance();
        AstNode *right = relationalExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::relationalExpr()
{
    AstNode *left = additiveExpr();

    while (token.tid == TID_OP_LESS || token.tid == TID_OP_LESSEQ ||
           token.tid == TID_OP_GREATER || token.tid == TID_OP_GREATEREQ)
    {
        int op = token.tid;
        advance();
        AstNode *right = additiveExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::additiveExpr()
{
    AstNode *left = multiplicativeExpr();

    while (token.tid == TID_OP_ADD || token.tid == TID_OP_SUB)
    {
        int op = token.tid;
        advance();
        AstNode *right = multiplicativeExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::multiplicativeExpr()
{
    AstNode *left = unaryExpr();

    while (token.tid == TID_OP_MUL || token.tid == TID_OP_DIV || token.tid == TID_OP_MOD)
    {
        int op = token.tid;
        advance();
        AstNode *right = unaryExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = left;
        binOp->right = right;
        left = binOp;
    }

    return left;
}

AstNode *Parser::unaryExpr()
{
    if (token.tid == TID_OP_NOT ||
        token.tid == TID_OP_INC ||
        token.tid == TID_OP_DEC)
    {
        int op = token.tid;
        advance();
        AstNode *expr = unaryExpr();

        auto *binOp = new BinaryOpNode();
        binOp->op = op;
        binOp->left = nullptr; // 一元操作符没有左操作数
        binOp->right = expr;
        return binOp;
    }
    else
    {
        return primaryExpr();
    }
}

AstNode *Parser::primaryExpr()
{
    switch (token.tid)
    {
    case TID_ID:
    {
        std::string idName = token.lexeme;
        advance();
        // 检查是否是函数调用
        if (token.tid == TID_LP)
        {
            auto *call = new CallNode();
            call->funcName = idName;
            advance(); // skip '('

            while (token.tid != TID_RP)
            {
                call->args.push_back(expression());

                if (token.tid == TID_COMMA)
                {
                    match(TID_COMMA);
                }
            }

            match(TID_RP);
            return call;
        }

        // 否则就是普通变量名
        auto *id = new IdNode();
        id->name = idName;
        return id;
    }

    case TID_INT:
    case TID_STRING:
    {
        auto *lit = new LiteralNode();
        lit->type = token.tid;
        lit->value = token.lexeme;
        advance();
        return lit;
    }

    case TID_LP:
    {
        advance(); // skip '('
        AstNode *expr = expression();
        match(TID_RP);
        return expr;
    }

    default:
        throw runtime_error("Unexpected token in primary expression");
    }
}