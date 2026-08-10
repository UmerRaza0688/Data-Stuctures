// Implementing a Doubly Linked List with it's basic operations
// Whereever the 'change' is commented, means there is change else is same like SinglyLinkedList 
#include <iostream>
using namespace std;

// Node class
class Node{
    public:
        int val;
        Node *next;
        Node *prev;

        // Initilizing node
        Node(int v = 0){
            val = v;
            next = nullptr;
            prev = nullptr;
        }

        // Free, allocated memory
        ~Node(){}
};

// Linked list class
class Doubly{
    private:
        Node* head;

    public:

    Doubly() { head = nullptr; }    // initilize head
    // Destructor
    ~Doubly() {
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
    //find
    int maxi();
    // remove min val
    void rem_min();
    // find duplicate
    int duplicate();
    // reverse the list
    void rev_list();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// List operations
    
// display the list
void Doubly::display() const{
    Node* temp = head;
    cout << "[ ";
    while(temp != nullptr){
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << "]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// put val at last
void Doubly::push(int val){
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
    new_node->prev = temp;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// pop/tail value at last
int Doubly::pop(){
    // case 1: if no node
    if(head == nullptr){
        throw runtime_error("List is empty");
    }

    // case 2: if one node
    if(head->next == nullptr){
        Node* temp = head;
        int val = head->val;
        delete temp;
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
    temp->prev = nullptr;
    int val = temp->val;
    delete temp;
    return val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// insert val at specific index
void Doubly::insert(int index, int val){
    Node* new_node = new Node(val);
   
    // case 1: if index is 0
    if(index == 0){
        new_node->next = head;

        if(head != nullptr){
            head->prev = new_node;
        }
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

    // if invalid index
    if(temp == nullptr){
        delete new_node;
        throw runtime_error("Invalid index!");
    }
    else{
        prev->next = new_node;
        new_node->prev = prev;

        new_node->next = temp;
        if(temp != nullptr){
            temp->prev = new_node;
        }
    } 
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove a specific value
void Doubly::remove(int val){

    Node* temp = head;

    // case 1: if no nodes
    if(head == nullptr){
        throw runtime_error("List is empty!");
    }

    // case 2: if sigle node
    if(temp->val == val){
        head = head->next;

        if(head->next != nullptr){
            head->prev = nullptr;
            delete temp;
        }
        return;
    }

    //case 3: if mid or end nodes
    Node* prev = nullptr;
    int counter = 0;
    while (temp != nullptr){
        if(temp->val == val){
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr){
        cout << "Value not found in the list!\n";
        return;
    }

    prev->next = temp->next;
    if(temp->next != nullptr){
        temp->next->prev = prev;
    }
    delete temp;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get length of list
int Doubly::length() const{
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
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get value at specific index
int Doubly::get(int index) const{
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
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// update value at specific index
void Doubly::update(int index, int val){
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
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


int Doubly::mini(){
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

// find max 
int Doubly::maxi(){
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

// remove min val
void Doubly::rem_min(){
    remove(mini());
}

// find duplicate
int Doubly::duplicate(){
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
    Node* temp = head;
    while(temp != nullptr){
        int key = temp->val;

        Node* tempo = temp->next;
        while(tempo != nullptr){
            if(tempo->val == key)
                return key;
        
            tempo = tempo->next;
        }

        temp = temp->next;
    }
 
    // not found
    return -1;
}

// reverse the list
void Doubly::rev_list(){
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
    temp = head;
    while(temp != nullptr){
        // simple
        // swap(temp->next, temp->prev);
        // temp = temp->prev;      //after swap, old next is now stored in prev

        // mannually swapped 
        Node* hold = temp->next;
        temp->next = temp->prev;
        temp->prev = hold;

        temp = hold;     // hold has store the old state of temp->next     
    }

    head = new_head;            // change the head
}

int main(){
    Doubly l;

    // add vals to list
    l.push(2);
    l.push(4);
    l.push(7);
    l.push(5);
    l.push(4);
    l.display();

    l.rev_list();
    l.display();

    cout << l.duplicate() << endl;

    return 0;
}