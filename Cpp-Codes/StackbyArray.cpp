// implementing stack data structure in CPP using array, this data structure follow LIFO Algo
// implement push, pop, top or peek functions

// stack class
#include <iostream>
#define STACK_SIZE 10

using namespace std;

class Stack{
    private:
        int* arr;
        int top;

        // to check if stack is empty
        bool isEmpty();
        // to check if stack is full
        bool isFull();

    public:
    // Constructor
        Stack(){
            arr = new int[STACK_SIZE];
            top = -1;
        }

        // Destructor
        ~Stack() { delete [] arr ; }

        // Stack operations 
        
        // push a val in stack
        void push(int val);
        // pop a val in stack
        int pop();
        // peek in stack
        int peek();
        // print stack
        void print();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Stack operations 
        
// to check if stack is empty
bool Stack::isEmpty(){
    return (top == -1);
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// to check if stack is full
bool Stack::isFull(){
    return (top == STACK_SIZE - 1);
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// push a val in stack
void Stack::push(int val){
    if(isFull()){
        throw runtime_error("Stack is full!");
    }

    arr[++top] = val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// pop a val in stack
int Stack::pop(){
    if(isEmpty()){
        throw runtime_error("Stack is empty!");
    }

    int val = arr[top];
    top--;
    return val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// peek in stack
int Stack::peek(){
    if(isEmpty()){
        cout << "Stack is empty!" << endl;
    }

    return arr[top];
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// display
void Stack::print(){
    cout << "[ ";
    for(int i = 0; i <= top; i++){
        cout << arr[i];
        if(i != top) cout << " <- ";
    }
    cout << " ]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX