// Program to convert Prefix expressions infix
// Only for single digits, 0 to 9
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// performing operations
void performOperation(stack<string>* val, char oper){
    string v1 = val->top();    // get top val
    val->pop();                 // remove from stack
    string v2 = val->top();
    val->pop();  

    // push prefix expression
    // for infix brackets are necessary
    string t = "(" + v1 + oper + v2 + ")";
    val->push(t);
}

string to_infix(string str){
    
    stack<string>* val = new stack<string>();     // one for values in string

    // loop for traversing through string
    for(int i = str.length()-1; i >= 0; i--){
        char ch = str[i];       // ith character
        
        // if ch is digit, simpy push it 
        if(isdigit(ch)){
            string s;
            s += ch;    // append char to empty string              
            val->push(s);
        }
        // if ch is operator
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%'){
            performOperation(val, ch);
        }
    }

    // store the result
    string result = val->top();
    // free allocated memory
    delete val;
    // return the result
    return result;
}

int main(){
    // Note: don't give any space between operators and operands
    string str = "-+9*2^324";
    cout << "Infix: " << to_infix(str) << endl;
}