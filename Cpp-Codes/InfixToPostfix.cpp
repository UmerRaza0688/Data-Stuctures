// Program to infix expressions into postfix
// Only for single digits, 0 to 9
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// performing operations
void performOperation(stack<string>* val, stack<char>* op){
    string v2 = val->top();    // get top val
    val->pop();             // remove from stack
    string v1 = val->top();
    val->pop();
    char oper = op->top();  // get top op
    op->pop();  

    // push postfix expression
    string t = v1 + v2 + oper;
    val->push(t);
}

string to_postfix(string str){
    // declare two stacks
    stack<string>* val = new stack<string>();     // one for values in string
    stack<char>* op = new stack<char>();    // one operators in string

    // loop for traversing through string
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];       // ith character
        int asscii = (int)ch;   // typecasting to int

        // case 1: if character is a number
        // if(asscii >= 48 && asscii <= 57)    // '0' -> 47 and '9' -> 57
        if(isalpha(ch)){
        // if(isdigit(ch)){
            string s;
            s += ch;    // append char to empty string              
            val->push(s);
        }

        //case 2: if character is operator, then there are three states
        // state 1: if op stack is empty, or char is '(', or on the top of op stack is '('
        else if(op->empty() || ch == '(' || op->top() == '('){
            op->push(ch);   // simply push, any operator
        }

        // state 2: if char is closing bracket
        else if(ch == ')'){
            while(!op->empty() && op->top() != '('){
                // work
                performOperation(val, op);
            }
            op->pop();  // '(' poped up
        }

        // state 3: if there is at least one operator in op stack before
        // then also there are some cases due to operator presidence
        else{
            // if operators are + or -
            if(ch == '+' || ch == '-'){
                //if equal precedense operator is existing on stack before, 
                // then some work
                performOperation(val, op);

                // after work, push the next operator
                op->push(ch);
            }

            // if operators are * and / and %
            if(ch == '*' || ch == '/' || ch == '%'){
                // two case
                // if some '*', '/', '%' or higher precidence '^' operators are already existing in stack
                // then we have to some work
                if((!op->empty()) && (op->top() == '*' || op->top() == '/' || op->top() == '%' || op->top() == '^')){
                    performOperation(val, op);

                    // after work, push the next operator
                    op->push(ch);
                }
                // if operators that are < in presidence then '*', '/' and '%' are existing before
                // then, simply push
                else
                    op->push(ch);
            }

            // if operator is '^'
            if(ch == '^'){
                op->push(ch);
            }
        }

    }
    // after loop is completed, if there are some values in val stack
    // we will evaluate them until we get final value, which is result
    while(val->size() > 1){
        // work
        performOperation(val, op);
    }

    // store the result
    string result = val->top();

    // free allocated memory
    delete val;
    delete op;  

    // return the result
    return result;
}

int main(){
    // Note: don't give any space between operators and operands
    string str = "A+B*C-D^E^F";
    cout << "Postfix: " << to_postfix(str) << endl;

    string str2 = "A%B+C*D";
    cout << "Postfix: " << to_postfix(str2) << endl;
}