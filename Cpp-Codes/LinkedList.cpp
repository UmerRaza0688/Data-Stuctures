#include <iostream>
using namespace std;

// Node class
class Node{
    public:
        int val;
        Node *next;

        // Initilizing node
        Node(int v = 0){
            val = v;
            next = nullptr;
        }

        // Free, allocated memory
        ~Node(){}
};

// Linked list class
class LinkedList{
    private:
        Node* head;

        // private helper function
        // for sum of list
        int sum_of_list(Node* node);

    public:
    LinkedList() { head = nullptr; }    // initilize head
    // destructor
    ~LinkedList() {
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // List operations

    // display the list
    void display() const;
    // put val at last
    void push(int val);
    // remove value at last
    int pop();
    // insert val at specific index
    void insert(int index, int val);
    // remove a specific value
    void remove(int val);
    // get length of list
    int length() const;
    // get value at specific index
    int get(int index) const;
    // update value at specific index
    void update(int index, int val);
    // find min
    int mini();
    // find max
    int maxi();
    // find duplicate
    int duplicate();
    // reverse the list
    void rev_list();
    // sum of list by recursion
    // public fun without perameters
    int sum_of_list();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// List operations

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// display the list
void LinkedList::display() const{
    Node* temp = head;
    cout << "[ ";
    while(temp != nullptr){
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// put val at last
void LinkedList::push(int val){
    Node *new_node = new Node(val);

    // case 1, if no value current
    if(head == nullptr){
        head = new_node;
        return;
    }

    // case 2, if there is atleast one value
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new_node;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove value at last
int LinkedList::pop(){
    // case 1: if no node
    if(head == nullptr){
        throw runtime_error("List is empty");
    }

    // case 2: if one node
    if(head->next == nullptr){
        int val = head->val;
        delete head;
        head = nullptr;
        return val;
    }

    // case 3: traverse through last
    Node* prev = nullptr;         // to store the last state of temp
    Node* temp = head;
    while(temp->next != nullptr){
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    int val = temp->val;
    delete temp;
    return val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// insert val at specific index
void LinkedList::insert(int index, int val){
    Node* new_node = new Node(val);
   
    // case 1: if index is 0
    if(index == 0){
        new_node->next = head;
        head = new_node;
        return;
    }

    // case 2: if index is in mid or end
    Node* prev = nullptr;
    Node* temp = head;
    int counter = 0;
    while(temp != nullptr && counter < index){
        prev = temp;
        temp = temp->next;
        counter += 1;
    }

    // invalid index
    if(temp == nullptr){
        delete new_node;
        throw runtime_error("Invalid index!");
    }
    else{
        prev->next = new_node;
        new_node->next = temp;
    } 
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove a specific value
void LinkedList::remove(int val){

    Node* temp = head;

    // case 1: if no nodes
    if(head == nullptr){
        throw runtime_error("List is empty!");
    }

    // case 2: if sigle node
    if(temp != nullptr){
        if(temp->val == val){
            head = temp->next;
            delete temp;
            return;
        }
    }

    //case 3: if mid or end nodes
    Node* prev = nullptr;
    while (temp != nullptr){
        if(temp->val == val){
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr){
        return;
    }

    prev->next = temp->next;
    delete temp;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get length of list
int LinkedList::length() const{
    Node* temp = head;

    // case 1: if empty
    if(head == nullptr){
        return 0;
    }

    // case 2: if list has some value
    int counter = 0;
    while (temp != nullptr){
        temp = temp->next;
        counter += 1;
    }
    return counter;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get value at specific index
int LinkedList::get(int index) const{
    // case 1: if no nodes
    if(head == nullptr){
        throw runtime_error("List is empty!");
    }

    // case 2: if one value
    if(index == 0){
        return head->val;
    }

    // case 3: if more then one value
    Node* temp = head;
    int counter = 0;
    while(temp != nullptr && counter < index){
        temp = temp->next;
        counter += 1;
    }

    if(temp == nullptr){
        throw runtime_error("Index out of range.");
    }

    return temp->val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// update value at specific index
void LinkedList::update(int index, int val){
    // case 1: if no node
    if(head == nullptr){
        throw runtime_error("can't update, no value!");
    }

    // case 2: if index is 0
    if(index == 0){
        head->val = val;
        return;
    }

    // case 3: if any other index
    Node* temp = head;
    int counter = 0;
    while(temp != nullptr && counter < index){
        temp = temp->next;
        counter += 1;
    }

    temp->val = val;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int LinkedList::mini(){
    // if list is empty
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return -1;
    }

    // if single value
    if(head->next == nullptr){
        return head->val;
    }

    // for else
    int min_val = head->val;
    Node* temp = head->next;
    while(temp != nullptr){
        if(temp->val < min_val)
            min_val = temp->val;
        
        temp = temp->next;
    }

    return min_val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// find max 
int LinkedList::maxi(){
    // if list is empty
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return -1;
    }

    // if single value
    if(head->next == nullptr){
        return head->val;
    }

    // for else
    int max_val = head->val;
    Node* temp = head->next;
    while(temp != nullptr){
        if(temp->val > max_val)
            max_val = temp->val;
        
        temp = temp->next;
    }

    return max_val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// find duplicate
int LinkedList::duplicate(){
    // list is empty
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return 0;
    }

    // if single value
    if(head->next == nullptr){
        cout << "List has only one value!" << endl;
        return head->val;
    }

    // else case
    int key = head->val;
    Node* temp = head->next;
    while(temp != nullptr){
        Node* tempo = temp->next;

        while(tempo != nullptr){
            if(tempo->val == key)
                return key;
        
            tempo = tempo->next;
        }

        temp = temp->next;
        key = temp->val;
    }
 
    // not found
    return -1;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// reverse the list
void LinkedList::rev_list(){
    // if list is empty or single valued, list is reversed
    if(head == nullptr) return;
    if(head->next == nullptr) return;

    // if two or more vals
    // 2nd: get the last node & make it new_head
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* new_head = temp;      // tail is the new_head 

    // reverse the list
    Node* processing = new_head;
    
    int len = length();
    // go through list, to it's size-1
    for(int i = 0; i < len-1; i++){

        temp = head; 
        // to reach the processing node
        while(temp->next != processing){
            temp = temp->next;
        }

        processing->next = temp; // reverse the next of processing node
        processing = temp;      // move backwards
    }

    head->next = nullptr;       // now this be tail node
    head = new_head;            // change the head
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Sum of list by recursion, private helper function
int LinkedList::sum_of_list(Node* node){
    // if list is empty
    if(node == nullptr)
        return 0;
    
    return node->val + sum_of_list(node->next);
}

// public function without perameters
int LinkedList::sum_of_list(){
    return sum_of_list(head);
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int main(){
    LinkedList l;

    // add vals to list
    l.push(2);
    l.push(10);
    l.push(2);
    l.push(6);

    l.display();

    cout << "Sum: " << l.sum_of_list() << endl;

    return 0;
}