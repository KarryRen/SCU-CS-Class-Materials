#include "mystack.h"
#include <cctype>

class calculator{
public:
//是否为运算符 
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' ||c== '(';
}
//检查是否为单目复号
bool isDoubleOperator(char* p){
    char* temp=p;
    temp++;
    if(isOperator(*(temp))){
        if(*temp=='+'){
            if(*p=='+')
                return true;
            else
                return false;    
        }
        if(*temp=='-'){
            if(*p=='-')
                return true;
            else
                return false;
        }
    }
    return false;
}

//运算符优先级
int priority(char op) {
    switch (op) {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '(':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}
//运算结果
double operate(double n1, double n2, char op) {
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            cout << "Invalid operator: " << op << endl;
            exit(1);
    }
}

double calculate_result(char* postfix) {
    mystack<double> s;
    mystack<char> operators;

    char* p = postfix;
    while (*p != '\0') {
        if (isdigit(*p)) {
            double num = *p - '0';
            p++;
            while (isdigit(*p) || *p == '.') {
                //处理小数情况
                if (*p == '.') {
                    p++;
                    double frac = 0.1;//小数位权重
                    while (isdigit(*p)) {
                        num += (*p - '0') * frac;
                        p++;
                        frac /= 10;
                    }
                    break;
                }
                //处理整数情况
                else {
                    num = num * 10 + (*p - '0');
                    p++;
                }
            }
            s.mypush(num);
        }
        else if(isDoubleOperator(p)){
            char op=*p;
            double num=s.mytop();
            s.mypop();
            s.mypush(operate(num,1.0,op));
            p++;
            p++;
            continue;
        }
        else if(*p==')'){
            while(operators.mytop()!='('){
                char op=operators.mytop();
                operators.mypop();
                double num2=s.mytop();
                s.mypop();
                double num1=s.mytop();
                s.mypop();
                double result=operate(num1,num2,op);   
                s.mypush(result);
            }
            operators.mypop();
            p++;
            continue;
        }
        else if (isOperator(*p)) {
            //这个步骤实际是中缀转后缀
            while (!operators.myisEmpty() && priority(operators.mytop()) >= priority(*p)&&operators.mytop()!='(') {
                /*如果运算符栈的top元素优先级大于中缀表达式中元素
                则取出计算*/
                char op = operators.mytop();
                operators.mypop();
                double num2 = s.mytop();
                s.mypop();
                double num1 = s.mytop();
                s.mypop();
                double result = operate(num1, num2, op);
                //计算后压入结果
                s.mypush(result);
            }
            //处理负号
            char* temp=p;
            temp--;
            if((s.myisEmpty()&&*p=='-')||isOperator(*temp)&&*p=='-'){//
                s.mypush(0);
            }
            //如果运算符栈为空或者top元素优先级小于该中缀表达式,则压入栈
            operators.mypush(*p);
            p++;
        }
        else{
            p++;
        }
    }
    //至此所有数组和运算符均压入数字栈和运算符栈，直接按照后缀表达式规则计算即可
    while (!operators.myisEmpty()) {
        char op = operators.mytop();
        double result;
        operators.mypop();
        double num2 = s.mytop();
        s.mypop();
        double num1 = s.mytop();
        s.mypop();
        result = operate(num1, num2, op);
        s.mypush(result);
    }
    double result = s.mytop();
    return result;
    }
};

