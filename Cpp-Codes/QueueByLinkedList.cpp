// implementing a Queue data structure, by LinkedList
#include <iostream>
using namespace std;

// Node class
class Node{
    public:
        int val;
        Node* next;
    
        Node(int v){
            val = v;
            next = nullptr;
        }

        ~Node(){}
};

class Queue{
    private:
        Node* front;
        Node* rear;
    
        // if queue is empty
        bool is_empty(){
            return (front == nullptr);
        }

    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
        }

        ~Queue(){
            while(front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        // operation on queue

        // to enter val
        void enqueue(int val);
        // to delete a val
        void dequeue();
        // get front val
        int _front();
        // display queue
        void print();
};

// operation on queue
// to enter val
void Queue::enqueue(int val){

    Node* new_node = new Node(val);

    // if queue is empty
    if(front == nullptr){
        front = rear = new_node;
    }
    // in other cases
    else{
        rear->next = new_node;      // add new_node at the end of queue
        rear = new_node;            // updating rear
    }
}

// to delete a val
void Queue::dequeue(){
    if(is_empty()){
        throw runtime_error("Queue is empty, can't dequeue!");
    }

    Node* temp = front;

    front = front->next;

    delete temp;
}

// get front val
int Queue::_front(){
    return front->val;
}

// display quueue
void Queue::print(){
    Node* temp = front;
    while(temp != nullptr){
        cout << temp->val;
        if(temp->next != nullptr) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.print();

    q.dequeue();
    q.print();

    return 0;
}