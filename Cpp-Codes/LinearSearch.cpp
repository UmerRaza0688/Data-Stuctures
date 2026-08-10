// Linear search
#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    // go through each element one by one
    for (int i = 0; i < size; i++) {
        // check if current element matches the key
        if (arr[i] == key) {
            return i;   // return index if found
        }
    }
    
    return -1;  // return -1 if not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int key = 30;

    int result = linearSearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}