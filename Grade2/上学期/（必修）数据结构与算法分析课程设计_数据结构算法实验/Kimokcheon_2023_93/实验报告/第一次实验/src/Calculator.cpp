#include "Calculator.h"

using value_type = Calculator::value_type;
using ld = Calculator::ld;

Calculator::Calculator(std::string exp) : expression(std::move(exp)) {}

void Calculator::clear() {
    variables.clear();
}

void Calculator::input(const std::string &exp) {
    expression = exp;
}

value_type Calculator::calculate() {
    if (expression.empty()) {
        throw std::invalid_argument("Empty expression");
    }
    // 检查括号匹配
    int left = 0, right = 0;
    for (const char &c: expression) {
        if (c == '(') {
            left++;
        } else if (c == ')') {
            right++;
        }
    }
    if (left != right)
        throw std::invalid_argument("Mismatched brackets in expression: " + expression);
    if (std::count(expression.begin(), expression.end(), '=') == 1) {  // 赋值表达式
        auto pos = expression.begin();
        std::string var = std::move(getToken(pos));
        if (pos == expression.end() || *pos != '=') {
            throw std::invalid_argument("Invalid expression: " + expression);
        }
        if (!isalpha(var[0])) {
            throw std::invalid_argument("Invalid token: " + var);
        }
        if (isVariable(var)) {
            std::cerr << "WARNING: Redefining variable: " << var << std::endl;
        }
        if (isConstant(var)) {
            throw std::invalid_argument("Cannot redefine constant: " + var);
        }
        ++pos;
        variables[var] = calc(pos);
        return variables[var];
    } else {  // 计算表达式
        auto pos = expression.begin();
        value_type res = calc(pos);
        std::cout << res << std::endl;
        return res;
    }
}

value_type Calculator::calc(std::string::iterator &pos) {
    std::stack<value_type> operands;
    std::stack<char> opts;
    operands.emplace(0.0);
    if (pos == expression.end())
        throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                    std::string(expression.size() + 20, ' ') + "^");
    if (isOperator(expression[expression.size() - 1])) {
        throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                    std::string(expression.size() - 1 + 20, ' ') + "^");
    }
    while (pos != expression.end()) {
        if (isspace(*pos)) {
            ++pos;
            continue;
        }
        if (*pos == '(') {
            if (*(pos + 1) == ')') {
                throw std::invalid_argument("Empty brackets: " + expression + "\n" +
                                            std::string(pos - expression.begin() + 16, ' ') + "^");
            }
            operands.push(calc(++pos));  // 结束递归调用后，pos指向')'或','
            pos++;
        } else if (*pos == ')' || *pos == ',') {
            break;  // 清空操作数栈，结束递归调用
        } else if (isdigit(*pos)) {  // 提取数字， 形如'.5'会报错
            operands.push(strtol(pos));
        } else if (isOperator(*pos)) {  // 匹配加减乘除、幂函数单独处理
            char opt = *pos++;
            if (isOperator(*pos)) {  // 连续两个运算符视为错误
                throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                            std::string(pos - expression.begin() + 20, ' ') + "^");
            }
            if (opt == '^') {  // 幂函数运算顺序自右向左，先入栈而不计算
                opts.push(opt);
                continue;
            }
            while (!opts.empty() && operators[opt] <= operators[opts.top()]) {
                try {
                    calcOnce(operands, opts);
                } catch (const std::invalid_argument &e) {
                    throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                                std::string(20, ' ') + std::string(pos - expression.begin(), '^'));
                } catch (const std::range_error &e) {
                    throw std::range_error("Divided by zero in expression: " + expression + "\n" +
                                           std::string(31, ' ') + std::string(pos - expression.begin(), '^'));
                }
            }
            opts.push(opt);
        } else {
            std::string token = std::move(getToken(pos));  // 提取函数名，pos指向参数列表的左括号 或 提取变量名
            if (token.empty())
                throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                            std::string(pos - expression.begin() + 20, ' ') + "^");
            if (isFunction(token)) {  // 匹配函数
                if (pos == expression.end() || *pos != '(') {
                    throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                                std::string(pos - expression.begin() + 20, ' ') + "^");
                }
                ++pos;
                calcFunc(token, pos, operands, opts);
                ++pos;
            } else if (isConstant(token)) {  // 匹配常量
                operands.push(constants[token]);
            } else if (isVariable(token)) {  // 匹配变量
                operands.push(variables[token]);
            } else {
                throw std::invalid_argument("Invalid token '" + token + "' in expression: " + expression + "\n" +
                                            std::string(pos - expression.begin() + 32 + token.size() - 1, ' ') + "^");
            }
        }
    }
    if (isOperator(*(pos - 1))) {
        throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                    std::string(pos - 1 - expression.begin() + 20, ' ') + "^");
    }
    while (!opts.empty()) {   // 完成栈中剩余运算符的计算
        try {
            calcOnce(operands, opts);
        } catch (const std::invalid_argument &e) {
            throw std::invalid_argument("Invalid expression: " + expression + "\n" +
                                        std::string(expression.size() - 1 + 20, ' ') + "^");
        } catch (const std::range_error &e) {
            throw std::range_error("Divided by zero in expression: " + expression + "\n" +
                                   std::string(expression.size() - 1 + 31, ' ') + "^");
        }
    }
    return operands.top();
}

std::string Calculator::getToken(std::string::iterator &pos) {
    std::string token;
    while (pos != expression.end() && (isalpha(*pos) || isdigit(*pos) || *pos == '_'))
        token += *pos++;
    return token;
}

inline value_type Calculator::strtol(std::string::iterator &pos) {
    std::string str;
    while (pos != expression.end() && isdigit(*pos)) {
        str += *pos++;
    }
    if (pos != expression.end() && *pos == '.') {
        str += *pos++;
        while (pos != expression.end() && isdigit(*pos)) {
            str += *pos++;
        }
    }
    return value_type(str);
}

inline bool Calculator::isOperator(char c) {
    return operators.find(c) != operators.end();
}

inline void Calculator::calcOnce(std::stack<value_type> &operands, std::stack<char> &opts) {
    if (operands.size() < 2)
        throw std::invalid_argument("Invalid expression: " + expression);
    value_type num2 = operands.top();
    operands.pop();
    value_type num1 = operands.top();
    operands.pop();
    char top = opts.top();
    opts.pop();
    if (top == '+') {
        operands.emplace(num1 + num2);
    } else if (top == '-') {
        operands.emplace(num1 - num2);
    } else if (top == '*') {
        operands.emplace(num1 * num2);
    } else if (top == '/') {
        if (num2 == 0) {
            throw std::range_error("Divided by zero in expression: " + expression);
        }
        operands.emplace(ld(num1) / ld(num2));
    } else if (top == '^') {
        operands.emplace(powl(ld(num1), ld(num2)));
    }
}

inline void
Calculator::calcFunc(const std::string &funcName, std::string::iterator &pos, std::stack<value_type> &operands,
                     std::stack<char> &opts) {
    std::vector<value_type> args;
    while (pos != expression.end() && *pos != ')') {  // 提取参数， pos指向参数列表后的右括号
        args.push_back(calc(pos));
        if (*pos == ',') ++pos;
    }
    if (getArgs(funcName) != -1 && args.size() != getArgs(funcName)) {  // 检查参数个数
        throw std::invalid_argument("Mismatched number of parameters to function '"
                                    + funcName + "' in expression: " + expression
                                    + ", excepted " + std::to_string(getArgs(funcName)) + ", got " +
                                    std::to_string(args.size()));
    }
    operands.emplace(invoke(funcName, args));
}

bool Calculator::isFunction(const std::string &funcName) const {
    return functions.find(funcName) != functions.end();
}

bool Calculator::isVariable(const std::string &funcName) const {
    return variables.find(funcName) != variables.end();
}

bool Calculator::isConstant(const std::string &funcName) const {
    return constants.find(funcName) != constants.end();
}

int Calculator::getArgs(const std::string &funcName) const {
    return functions.at(funcName);
}

inline value_type Calculator::invoke(const std::string &funcName, const std::vector<value_type> &args) {
    if (funcName == "sqrt") {
        if (ld(args[0]) < 0)
            throw std::invalid_argument("Invalid argument to function 'sqrt' in expression: " + expression);
        return sqrtl(ld(args[0]));
    } else if (funcName == "ln") {
        if (ld(args[0]) <= 0)
            throw std::invalid_argument("Invalid argument to function 'ln' in expression: " + expression);
        return logl(ld(args[0]));
    } else if (funcName == "exp") {
        return expl(ld(args[0]));
    } else if (funcName == "sin") {
        return sinl(ld(args[0]));
    } else if (funcName == "cos") {
        return cosl(ld(args[0]));
    } else if (funcName == "tan") {
        return tanl(ld(args[0]));
    } else if (funcName == "asin") {
        if (ld(args[0]) < -1 || ld(args[0]) > 1)
            throw std::invalid_argument("Invalid argument to function 'asin' in expression: " + expression);
        return asinl(ld(args[0]));
    } else if (funcName == "acos") {
        if (args[0] < -1 || args[0] > 1)
            throw std::invalid_argument("Invalid argument to function 'acos' in expression: " + expression);
        return acosl(ld(args[0]));
    } else if (funcName == "atan") {
        return atanl(ld(args[0]));
    } else if (funcName == "sinh") {
        return sinhl(ld(args[0]));
    } else if (funcName == "cosh") {
        return coshl(ld(args[0]));
    } else if (funcName == "tanh") {
        return tanhl(ld(args[0]));
    } else if (funcName == "asinh") {
        return asinhl(ld(args[0]));
    } else if (funcName == "acosh") {
        return acoshl(ld(args[0]));
    } else if (funcName == "atanh") {
        return atanhl(ld(args[0]));
    } else if (funcName == "abs") {
        return fabsl(ld(args[0]));
    } else if (funcName == "ceil") {
        return ceill(ld(args[0]));
    } else if (funcName == "floor") {
        return floorl(ld(args[0]));
    } else if (funcName == "round") {
        return roundl(ld(args[0]));
    } else if (funcName == "trunc") {
        return truncl(ld(args[0]));
    } else if (funcName == "log") {
        if (ld(args[0]) <= 0 || ld(args[1]) <= 0)
            throw std::invalid_argument("Invalid argument to function 'log' in expression: " + expression);
        return logl(ld(args[1])) / logl(ld(args[0]));
    } else if (funcName == "pow") {
        if (ld(args[0]) == 0 && ld(args[1]) <= 0)
            throw std::invalid_argument("Invalid argument to function 'pow' in expression: " + expression);
        return powl(ld(args[0]), ld(args[1]));
    } else if (funcName == "max") {
        value_type maxn = args[0];
        for (int i = 1; i < args.size(); ++i) {
            maxn = std::max(maxn, args[i]);
        }
        return maxn;
    } else if (funcName == "min") {
        value_type minn = args[0];
        for (int i = 1; i < args.size(); ++i) {
            minn = std::min(minn, args[i]);
        }
        return minn;
    } else if (funcName == "random") {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<ld> dist(0.0, 1.0);
        return dist(mt);
    }
    return 0;
}
