// Program to evaluate infix expressions with operators '(', ')', '+', '-', '*'. '/', '^', '%'
// Only for single digits, 0 to 9
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// performing operations
void performOperation(stack<int>* val, stack<char>* op){
    int v2 = val->top();    // get top val
    val->pop();             // remove from stack
    int v1 = val->top();
    val->pop();

    if(op->top() == '+')    val->push(v1 + v2);
    if(op->top() == '-')    val->push(v1 - v2);
    if(op->top() == '*')    val->push(v1 * v2);
    if(op->top() == '/')    val->push(v1 / v2);
    if(op->top() == '^')    val->push(pow(v1, v2));
    if(op->top() == '%')    val->push(v1 % v2);     // added

    op->pop();
}

int Infix(string str){
    // declare two stacks
    stack<int>* val = new stack<int>();     // one for values in string
    stack<char>* op = new stack<char>();    // one operators in string

    // loop for traversing through string
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];       // ith character
        int asscii = (int)ch;   // typecasting to int

        // case 1: if character is a number
        // if(asscii >= 48 && asscii <= 57)    // '0' -> 47 and '9' -> 57
        if(isdigit(ch))
            val->push(ch-48);               // e.g: 53 - 48 = 5
            // or val->push(ch-'0');

        //case 2: if character is operator, then there are three states
        // state 1: if op stack is empty, or char is '(', or on the top of op stack is '('
        else if(op->empty() || ch == '(' || op->top() == '(')
            op->push(ch);   // simply push, any operator

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

            // if operators are * , / and %          // added '%'
            if(ch == '*' || ch == '/' || ch == '%'){
                // two case
                // if some '*', '/' , '%' or higher precidence '^' operators are already existing in stack
                // then we have to some work
                if((!op->empty()) && (op->top() == '*' || op->top() == '/' || op->top() == '%' || op->top() == '^')){   // added '%'
                    performOperation(val, op);

                    // after work, push the next operator
                    op->push(ch);
                }
                // if operators that are < in presidence then '*' , '/' and '%' are existing before
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
    int result = val->top();

    // free allocated memory
    delete val;
    delete op;  

    // return the result
    return result;
}

int main(){
    // Note: don't give any space between operators and operands
    string str = "9+(2*3^2)-4";
    cout << "Answer: " << Infix(str) << endl;

    string str2 = "9%4+2";     // test % operator: 9%4=1, 1+2=3
    cout << "Answer: " << Infix(str2) << endl;
}