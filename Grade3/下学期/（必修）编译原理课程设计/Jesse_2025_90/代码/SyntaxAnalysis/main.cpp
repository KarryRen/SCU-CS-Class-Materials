//============================== head file
#include "pch.h"
#include "Token.h"
#include "Lexemes.h"
#include "Scanner.h"
#include "Parser.h"
#include "AstNode.h"
#include "AstPrint.h"
//============================== include file
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <set>
using namespace std;
//============================== define
#define _TO_STRING(e) #e
#define TO_STRING(e) _TO_STRING(e)
#define FILE_LINE __FILE__ "(" TO_STRING(__LINE__) ")"
#define ASSERT(b)                                                  \
    do                                                             \
    {                                                              \
        if (!(b))                                                  \
            throw logic_error(FILE_LINE " : assert failed ! " #b); \
    } while (0)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
//special implement for \x character
static string unescape(const string &s)
{
    string r;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == '\\')
        {
            switch (s[++i])
            {
            case 't':
                r += '\t';
                break;
            case 'n':
                r += '\n';
                break;
            case 'r':
                r += '\r';
                break;
            default:
                r += s[i];
                break;
            }
        }
        else
            r += s[i];
    }
    return r;
}
static string format(const char *fmt, ...)
{
    // handle variable argument list
    va_list args;
    va_start(args, fmt);
    static vector<char> buf(256);
    while ((int)buf.size() == vsnprintf(&buf[0], buf.size(), fmt, args))
    {
        buf.resize(buf.size() * 3 / 2);
    }
    va_end(args);
    //return c style string from buffer
    return &buf[0];
}
//read from file into string
static string readFile(const string &fileName)
{
    string r;
    FILE *f = fopen(fileName.c_str(), "rb");
    if (f == NULL)
        return r;
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    r.resize(size + 1, 0);
    int bytes = (int)fread(&r[0], size, 1, f);
    ASSERT(bytes == 1);
    fclose(f);
    return r;
}
//============================== syntax analysis
int main()
{
    string file_path;
    cout<<"Enter file path:";
    cin>>file_path;
    string input = readFile(file_path);
    input = unescape(input);
    const char * input_cstr = input.c_str();
    printf("input:\n%s\n", input_cstr);
    printf("-------------------------\n");
    Scanner scanner(input_cstr);
    //扫描并输出每个Token
    Token token;
    do{
        token = scanner.next();
        cout << "Token ID: " << token.tid << ", Lexeme: " << token.lexeme << endl;
    } while (token.tid != TID_EOF);
    Parser parser(&scanner);
    parser.parse();

    AstNode *ast = parser.getAstRoot(); // 获取 AST 根节点
    if (ast){
        std::cout << "=== AST ===\n";
        printAst(ast);
    }
    
    return 0;
}

