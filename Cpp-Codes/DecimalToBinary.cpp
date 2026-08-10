#include <iostream>
#include <stack>
#include <string>

using namespace std;

string dec_to_bin(int num){
    if(num == 0)
        return "0";

    stack<int> stack;

    while(num != 0){
        int remainder = num % 2;        // remainder will always be 0 or 1
        num = num / 2;                  // decrease the num, dividing by 2 
        stack.push(remainder);          // push remainder in stack
    }

    string ret_str = "";

    while(!stack.empty()){
        ret_str += to_string(stack.top());  // take value
        stack.pop();                        // remove value
    }

    return ret_str;
}

int main(){

    cout << dec_to_bin(8) << endl;

    return 0;
}