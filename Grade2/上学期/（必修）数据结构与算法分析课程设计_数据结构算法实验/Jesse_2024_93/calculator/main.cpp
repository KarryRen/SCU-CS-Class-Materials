#include "calculator.h"

int main() {
    char postfix[MAX_SIZE];
    cout << "Enter a postfix expression: ";
    calculator cal;
    cin.getline(postfix, 100);
    double result =cal.calculate_result(postfix);
    cout << "Result: " << result << endl;
    return 0;
}