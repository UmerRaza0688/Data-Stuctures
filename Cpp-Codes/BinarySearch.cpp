// Binary search
// Note, array must sorted before
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    // keep searching until condition false
    while (start <= end) {
        int mid = (start + end) / 2;  // find middle index

        // check if middle element is the key
        if (arr[mid] == key) {
            return mid;   // found
        }
        // if key is bigger then mid element, search right half
        else if (arr[mid] < key) {
            start = mid + 1;        // start will be update
        }
        // if key is smaller, search left half
        else {
            end = mid - 1;          // end will be update
        }
    }

    return -1;  // not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // must be sorted
    int size = 5;
    int key = 40;

    int result = binarySearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}