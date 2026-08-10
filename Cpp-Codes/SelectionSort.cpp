// Selection Sorting
#include <iostream>
using namespace std;

// Selection sort
void SelectionSort(int arr[], int &size){
    // go through each position one by one (no need to check last element)
    for(int i = 0; i < size-1; i++){

        // compare current element with everything to its right
        for(int j = i+1; j < size; j++){

            // if right element is smaller, swap it to the left position
            if(arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
        }
    }
}

int main(){
    int arr[] = {12, 7, 4, 10, 1};  // unsorted array
    int s = size(arr);      // size of array

    SelectionSort(arr, s);

    // after sorting, displaying array 
    cout << "Sorted array: ";
    for(int i = 0; i < s; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}