// implementing queue by array, we will make array circular
#include <iostream>

using namespace std;
#define QUEUE_SIZE 5

class Queue{
    private:
        int* arr;
        int front;
        int rear;
    
        // if queue is full
        bool is_full(){
            // 
            return ((rear + 1) % QUEUE_SIZE == front);
        }
        // if queue us empty
        bool is_empty(){
            return (front == rear);
        }
    public:
        Queue(){
            arr = new int[QUEUE_SIZE];
            front = 0;
            rear = 0;            
        }

        ~Queue(){
            delete[] arr;
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
    if(is_full()){
        cout << "Queue is FULL!" << endl;
        return;
    }

    arr[rear] = val;
    rear = (rear + 1) % QUEUE_SIZE;
}

// to delete a val
void Queue::dequeue(){
    if(is_empty()){
        cout << "Queue us EMPTY!" << endl;
        return;
    }

    front = (front + 1) % QUEUE_SIZE;
}

// get front val
int Queue::_front(){
    if(is_empty()){
        cout << "Queue is Empty!" << endl;
        return -1;
    }

    return arr[front];
}

// display queue
void Queue::print(){
    int i = front;
    while(i != rear){
        cout << arr[i];
        i = (i + 1) % QUEUE_SIZE;
        if(i != rear) cout << "->";
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