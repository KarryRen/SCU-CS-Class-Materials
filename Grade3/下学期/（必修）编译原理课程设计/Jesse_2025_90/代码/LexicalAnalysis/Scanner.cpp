// Scanner.cpp
#include "Scanner.h"
#include <cctype>
#include <stdexcept>
#include "Token.h"   // 假设Token定义在一个单独的头文件中
#include "Lexemes.h" // 假设Lexemes.h中包含getBuildinToken函数

using namespace std;
// init Scanner with c_str from test data
Scanner::Scanner(const char *src) : m_src(src) {}
//return n-index token
Token Scanner::LA(int n)
{
    fetchN(n);
    return m_LAList[n - 1];
}
//return next token
Token Scanner::next(int n)
{
    fetchN(n);
    Token token = m_LAList[0];
    m_LAList.erase(m_LAList.begin(), m_LAList.begin() + n);
    return token;
}
// tansform c_str into TokenType
void Scanner::fetchN(int n)
{
    while ((int)m_LAList.size() < n)
    {
        // Skip whitespace characters
        for (; isspace(*m_src); ++m_src)
            ;
        // End of source code
        if (m_src[0] == 0)
        {
            m_LAList.push_back(Token());
        }
        // Skip one-line commments
        else if (m_src[0] == '/' && m_src[1] == '/')
        {
            while (*++m_src != '\n' && *m_src != 0)
                ;
            if (*m_src == '\n')
                ++m_src;
        }
        // Skip multi-line comments
        else if (m_src[0] == '/' && m_src[1] == '*')
        {   
            ++m_src;
            do
            {
                ++m_src;
            } while (m_src[0] != '*' || m_src[1] != '/');
            m_src += 2;
        }
        // Integer literal
        else if (isdigit(m_src[0]))
        {
            const char *begin = m_src;
            while (isdigit(*++m_src))
                ;
            m_LAList.push_back(Token(TID_INT, begin, m_src));
        }
        //String literal
        else if (m_src[0] == '"')
        {
            const char *begin = m_src;
            while (*++m_src != '"')
            {
                //handle multi-line string
                if (*m_src == '\\')
                    ++m_src;
            }
            m_LAList.push_back(Token(TID_STRING, begin, ++m_src));
        }
        // Identifier or keyword
        else if (isalpha(m_src[0]) || m_src[0] == '_')
        {
            const char *begin = m_src;
            do
            {
                ++m_src;
            } while (isalpha(m_src[0]) || m_src[0] == '_' || isdigit(m_src[0]));
            string lexeme(begin, m_src);
            if (Token *token = getBuildinToken(lexeme))
            {
                m_LAList.push_back(*token);
            }
            else
            {
                m_LAList.push_back(Token(TID_ID, begin, m_src));
            }
        }
        // Single-character and multi-character operators
        else
        {
            string lexeme(m_src, m_src + 2);
            if (Token *token = getBuildinToken(lexeme))
            {
                m_LAList.push_back(*token);
                m_src += 2;
            }
            else
            {
                lexeme.assign(m_src, m_src + 1);
                if (Token *token = getBuildinToken(lexeme))
                {
                    m_LAList.push_back(*token);
                    ++m_src;
                }
                else
                {
                    throw logic_error("invalid token");
                }
            }
        }
    }
}