// Bubble Sorting
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    // Sorting
    for(int i = 0; i < size-1; i++) {
        bool swapped = false;       // check flag
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;     // if swap, flage change
            }
        }
        // if not any swap, break the loop
        // means the array is sorted
        if(!swapped){
            break;
        }
    }
}

int main(){
    int arr[] = {12, 7, 4, 10, 1};  // unsorted array
    int s = size(arr);      // size of array

    BubbleSort(arr, s);

    // after sorting, displaying array 
    cout << "Sorted array: ";
    for(int i = 0; i < s; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}