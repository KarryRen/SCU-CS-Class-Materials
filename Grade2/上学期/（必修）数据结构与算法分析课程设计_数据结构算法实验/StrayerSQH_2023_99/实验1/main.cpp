#include <iostream>  
#include <string>  
#include <cctype>  
#include <cmath>
#include <vector>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

bool isRight(string s)
{
    Stack<char> opeJudge;
    int arr[10001];
    int j = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '(')
        {
            opeJudge.push(s[i]);
            arr[j] = i;
            j++;
        }
        else if (s[i] == ')')
        {
            if (opeJudge.isEmpty())
            {
                for (int k = 0; k < i - 2; k++)
                {
                    cout << " ";
                }
                cout << "^此处括号不匹配，请检查输入！" << endl;
                for (int i = 0; i < 2; i++)
                {
                    cout << endl;
                }
                return false;
            }
            else
            {
                char tmp;
                opeJudge.pop(tmp);
                arr[j] = 0;
                j--;
            }
        }
    }
    j--;
    if (!opeJudge.isEmpty())
    {
        for (int k = 0; k <= arr[j] - 1 - 2; k++)
        {
            cout << " ";
        }
        cout << "^此处括号不匹配，请检查输入！" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }
        return false;
    }

    return true;
}

void Introduction()
{
    std::string courseInfo = "四川大学计算机学院 2024-2025 学年数据结构与算法分析课程实验课作业一";
    std::string name = "SQH";
    std::string studentID = "2023141460***";

    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    std::cout << "| " << courseInfo;
    std::cout << std::string(74 - courseInfo.length(), ' ') << " |" << std::endl;
    std::cout << "| 姓名：" << name;
    std::cout << std::string(68 - name.length(), ' ') << " |" << std::endl;
    std::cout << "| 学号：" << studentID;
    std::cout << std::string(68 - studentID.length(), ' ') << " |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------+" << std::endl;

    cout << "+----------------------------------------------------------------------------+" << endl;
    cout << "使用方式：1.可以完成正常的四则运算混合运算，例如:1+(1-(2*3+1))=" << endl;
    cout << "          2.支持乘方运算，例如：2^3=" << endl;
    cout << "          3.支持小数运算，例如：1.1+1.1=" << endl;
    cout << "          4.支持自然对数e运算，例如e^2=" << endl;
    cout << "          5.支持三角函数sin,cos,tan,cot运算,但不能嵌套。例如sin(9)+cos(9)+tan(9)" << endl;
    cout << "          6.支持括号匹配检测和指出错误功能,例如：" << endl;
    cout << "                 10+(10*8+1))=" << endl;
    cout << "                            ^ 此处括号不匹配，请检查输入！" << endl;
    cout << "                 1+((2))3=" << endl;
    cout << "                       ^^出现意义不明表达式，请重新输入！" << endl;
    cout << "                 1 + 2(2 + 1) =" << endl;
    cout << "                     ^^出现意义不明表达式，请重新输入！" << endl;
    cout << "          7.非法除0运算检测，例如：" << endl;
    cout << "                 1+1/0=" << endl;
    cout << "                     ^ 除数不能为0，请重新输入！" << endl;
    cout << "                 1+2/(1-1)=" << endl;
    cout << "                         ^ 除数不能为0，请重新输入！" << endl;
    cout << "          8.支持小数点运算检测。若超过一个则启动默认运算" << endl;
    cout << "                 1.1.1*2+1=3.11" << endl;
    cout << "                 输入的小数有错误，小数点‘.'个数超过1个" << endl;
    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    for (int i = 0; i < 1; i++)
    {
        cout << endl;
    }
}

int main()
{
    Introduction();

    char ifEnd = 'y';

    while (toupper(ifEnd) != 'N')
    {
        if (toupper(ifEnd) == 'Y')
        {
            cout << "请输入表达式:" << endl;
            string expression;
            cin >> expression;
            expression.insert(0, "0+");

            if (expression[expression.size() - 1] != '=')
            {
                for (int i = 0; i < expression.size() - 2; i++)
                {
                    cout << " ";
                }
                cout << "^未输入“=”，无法进行运算。请重新输入。" << endl;
                for (int i = 0; i < 2; i++)
                {
                    cout << endl;
                }
            }
            else if (isRight(expression) && expression[expression.size() - 1] == '=')
            {
                Calculator<char> Cal(expression);
                double result = Cal.expRun(1);
            }
        }
        else
        {
            cout << "请正确输入是否继续程序（y/n),感谢理解！" << endl;
            for (int i = 0; i < 2; i++)
            {
                cout << endl;
            }
        }


        cout << "是否继续进行运算（y/n）:";
        cin >> ifEnd;
    }

    cout << "感谢使用！";

    return 0;
}