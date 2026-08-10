#include <iostream>
using namespace std;

//  implementing Stack by Linked list

//  list single node
class Node{
    public:
        int val;
        Node* next;

        // constructor
        Node(int v){
            val = v;
            next = nullptr;
        }

        // desturctor
        ~Node() {}
};

// Stack class
class Stack{
    private:
        Node* top;

        // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        // is empty fun
        bool isEmpty(){
            return (top == nullptr);
        }
        // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

    public:
        // constructor
        Stack(){ top = nullptr; }

        // Destructor
        ~Stack(){
            while(top != nullptr){
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }

        // Stack operations

        // push val
        void push(int val);
        // pop val
        int pop();
        // get last val of stack
        int peek();
        // print stack
        void print();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Stack operations

// push val
void Stack::push(int val){
    Node* new_node = new Node(val);

    new_node->next = top;
    top = new_node;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// pop val
int Stack::pop(){
    if(isEmpty()){
        throw runtime_error("Satck is already empty!");
    }

    Node* temp = top;
    int val = temp->val;
    top = top->next;
    delete temp;
    return val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get last val of stack
int Stack::peek(){
    return top->val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// print stack
void Stack::print(){
    Node* temp = top;

    cout << "[ ";
    while(temp != nullptr){
        cout << temp->val ;
        if(temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout<< " ]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX