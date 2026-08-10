// Program to evaluate postfix expressions with operators  '+', '-', '*'. '/', '^', '%'
// Only for single digits, 0 to 9
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// performing operations
void performOperation(stack<int>* val, char oper){
    int v2 = val->top();    // get top val
    val->pop();             // remove from stack
    int v1 = val->top();
    val->pop();

    if(oper == '+')    val->push(v1 + v2);
    if(oper == '-')    val->push(v1 - v2);
    if(oper == '*')    val->push(v1 * v2);
    if(oper == '/')    val->push(v1 / v2);
    if(oper == '^')    val->push(pow(v1, v2));
    if(oper == '%')    val->push(v1 % v2);
}

int Postfix(string str){
    // stack
    stack<int>* val = new stack<int>();  

    // loop for traversing through string
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];       // ith character

        // if ch is digit, push it on stack
        if(isdigit(ch)){
            val->push(ch - 48);
            // val->push(ch - '0');
        }
        // when operator comes perform operation
        else{
            performOperation(val, ch);
        }
    }
        
    // store the result
    int result = val->top();
    // free allocated memory
    delete val;
    // return the result
    return result;
}

int main(){
    // Note: don't give any space between operators and operands
    string str = "9232^*+4-";
    cout << "Answer: " << Postfix(str) << endl;
}