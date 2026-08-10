#include <iostream>
using namespace std;

// Insertion sort
void InsertionSort(int arr[], int &size){
    // go through all elements (except first)
    // now pick element, Call it Key
    // Each time key will be inserted in its place
    // At each itration, stuff less then i would be sorted already

    for(int i=1; i<size; i++){

        int key = arr[i];   // hold the key

        // start comparing keys to things on its left
        // stop when less or equal value found (or we reach left end)

        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];  // shift val to right, until val come less then or equal to key
            j--;
        }
        arr[j+1] = key;         // place key in free slot, (j+1 because we decreement j above)
    }
}


int main() {
     int *arr = new int[]{12, 7, 4, 10, 1};
    int size = 5;

    // Sorting
    InsertionSort(arr, size);



    // print array
    cout << "Sorted array: " << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}