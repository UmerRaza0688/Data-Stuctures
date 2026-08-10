#include <iostream>
using namespace std;

class List{
    private:
        int *arr;
        int size;
        int capacity;
        int current;

        // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        // We want flexible list, for this we have to resize after size == capacity
        void resize(){
            // double the size
            capacity *= 2;

            // create new array
            int *newArr = new int[capacity];

            //Copy the content in new array
            for(int i = 0; i < size; i++){
                newArr[i] = arr[i];
            }

            // delete previus array
            delete[] arr;
            //assign it
            arr = newArr;
        }
        // XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    
    public:
        List(){
            capacity = 10;
            arr = new int[capacity];
            size = 0;
            current = 0;
        }
        ~List(){ delete [] arr; }

        // find an element
        int find(int x);
        // get current value
        int get();
        //get length of array
        int length();
        //back one step, current pointer
        void back(); 
        //take current pointer to start
        void start(); 
        //take current pointer to end 
        void end(); 
        // Check if list is empty
        bool isEmpty();
        // update value of last index
        void update(int x);
        // update value at particular index
        void update(int index, int x);
        //insert value at last index
        void insert(int x);
        //insert a value at particular index
        void insert(int index, int x);
        //remove value at particular index
        void remove(int index);
        // remove value at last index
        void pop();
        // display list
        void display();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

 // find an element
int List::find(int x){
    for(int i=0; i<size; i++){
        if(arr[i] == x) {
            current = i;
            return current;   // return index number
        }
    }
    return -1; // not found
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get current value
int List::get(){
    if(size == 0){
        cout << "List is empty.\n";
        return -1;
    }
    return arr[current];
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//get length of array
int List::length(){
    return size;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//back one step, current pointer
void List::back(){
    if(current > 0){
        current--;
    }
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//take current pointer to end 
void List::start(){
    if(size > 0)
        current = 0;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//take current pointer to end 
void List::end(){
    if(size > 0)
        current = size-1;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// update value of last index
void List::update(int x){
    if(size==0) return;
    arr[current] = x;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Check if list is empty
bool List::isEmpty(){
        return (size == 0);
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// update value at particular index
void List::update(int index, int x){
    if(index < 0 || index >= size) {
        cout << "Invalid Index!\n";
        return;
    }
    arr[index] = x;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//insert value at last index
void List::insert(int x){
    if(size == capacity) 
        resize();
    arr[size++] = x;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//insert a value at particular index
void List::insert(int index, int x){
    if(index < 0 || index > size) {
        cout << "Invalid Index!\n";
        return;
    }

    if(size == capacity) resize();

    // right shifting values by 1
    for(int i=size; i>index; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = x;
    size++;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//remove value at particular index
void List::remove(int index){
    if(size == 0){
        cout << "List is empty!\n";
        return;
    }

    if(index < 0 || index >= size) {
        cout << "Invalid Index!\n";
        return;
    }

    // left shifting values by 1
    for(int i=index; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    
    size--;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove value at last index
void List::pop(){
    if(size == 0){
        cout << "List is empty!\n";
        return;
    }

    size--;

    if(size == 0)
        current = 0;
    else if(current >= size)
        current = size - 1;
    else 
        return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// display list
void List::display(){
    cout << "[ ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "]\n";
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX