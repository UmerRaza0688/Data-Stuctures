// Program to convert Postfix expressions to Infix
// Supports single digits (0-9), letter operands (A-Z, a-z)
// Operators: + - * / % ^
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void performOperation(stack<string>* val, char oper) {
    string v2 = val->top(); val->pop();
    string v1 = val->top(); val->pop();

    // infix: wrap in brackets to preserve precedence
    string t = "(" + v1 + oper + v2 + ")";
    val->push(t);
}

string to_infix(string str) {
    stack<string>* val = new stack<string>();

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // if ch is an operand (digit or letter), push it
        if (isdigit(ch) || isalpha(ch)) {
            val->push(string(1, ch));
        }
        // if ch is an operator (+, -, *, /, %, ^), perform operation
        else {
            performOperation(val, ch);
        }
    }

    string result = val->top();
    delete val;
    return result;
}

int main() {
    string str = "9232^*+4-";
    cout << "Infix: " << to_infix(str) << endl;

    // test with % operator
    string str2 = "AB%CD*+";
    cout << "Infix: " << to_infix(str2) << endl;
}