#include<iostream>
#include<array>
using namespace std;

// bubble sort
void BubbleSort(int arr[], int &size){
    for(int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // if not any swap, break the loop
        if(swapped == false){
            break;
        }
    }
}


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

    // sort left part (elements smaller than pivot)
    QuickSort(arr, fst, j);

    // sort right part (elements bigger than pivot)
    QuickSort(arr, i, lst);
}




int main(){
    int *arr = new int[]{12, 7, 4, 10, 1};
    int size = 5;

    // Sorting
    // SelectionSort(arr, size);
    // BubbleSort(arr, size);
    InsertionSort(arr, size);
    // QuickSort(arr, 0, size - 1);




    // print array
    cout << "Sorted array: " << "[ ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}