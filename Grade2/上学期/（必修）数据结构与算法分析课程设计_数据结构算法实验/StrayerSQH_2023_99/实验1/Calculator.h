#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>  
#include <string>  
#include <cctype>  
#include <cmath>
#include <vector>
#include "Stack.h"

using namespace std;

template <class T>
class Calculator {
private:
    Stack<T> NumStack;
    Stack<char> OpeStack;
    string expression;

public:
    Calculator() {}
    Calculator(string exp) : expression(exp) {}

    ~Calculator() {}

    double getValue()
    {
        int i = 0, judge = 0, pointNum = 0;
        double a = 0;
        char ch;
        NumStack.pop(ch);

        while (ch != 'A')
        {
            a += pow(10, i) * ch;
            i++;
            NumStack.pop(ch);
            if (ch == '.')
            {
                pointNum++;
                if (pointNum > 1)
                {
                    cout << "输入的小数有错误，小数点‘.'个数超过1个，自动处理为将第一个小数点作为小数点。（若不符合需求，请忽略运算结果）" << endl;
                }
                a /= pow(10, i);
                i = -1;
                ch = 0;
            }

            if (ch == '-')
            {
                judge = 1;
                NumStack.pop(ch);
                break;
            }
        }

        if (judge)
        {
            a *= -1;
        }

        return a;
    }

    bool isOperator(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            return true;
        }
        return false;
    }

    int opeGrade(char ope)
    {
        switch (ope)
        {
        case '=': return 1;
        case '(': return 2;
        case ')': return 2;
        case '+': return 3;
        case '-': return 3;
        case '*': return 4;
        case '/': return 4;
        case '%': return 4;
        case '^': return 5;
        default: return 0;
        }
    }

    double MyCalculator(double a, char ope, double b)
    {
        switch (ope)
        {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        }

    }

    double expRun(int need)
    {
        //将操作符栈中压入字符=
        OpeStack.push('=');
        NumStack.push('A');
        OpeStack.push('+');
        //定义相关变量
        char beforCh; //前一个字符
        char opeCh = '='; //操作符并将其赋值为操作符栈顶中的=
        char opeBefore = '=';
        char opeTop = 'T';

        int i = 0;
        double a, b, c;
        while (i < expression.size())
        {
            if (expression[i] == 's' || expression[i] == 'c' || expression[i] == 't')
            {
                string b;
                vector<string> trigFunctions = { "sin", "cos", "tan", "cot" };

                size_t startIndex = string::npos;
                size_t endIndex = string::npos;

                for (const auto& func : trigFunctions)
                {
                    size_t startIndex = 0;
                    while ((startIndex = expression.find(func + "(", startIndex)) != std::string::npos)
                    {
                        size_t endIndex = expression.find(")", startIndex);
                        if (endIndex != std::string::npos)
                        {
                            b = expression.substr(startIndex + func.size() + 1, endIndex - startIndex - func.size() - 1);
                            startIndex = endIndex;
                        }
                    }
                }

                b.insert(b.size(), 1, '=');
                b.insert(0, "0+(");
                Calculator<char> CalTri(b);

                double resultTri;
                if (expression[i] == 's')
                {
                    resultTri = sin(CalTri.expRun(0));
                }
                else if (expression[i] == 'c' && expression[i + 2] == 's')
                {
                    resultTri = cos(CalTri.expRun(0));
                }
                else if (expression[i] == 't')
                {
                    resultTri = tan(CalTri.expRun(0));
                }
                else if (expression[i] == 'c' && expression[i + 2] == 't')
                {

                    resultTri = 1 / tan(CalTri.expRun(0));
                }

                string numTri = to_string(resultTri);
                for (int i = 0; i < numTri.size(); i++)
                {
                    if (isdigit(numTri[i]))
                    {
                        NumStack.push(numTri[i] - '0');
                    }
                    else
                    {
                        NumStack.push(numTri[i]);
                    }
                }
                beforCh = 'N';
                i += b.size();
            }
            else if (expression[i] == '(')
            {
                OpeStack.push(opeBefore);
                OpeStack.push(expression[i]);
                opeBefore = expression[i];
            }
            else if (isdigit(expression[i]))
            {
                if (isdigit(expression[i]) && expression[i + 1] == '(')
                {
                    for (int k = 0; k < i - 2; k++)
                    {
                        cout << ' ';
                    }
                    cout << "^^出现意义不明表达式，请重新输入！" << endl;
                    for (int i = 0; i < 2; i++)
                    {
                        cout << endl;
                    }
                    return i;
                }
                char t = expression[i];
                NumStack.push(t - '0');
                beforCh = 'N';
            }
            else if (expression[i] == 'e')
            {
                string numE = to_string(2.718281828459045);
                for (int i = 0; i < numE.size(); i++)
                {
                    if (isdigit(numE[i]))
                    {
                        NumStack.push(numE[i] - '0');
                    }
                    else
                    {
                        NumStack.push(numE[i]);
                    }
                }
            }
            else if (expression[i] == '.')
            {
                NumStack.push(expression[i]);
            }
            else if ((!isdigit(expression[i - 1]) && expression[i - 1] != ')' && expression[i] == ')') ||
                (expression[i] == ')' && isdigit(expression[i + 1])) ||
                (isOperator(expression[i]) && isOperator(expression[i + 1])))
            {
                for (int k = 0; k < i - 2; k++)
                {
                    cout << ' ';
                }
                cout << "^^出现意义不明表达式，请重新输入！" << endl;
                for (int i = 0; i < 2; i++)
                {
                    cout << endl;
                }
                return i;
            }
            else
            {
                opeCh = expression[i];
                if (opeGrade(opeBefore) < opeGrade(opeCh))
                {
                    if (opeBefore != '(')
                    {
                        OpeStack.push(opeBefore);
                    }
                    opeBefore = opeCh;
                    if (opeCh != '(')
                    {
                        NumStack.push('A');
                    }
                }
                else if (opeGrade(opeCh) <= opeGrade(opeBefore))
                {
                    while (opeGrade(opeCh) <= opeGrade(opeBefore) && !(opeBefore == '=' && opeBefore == opeCh) && !(opeBefore == '(' && opeCh == ')'))
                    {

                        a = getValue();
                        b = getValue();
                        NumStack.push('A');
                        if (a == 0 && opeBefore == '/')
                        {
                            for (int k = 0; k < i - 1 - 2; k++)
                            {
                                cout << ' ';
                            }
                            cout << "^除数不能为0，请重新输入！" << endl;
                            for (int i = 0; i < 2; i++)
                            {
                                cout << endl;
                            }
                            return i;
                        }
                        else
                        {
                            c = MyCalculator(b, opeBefore, a);
                        }
                        string numTmp = to_string(c);
                        for (int i = 0; i < numTmp.size(); i++)
                        {
                            if (isdigit(numTmp[i]))
                            {
                                NumStack.push(numTmp[i] - '0');
                            }
                            else
                            {
                                NumStack.push(numTmp[i]);
                            }
                        }
                        OpeStack.pop(opeBefore);
                        if (OpeStack.isEmpty() || (opeBefore == '('))
                        {
                            OpeStack.push(opeBefore);
                            if (opeCh != ')')
                            {
                                opeBefore = opeCh;
                            }
                            break;
                        }
                    }

                    NumStack.push('A');
                    if (opeBefore != '(')
                    {
                        if (opeGrade(opeBefore) < opeGrade(opeCh))
                        {
                            OpeStack.push(opeBefore);
                        }
                        opeBefore = opeCh;
                    }
                    else if (opeCh == ')' && opeBefore == '(')
                    {
                        char deletCh1;
                        NumStack.pop(deletCh1);
                        OpeStack.pop(opeBefore);
                        OpeStack.pop(opeBefore);
                    }
                }
            }
            i++;
        }

        if (need)
        {
            cout << "表达式的计算结果是：" << c << endl;
        }
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }

        return c;
    }
};


#endif // !CALCULATOR_H

