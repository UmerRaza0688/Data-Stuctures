#include <iostream>
using namespace std;

// class for single node
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int v = 0) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

// class of Doubly connected Ring
// Circular Linked List class
class doubly_ring{
    private:
        Node* head;

    public:
        doubly_ring() { head = nullptr; }

    // destructor
    ~doubly_ring(){
        if(head == nullptr) return;

        // find last node and break the circle
        Node* temp = head;
        while(temp->next != head)
            head = head->next;
        
        temp->next = nullptr;   // break the link, by next
        head->prev = nullptr;   // break the link, by prev

        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // List operations

    // display the list
    void display() const;
    // methode for get last node    (cahnge)
    Node* get_last();
    // put val at last
    void push(int val);
    // remove value at last
    void pop();
    // insert val at specific index
    void insert(int index, int val);
    // remove a specific value
    void remove(int val);
    // void removeAt
    void removeAt(int index);
    // get length of list
    int length();
    // get value at specific index
    int get(int index) const;
    // update value at specific index
    void update(int index, int val);
    // josephus problem
    int josephus_problem(int k);
    // find duplicate
    int duplicate();
    // reverse list
    void rev_list();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// to print ring
void doubly_ring::display()const {
    Node* temp = head;

    cout << "[ ";
    while (temp != nullptr) {
        cout << temp->val << ", ";
        temp = temp->next;

        if (temp == head) {           // diffirent for Ring (change), get out of loop
            break;
        }
    }
    cout << "]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// to get last node of circular list,   (change)
Node* doubly_ring::get_last() {
    // if no node
    if (head == nullptr) {
        return nullptr;
    }

    // case 3: if more then one nodes, also cover case 2(one node)
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    return temp;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to push val at last
void doubly_ring::push(int val) {
    Node* new_node = new Node(val);

    // case 1: if no node
    if (head == nullptr) {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;       // (change)
        return;
    }

    // case 2: if atleast one node
    if(head->next == head){

        head->next = new_node;
        new_node->next = head;

        new_node->prev = head;       // (change)
        head->prev = new_node;       // (change)
        return;
    }

    // case 3: if more then one node
    Node* temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;                // (change)

    new_node->next = head;
    head->prev = new_node;           // (change)
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to pop val at last
void doubly_ring::pop() {
    // case 1: if no node 
    if(head == nullptr){
        throw runtime_error("No node, list is empty");
    }

    // case 2: if one node
    if(head->next == head){
        delete head;
        head = nullptr;
        return;
    }

    // case 3: if more then one nodes
    Node* temp = head;
    Node* prev = nullptr;

    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    head->prev = prev;           // (change)
    delete temp;

    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to insert val, at specific index
void doubly_ring::insert(int index, int val) {
    Node* new_node = new Node(val);
    Node* last = get_last();

    // if head is None and index is greater then 0
    if(head == nullptr && index > 0){
        throw runtime_error("Cannot insert at index at " + to_string(index) + " because list is empty!");
    }

    // case 1: if index is zero
    if(index == 0){
        new_node->next = head;
        new_node->prev = last;            // (change)

        head = new_node;

        // also need to set the last pointer to new head (change)
        if(last == nullptr){
            head->next = head;      // if no node before
            head->prev = head;
        } 
        else{
            last->next = head;           // if one node exist
            new_node->next->prev = new_node;   // old head prev, to new head(new_node)
        }

        return;
    }

    // case 2: if any other index
    Node* temp = head;
    int counter = 0;
    Node* prev = nullptr;

    while(counter < index){
        prev = temp;
        temp = temp->next;
        counter += 1;
    }

    new_node->next = temp;
    temp->prev = new_node;            // (change)

    prev->next = new_node;
    new_node->prev = prev;            // (change)

    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to remove a specific val
void doubly_ring::remove(int val) {

    Node* temp = head;
    Node* last = get_last();     

    // case 1: if no node
    if(head == nullptr){
        throw runtime_error("No node, can't remove!");
    }

    // case 2: if val matches at first node 
    if(head->val == val){
        if(head->next == head){
            delete head;
            head = nullptr;    // just one node
        } 
        else{
            Node* del_head = head;       // store old head

            head = head->next;
            last->next = head;
            head->prev = last;       // (change)

            delete del_head;            //delete it
        }

        return;
    }

    // case 3: if value match at any other index
    Node* prev = temp;
    temp = temp->next;

    while (temp != last->next) {
        if (temp->val == val) {
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    // val not found 
    if (temp == last->next) {
        return;
    }

    prev->next = temp->next;
    temp->next->prev = prev;           // (change)
    delete temp;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to remove val at specific index
void doubly_ring::removeAt(int index) {
    Node* last = get_last();
    Node* temp = head;

    // if list is empty
    if (head == nullptr) {
        throw runtime_error("list is empty!");
    }

    // if index is zero
    if (index == 0) {
        if (last == head) {
            delete head;
            head = nullptr;
        } else {
            Node* del_head = head;       // store old head

            last->next = head->next;
            head = last->next;
            head->prev = last;       // (change)

            delete del_head;
        }

        return;
    }

    // other indices
    int counter = 0;
    Node* prev = nullptr;

    while(counter < index){
        prev = temp;
        temp = temp->next;
        counter += 1;

        if(temp == last->next){
            return;    
        }
    }

    prev->next = temp->next;
    temp->next->prev = prev;           // (change)
    delete temp;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to get val at specific index
int doubly_ring::get(int index) const{
    // case1 : if no node
    if (head == nullptr) {
        return -1;
    }

    // case 2: if one node
    if (head->next == head) { 
        return head->val;
    }

    // case 3: others
    Node* temp = head;
    int counter = 0;

    while (counter < index) {
        temp = temp->next;
        counter += 1;
    }

    return temp->val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to get lenght of list
int doubly_ring::length() {
    Node* last = get_last();

    // case 1: if no node
    if (head == nullptr) {
        return 0;
    }
    
    // case 2: if one node
    if (head->next == head) {
        return 1;
    }

    // case 3: if more then one node
    Node* temp = head->next;
    int counter = 1;

    while (temp != last->next) {
        temp = temp->next;
        counter += 1;
    }
    
    return counter;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// fun to update val at specific index
void doubly_ring::update(int index, int val) {
    // case 1: if no node
    if (head == nullptr) {
        throw runtime_error("No node, can't update!");
    }
    
    // case 2: if index is 0
    if (index == 0) {
        head->val = val;
        return;
    }
    
    // case 3: any other index
    Node* temp = head->next;
    int counter = 1;

    while (counter < index) {
        if (temp->val == val) {
            break;
        }

        temp = temp->next;
        counter += 1;
    }

    temp->val = val;

    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Josephus problem
int doubly_ring::josephus_problem(int k) {
    // if list is empty or k <= 0
    if(head == nullptr || k <= 0){
        return -1;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // continue until one node left
    while (temp->next != temp) {

        // if k is 1
        if(k == 1){
            prev = temp;
            while(prev->next != temp) { 
                prev = prev->next;
            }
        }
        // if k > 1
        else{
            for(int i = 0; i < k - 1; i++) {
                prev = temp;
                temp = temp->next;
            }
        }

        cout << "Removed: " << temp->val << endl;
        prev->next = temp->next;   // break the link, release the kth node
        temp->next->prev = prev;   // (change)

        Node* del_temp = temp;      // store old temp to delete it
        temp = temp->next;
        delete del_temp;
    }

    head = temp;
    return temp->val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// find duplicate
int doubly_ring::duplicate(){
    // list is empty
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return 0;
    }

    // if single value
    if(head->next == head){
        cout << "List has only one value!" << endl;
        return head->val;
    }

    // else case
    int key = head->val;
    Node* temp = head->next;
    while(temp != head){
        Node* tempo = temp->next;

        while(tempo != head){
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

// reverse the list
void doubly_ring::rev_list(){
    // if list is empty or single valued, list is reversed
    if(head == nullptr) return;
    if(head->next == nullptr) return;

    // if two or more vals
    // 2nd: get the last node & make it new_head
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* new_head = temp;      // tail is the new_head 

    // reverse the list
    temp = head;
    do{
        // simple
        // swap(temp->next, temp->prev);
        // temp = temp->prev;      //after swap, old next is now stored in prev

        // mannually swapped 
        Node* hold = temp->next;
        temp->next = temp->prev;
        temp->prev = hold;

        temp = hold;     // hold has store the old state of temp->next     
    }while(temp != head);

    head = new_head;            // change the head
}

int main(){
    doubly_ring l;

    // add vals to list
    l.push(4);
    l.push(9);
    l.push(2);
    l.push(10);
    l.push(2);
    l.push(7);

    l.display();

    l.rev_list();
    l.display();

    return 0;
}