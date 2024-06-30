#include <iostream>
#include <string>

#include "Calculator.h"

using namespace std;

int main() {
    string exp;
    Calculator calc;
    stringstream ss1(
            "1+2-3*4/5\n"
            "10 - (-2 + 3) * 4\n"
            "sqrt(  1.9999999999999999999999999999999999999  +  2.00000000000000000000000000000000000001  )\n"
            "max(sqrt(5.5678), -1.56789022222222222222, 3456, -12345678) - 2456\n"
            "sin(PI/6)\n"
            "(1.000000000000001+0.999999999999999)*1.01010101010101010101\n"
            "999999999999999999999999     *        999999999999999999999999 \n"
            "999999999999.999999999999    *        999999999999.999999999999\n"
            "-222-333.555555555555555555555555555555555555555555\n"
            "-4*3\n"
            "+2\n"
            "2^2^3\n"  /// should be 256, not 64
            "6/3/2\n"  /// should be 1, not 4
            "x_1=12345\n"
            "(x_1-2345)/2\n"
            "random()\n"
            "random()\n"
    );
    auto cin_buf = cin.rdbuf();
    cin.rdbuf(ss1.rdbuf());
    while (getline(cin, exp)) {
        calc.input(exp);
        try {
            calc.calculate();
        } catch (exception &e) {
            cerr << e.what() << endl;
        }
    }
    cout.flush();
    cerr.flush();
    stringstream ss2(         /// should throw exceptions
            "1/0\n"
            "--1\n"
            "-1-\n"
            "1++2\n"
            "1+2-\n"
            "4*-3\n"
            "-1+(2+3*)\n"
            "1#2\n"
            "_x1=5\n"
            "undefined_var+5\n"
            "sin(1,2)\n"
            "pow(5)\n"
    );
    cin.rdbuf(ss2.rdbuf());
    while (getline(cin, exp)) {
        calc.input(exp);
        try {
            calc.calculate();
        } catch (exception &e) {
            cerr << e.what() << endl;
        }
    }
    cin.rdbuf(cin_buf);
//    cout << "User inputs start here:" << endl;
//    while (getline(cin, exp)) {
//        calc.input(exp);
//        try {
//            calc.calculate();
//        } catch (exception &e) {
//            cerr << e.what() << endl;
//        }
//    }
    return 0;
}
