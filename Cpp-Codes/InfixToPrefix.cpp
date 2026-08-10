// Program to infix expressions into prefix
// Only for single digits, 0 to 9
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// performing operations
void performOperation(stack<string>* val, stack<char>* op){
    string v2 = val->top();    // get top val
    val->pop();                // remove from stack
    string v1 = val->top();
    val->pop();
    char oper = op->top();     // get top op
    op->pop();  

    // push prefix expression
    string t = oper + v1 + v2;
    val->push(t);
}

string to_prefix(string str){
    // declare two stacks
    stack<string>* val = new stack<string>();  // one for values in string
    stack<char>* op = new stack<char>();       // one for operators in string

    // loop for traversing through string
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];  // ith character

        // case 1: if character is a letter (operand)
        if(isalpha(ch)){
            string s;
            s += ch;    // append char to empty string              
            val->push(s);
        }

        // case 2: if character is operator, then there are three states
        // state 1: if op stack is empty, or char is '(', or top of op stack is '('
        else if(op->empty() || ch == '(' || op->top() == '('){
            op->push(ch);  // simply push any operator
        }

        // state 2: if char is closing bracket
        else if(ch == ')'){
            while(!op->empty() && op->top() != '('){
                performOperation(val, op);
            }
            op->pop();  // '(' popped
        }

        // state 3: at least one operator already in op stack
        else{
            // if operator is + or -
            if(ch == '+' || ch == '-'){
                // equal precedence operator exists on stack, so perform first
                performOperation(val, op);
                op->push(ch);
            }

            // if operator is *, / or %  (same precedence group)
            if(ch == '*' || ch == '/' || ch == '%'){
                // if *, /, % or higher precedence ^ already on stack, perform first
                if((!op->empty()) && (op->top() == '*' || op->top() == '/' || op->top() == '%' || op->top() == '^')){
                    performOperation(val, op);
                    op->push(ch);
                }
                // lower precedence operator on stack, simply push
                else
                    op->push(ch);
            }

            // if operator is ^
            if(ch == '^'){
                op->push(ch);
            }
        }
    }

    // after loop, evaluate remaining values until final result
    while(val->size() > 1){
        performOperation(val, op);
    }

    // store the result
    string result = val->top();

    // free allocated memory
    delete val;
    delete op;  

    return result;
}

int main(){
    // Note: don't give any space between operators and operands
    string str = "((P%Q)/A*B^C)+(R-S%U)+W^Z";
    cout << "Prefix: " << to_prefix(str) << endl;
}