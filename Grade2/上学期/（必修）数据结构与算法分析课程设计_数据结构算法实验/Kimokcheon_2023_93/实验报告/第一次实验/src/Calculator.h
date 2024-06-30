#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "HighPrecisionFloat.h"

#include <map>
#include <stack>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <stdexcept>
#include <sstream>

class Calculator {
    friend class HighPrecisionFloat;

public:
    typedef HighPrecisionFloat value_type;
    typedef long double ld;
    explicit Calculator(std::string exp = "");
    void clear();
    void input(const std::string &exp);
    value_type calculate();

private:
    std::string expression;
    value_type calc(std::string::iterator &pos);
    std::string getToken(std::string::iterator &pos);
    inline value_type strtol(std::string::iterator &pos);
    inline bool isOperator(char c);
    [[nodiscard]] bool isFunction(const std::string &funcName) const;
    [[nodiscard]] bool isVariable(const std::string &funcName) const;
    [[nodiscard]] bool isConstant(const std::string &funcName) const;
    inline void calcOnce(std::stack<value_type> &operands, std::stack<char> &opts);
    inline void calcFunc(const std::string &funcName, std::string::iterator &pos, std::stack<value_type> &operands,
                         std::stack<char> &opts);
    [[nodiscard]] int getArgs(const std::string &funcName) const;
    inline value_type invoke(const std::string &funcName, const std::vector<value_type> &args);
    std::map<char, int> operators = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3},
    };
    std::map<std::string, value_type> variables = {};
    std::map<std::string, value_type> constants = {
            {"PI", M_PI},
            {"E",  M_E},
    };
    std::map<std::string, int> const functions = {
            {"random", 0},  // 返回[0,1)的随机数
            {"sqrt",   1},
            {"ln",     1},
            {"exp",    1},
            {"sin",    1},
            {"cos",    1},
            {"tan",    1},
            {"asin",   1},
            {"acos",   1},
            {"atan",   1},
            {"sinh",   1},
            {"cosh",   1},
            {"tanh",   1},
            {"asinh",  1},
            {"acosh",  1},
            {"atanh",  1},
            {"abs",    1},
            {"ceil",   1},
            {"floor",  1},
            {"round",  1},
            {"trunc",  1},
            {"log",    2},
            {"pow",    2},
            {"max",    -1},  // -1表示不限制操作数个数
            {"min",    -1},
    };
};


#endif //CALCULATOR_H
