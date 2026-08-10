#include <iostream>
using namespace std;


// Quick Sort
void QuickSort(int arr[], int fst, int lst){

    // base case: if section has 1 or no elements, nothing to sort
    if(fst >= lst) return;

    int i = fst, j = lst;   // i starts from left, j starts from right
    int pivot = arr[fst];   // pick first element as pivot

    // keep going until i and j cross each other
    while(i <= j){

        // move i right, skip elements already smaller than pivot
        while(arr[i] < pivot) i += 1;

        // move j left, skip elements already bigger than pivot
        while(arr[j] > pivot) j -= 1;

        // if i and j haven't crossed, swap and move both i++, j--
        if(i <= j){
            swap(arr[i], arr[j]);
            i += 1;
            j -= 1;
        }
    }
    // Get out from loop when, i & j cross eachother

    // sort left part (elements smaller than pivot)
    QuickSort(arr, fst, j);

    // sort right part (elements bigger than pivot)
    QuickSort(arr, i, lst);
}



int main(){
    int *arr = new int[]{12, 7, 4, 10, 1};
    int size = 5;

    
    QuickSort(arr, 0, size - 1);

    // print array
    cout << "Sorted array: " << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}