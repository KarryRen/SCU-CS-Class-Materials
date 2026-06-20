#include "AstNode.h"
#include <iostream>
using std::cout;
using std::string;
void printAst(AstNode *node, int indent = 0)
{
    if (!node)
        return;

    string prefix(indent, ' ');

    switch (node->getType())
    {
    case NODE_PROGRAM:
    {
        cout << prefix << "Program\n";
        for (auto *decl : static_cast<ProgramNode *>(node)->declarations)
        {
            printAst(decl, indent + 2);
        }
        break;
    }

    case NODE_VAR_DECL:
    {
        auto *varDecl = static_cast<VarDeclNode *>(node);
        cout << prefix << "VarDecl: " << varDecl->name << "\n";
        if (varDecl->initValue)
            printAst(varDecl->initValue, indent + 2);
        break;
    }

    case NODE_FUNCTION_DECL:
    {
        auto *func = static_cast<FunctionDeclNode *>(node);
        cout << prefix << "FunctionDecl: " << func->name << "\n";
        for (auto *param : func->params)
        {
            printAst(param, indent + 2);
        }
        printAst(func->body, indent + 2);
        break;
    }

    case NODE_ASSIGN:
    {
        auto *assign = static_cast<AssignNode *>(node);
        cout << prefix << "Assign: " << assign->varName << "\n";
        printAst(assign->expr, indent + 2);
        break;
    }

    case NODE_ID:
    {
        auto *id = static_cast<IdNode *>(node);
        cout << prefix << "ID: " << id->name << "\n";
        break;
    }

    case NODE_LITERAL:
    {
        auto *lit = static_cast<LiteralNode *>(node);
        cout << prefix << "Literal: " << lit->value << "\n";
        break;
    }

    case NODE_IF:
    {
        auto *ifStmt = static_cast<IfStmtNode *>(node);
        cout << prefix << "IfStmt\n";
        printAst(ifStmt->condition, indent + 2);
        printAst(ifStmt->thenBranch, indent + 2);
        if (ifStmt->elseBranch)
            printAst(ifStmt->elseBranch, indent + 2);
        break;
    }

    case NODE_WHILE:
    {
        auto *whileStmt = static_cast<WhileStmtNode *>(node);
        cout << prefix << "WhileStmt\n";
        printAst(whileStmt->condition, indent + 2);
        printAst(whileStmt->body, indent + 2);
        break;
    }

    case NODE_RETURN:
    {
        auto *ret = static_cast<ReturnStmtNode *>(node);
        cout << prefix << "Return\n";
        if (ret->returnValue)
            printAst(ret->returnValue, indent + 2);
        break;
    }

    case NODE_BINARY_OP:
    {
        auto *binOp = static_cast<BinaryOpNode *>(node);
        cout << prefix << "BinaryOp: " << binOp->op << "\n";
        printAst(binOp->left, indent + 2);
        printAst(binOp->right, indent + 2);
        break;
    }

    case NODE_UNARY_OP:
    {
        auto *unOp = static_cast<UnaryOpNode *>(node);
        cout << prefix << "UnaryOp: " << unOp->op << "\n";
        printAst(unOp->operand, indent + 2);
        break;
    }

    case NODE_EXPRESSION_STMT:
    {
        auto *exprStmt = static_cast<ExpressionStmtNode *>(node);
        cout << prefix << "ExpressionStmt\n";
        if (exprStmt->expr)
            printAst(exprStmt->expr, indent + 2);
        break;
    }

    case NODE_BLOCK:
    {
        auto *block = static_cast<BlockNode *>(node);
        cout << prefix << "Block\n";
        for (auto *stmt : block->statements)
        {
            printAst(stmt, indent + 2);
        }
        break;
    }

    case NODE_CALL:
    {
        auto *call = static_cast<CallNode *>(node);
        cout << prefix << "Call: " << call->funcName << "\n";
        for (auto *arg : call->args)
        {
            printAst(arg, indent + 2);
        }
        break;
    }

    default:
        cout << prefix << "Unknown node type\n";
    }
}