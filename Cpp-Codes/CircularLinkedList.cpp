// Implementing a Circular Linked List or Ring with it's basic operations
#include <iostream>
using namespace std;

//  class for single node
class Node{
    public:
        int val;
        Node* next;
    
        // Initilizing node
        Node(int v = 0){
            val = v;
            next = nullptr;
        }

        // Free, allocated memory
        ~Node() {}
};

// Circular Linked List class
class Ring{
    private:
        Node* head;

    public:
        Ring() { head = nullptr; }

    // destructor
    ~Ring(){
        if(head == nullptr) return;

        // find last node and break the circle
        Node* temp = head;
        while(temp->next != head)
            head = head->next;
        
        temp->next = nullptr;   // break the link

        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = nullptr;
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
    // find a val in list, return it's index else null
    int find(int val);
    // update value at specific index
    void update(int index, int val);
    // josephus problem
    int josephus_problem(int k);
    // get duplicates in list
    int duplicate();
    // Reverse the list
    void rev_list();
};
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// display the list
void Ring::display() const{
    Node* temp = head;

    cout << "[ " ;
    while(temp != nullptr){
        cout << temp->val << ", ";
        temp = temp->next;

        // change, only for cicular list
        if(temp == head)
            break;
    }
    cout << "]" << endl;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// methode for get last node    (cahnge)
Node* Ring::get_last(){
    // case 1: if no node 
    if(head == nullptr)
        return nullptr;

    // case 2: if one or more then one nodes
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;

    return temp;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// put val at last
void Ring::push(int val){
    Node* new_node = new Node(val);
    Node* last = get_last();

    // case 1: if no node
    if(head == nullptr){
        head = new_node;
        new_node->next = head;
        return;
    }

    // case 2: if one node
    if(head->next == head){
        head->next = new_node;
        new_node->next = head;
        return;
    }

    // case 3: if more then one nodes
    Node* temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = head;

    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove value at last
void Ring::pop(){
    Node* last = get_last();

    // case 1: if no node
    if(head == nullptr)
        throw runtime_error("can't pop, list is empty!");
    
    // case 2; if one node
    if(head->next == head){
        delete head;
        head = nullptr;
        return;
    }

    // case 3: if more then one nodes
    Node* temp = head;
    Node* prev = nullptr;

    while(temp->next != last->next){
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    delete temp;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// insert val at specific index
void Ring::insert(int index, int val){
    Node* new_node = new Node(val);
    Node* last = get_last();

    // if list is empty and index is > 0
    if(head == nullptr && index > 0)
        throw runtime_error("Cannot insert, list is empty.");

    // case 1: if index is 0
    if(index == 0){
        new_node->next = head;
        head = new_node;

        // also need to set the last pointer to new head (change)
        // if no node before
        if(last == nullptr)
            head->next = head;

        // if nodes are available    
        else
            last->next = head;

        return;
    }

    // if any other index
    Node* temp = head;
    Node* prev = nullptr;
    int counter = 0;

    while(counter < index){
        prev = temp;
        temp = temp->next;
        counter += 1;

        // stop if ring is completed
        // if(temp == head)
        //     break;
    }

    new_node->next = temp;
    prev->next = new_node;

    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// remove a specific value
void Ring::remove(int val){
    Node* last = get_last();
    Node* temp = head;

    // if node before
    if(head == nullptr){
        throw runtime_error("List is already empty!");
    }

    // if index is zero
    if(head->val == val){
        if(head->next == head){
            delete head;
            head = nullptr;     // just one node
        }
        else{    
            Node* del_head = head;  // store old head 

            head = head->next;  // if more then one node
            last->next = head;

            delete del_head;
        }
        
        return;
    }

    // case 3: if value match at any other index
    Node* prev = temp;
    temp = temp->next;

    while(temp != last->next){
        if(temp->val == val)    // value found, break
            break;

        prev = temp;
        temp = temp->next;
    }
    // val not found
    if(temp == last->next)
        return;

    prev->next = temp->next;

    delete temp;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// void removeAt
void Ring::removeAt(int index){
    Node* last = get_last();
    Node* temp = head;

    // if node before
    if(head == nullptr){
        throw runtime_error("List is already empty!");
    }

    // if index is zero
    if(index == 0){
        if(head->next == head)
            head = nullptr;
        else{
            Node* del_head = head;       // store old head

            head = head->next;
            last->next = head;

            delete del_head;
        }
        
        return;
    }

    // if any other index
    Node* prev = temp;
    int counter = 0;

    while(counter < index){
        prev = temp;
        temp = temp->next;
        counter += 1;

        // break if itration is complete
        if(temp == last->next)
            break;
    }

    // break link & clear node    
    prev->next = temp->next;

    delete temp;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get length of list
int Ring::length() {
    Node* last = get_last();

    // if no node
    if(head == nullptr)
        return 0;

    // if one node
    if(head->next == head)
        return 1;

    // if more then one node
    Node* temp = head->next;
    int counter = 1;
    
    while(temp != last->next){
        temp = temp->next;
        counter += 1;
    }

    return counter;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// get value at specific index
int Ring::get(int index) const{
    // if no node
    if(head == nullptr)
        throw runtime_error("List, is empty!");

    // if one node
    if(head->next == head && index == 0)
            return head->val;

    // for others
    Node*  temp = head;
    int counter = 0;

    while(counter < index){
        temp = temp->next;
        counter += 1;
    }

    return temp->val;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// find a val in list, return it's index else null
int Ring::find(int val){
    // if no node
    if(head == nullptr)
        throw runtime_error("List, is empty!");

    // if one node
    if(head->val == val){
        return 0;
    }

    // if more then one node
    Node* temp = head->next;
    int counter = 1;
    while(temp != head){
        if(temp->val == val)
            break;

        temp = temp->next;
        counter += 1;
    }

    if (temp == head)
        return -1;

    return counter;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// update value at specific index
void Ring::update(int index, int val){
    // if no node
    if(head == nullptr)
        return;

    // index is zero
    if(index == 0){
        head->val = val;
        return;
    }

    // index > 0
    Node* temp = head->next;
    int counter = 1;

    while(counter < index){
        temp = temp->next;
        counter += 1;
    }

    temp->val = val;
    return;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Josephus problem
int Ring::josephus_problem(int k){
    // if list is empty or k <= 0
    if (head == nullptr || k <= 0){
        return -1;   // similar to None in Python
    }

    Node *temp = head, *prev = nullptr;

    // continue until one node left
    while (temp->next != temp){

        // if k is 1
        if (k == 1){
            prev = temp;
            while (prev->next != temp){ 
                prev = prev->next;
            }
        }
        // if k > 1
        else{
            for (int i = 0; i < k - 1; i++){   // due to 0 index base, k is k-1
                prev = temp;
                temp = temp->next;
            }
        }

        cout << "Removed: " << temp->val << endl;

        prev->next = temp->next;   // break the link, release the kth node

        Node* del_temp = temp;     // store node to delete
        temp = temp->next;         // move temp to next node, after removing kth node
        delete del_temp;           // free memory
    }

    head = temp;                  // update head
    return temp->val;             // return master node
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// find duplicate
int Ring::duplicate(){
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
    Node* temp = head;
    while(temp->next != head){
        int key = temp->val;

        Node* tempo = temp->next;
        while(tempo != head){
            if(tempo->val == key)
                return key;
        
            tempo = tempo->next;
        }

        temp = temp->next;
    }
 
    // not found
    return -1;
}
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// reverse the linked list
void Ring::rev_list(){
    // if empty or sinlge val
    if(head == nullptr) return;
    if(head->next == head) return;

    // get len of list
    Node* temp = head;
    int len = 1;
    while(temp->next != head){
        temp = temp->next;
        len += 1;
    }

    // 1st: get tail and make it new head
    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* new_head = temp;

    // now reverse
    Node* processing = new_head;

    for(int i = 0; i < len-1; i++){
        temp = head;

        while(temp->next != processing){
            temp = temp->next;
        }
        processing->next = temp;
        processing = temp;
    }

    head->next = new_head; 
    head = new_head;
}


int main() {
    Ring r;

    r.insert(0,1);
    r.insert(1, 2);
    r.insert(2, 3);
    r.insert(3, 4);
    r.insert(4, 1);
    r.insert(5, 6);


    cout << r.duplicate() << endl;

    
}