// implementing a limited size Queue data structure, by LinkedList
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
        int size;

        // if queue is empty
        bool is_empty(){
            return (front == nullptr);
        }

        bool is_full(){
            return (size >= 10);
        }
    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

        ~Queue(){
            rear->next = nullptr;
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
        // get front val
        int _rear();
        // display queue
        void print();
};

// operation on queue
// to enter val
void Queue::enqueue(int val){
    if(is_full()){
        throw runtime_error("Queue is full, can't enqueue!");
    }

    Node* new_node = new Node(val);

    // if queue is empty
    if(rear == nullptr){
        rear = front = new_node;
    }
    // in other cases
    else{
        rear->next = new_node;      // add new_node at the end of queue
        new_node->next = front;
        rear = new_node;            // updating rear
    }
    size += 1;
}

// to delete a val
void Queue::dequeue(){
    if(is_empty()){
        throw runtime_error("Queue is empty, can't dequeue!");
    }

    Node* temp = front;

    front = front->next;
    rear->next = front;

    delete temp;

    size -= 1;
}

// get rear val
int Queue::_rear(){
    return rear->val;
}

// get front val
int Queue::_front(){
    return front->val;
}

// display quueue
void Queue::print(){
    if(is_empty()) return;
    Node* temp = front;
    do{
        cout << temp->val;
        if(temp->next != front) cout << "->";
        temp = temp->next;
    }while(temp != front);
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