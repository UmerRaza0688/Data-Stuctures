#include <iostream>
#include "ArrayList.cpp"

using namespace std;

int main(){
    List l;

    // insert at end
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.display();   // [10 20 30]

    // insert at index
    l.insert(1, 15);
    l.display();   // [10 15 20 30]

    // remove
    l.remove(2);
    l.display();   // [10 15 30]

    // pop
    l.pop();
    l.display();   // [10 15]

    // find
    cout << "Index of 15: " << l.find(15) << endl;

    // update
    l.update(1, 50);
    l.display();   // [10 50]

    // get
    cout << "Current value: " << l.get() << endl;

    // navigation
    l.start();
    cout << "Start: " << l.get() << endl;

    l.end();
    cout << "End: " << l.get() << endl;

    l.back();
    cout << "Back: " << l.get() << endl;

    return 0;
}