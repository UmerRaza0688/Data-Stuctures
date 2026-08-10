// Program to convert Postfix expressions into Prefix
// Supports single-digit operands (0-9) and single-letter operands (A-Z, a-z)
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void performOperation(stack<string>* val, char oper) {
    string v2 = val->top();  val->pop();
    string v1 = val->top();  val->pop();

    // build prefix: operator comes first, then left operand, then right
    string t = string(1, oper) + v1 + v2;
    val->push(t);
}

string to_prefix(string str) {
    stack<string>* val = new stack<string>();

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // if ch is an operand (letter or digit), push it
        if (isalpha(ch) || isdigit(ch)) {
            val->push(string(1, ch));
        }
        // if ch is an operator (including %), pop two operands and combine
        else {
            performOperation(val, ch);
        }
    }

    string result = val->top();
    delete val;
    return result;
}

int main() {
    // Postfix: PQ%AB/C^*RS%U-+WZ^+
    // which is the postfix form of: ((P%Q)/A*B^C)+(R-S%U)+W^Z
    string str = "PQ%AB/C^*RS%U-+WZ^+";
    cout << "Postfix: " << str << endl;
    cout << "Prefix:  " << to_prefix(str) << endl;
}