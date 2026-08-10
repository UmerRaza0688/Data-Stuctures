// implementing a double ended Queue, by LinkedList
#include <iostream>
using namespace std;

// Node class
class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    
        Node(int v){
            val = v;
            next = nullptr;
            prev = nullptr;
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

        // if queue is full
        bool is_full(){
            return (size > 10);
        }

    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

        ~Queue(){
            while(front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        // operation on queue

        // to enter val, from front
        void insertFront(int val);
        // to enter val, from rear
        void insertRear(int val);
        // to delete a val, from front
        void removeFront();
        // to delete a val, from rear
        void removeRear();
        // get front val
        int _front();
        // get rear val
        int _rear();
        // display queue
        void print();
};

// operation on queue
// to enter val, from front
void Queue::insertFront(int val){
    Node* new_node = new Node(val);

    // if queue is full
    if(is_full()){
        throw runtime_error("Queue is full, can't enqueue!");
    }

    // if queue is empty
    if(front == nullptr){
        front = rear = new_node;
    }
    // in other cases
    else{
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    }
    size++;
    return;
}

// to enter val, from rear
void Queue::insertRear(int val){
    Node* new_node = new Node(val);

    // if queue is full
    if(is_full()){
        throw runtime_error("Queue is full, can't enqueue!");
    }

    // if queue is empty
    if(rear == nullptr){
        front = rear = new_node;
    }
    // in other cases
    else{
        rear->next = new_node;
        new_node->prev = rear;
        rear = new_node;
    }

    size++;
    return;
}

// to delete a val, from front
void Queue::removeFront(){
    if(is_empty()){
        throw runtime_error("Queue is empty, can't dequeue!");
    }

    Node* temp = front;

    front = front->next;
    if(front == nullptr){
        size--;
        return;
    }
    front->prev = nullptr;

    delete temp;
    size--;
}

// to delete a val, from rear
void Queue::removeRear(){
    if(is_empty()){
        throw runtime_error("Queue is empty, can't dequeue!");
    }

    Node* temp = rear;

    rear = rear->prev;
    if(rear == nullptr) {
        size--;
        return;
    }

    rear->next = nullptr;
    
    delete temp;

    size--;
}

// get front val
int Queue::_front(){
    if(is_empty()) return -1;
    
    // else
    return front->val;
}

// get tail val
int Queue::_rear(){
    if(is_empty()) return -1;

    // else
    return rear->val;
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

    q.insertFront(55);
    q.insertFront(60);
    q.insertFront(65);
    q.insertFront(70);
    q.insertFront(75);
    q.insertRear(80);
    q.insertRear(85);
    q.insertRear(90);
    q.insertRear(95);
    q.insertRear(100);
    // q.insertRear(100);

    q.print();

    q.removeFront();
    q.removeRear();
    q.print();

    return 0;
}