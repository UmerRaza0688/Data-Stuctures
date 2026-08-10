// Implementing MaxHeap data structure using array 
#include <iostream>
using namespace std;

// heapify fun for MaxHeap
void heapify(int arr[], int size, int root){
    // Heapify the root element of arr which has 'size' elements in total

    int minimum = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    if(left < size && arr[left] < arr[minimum])
        minimum = left;
    
    if(right < size && arr[right] < arr[minimum])
        minimum = right;
        
    // if root is maximum is changed
    if(minimum != root){
        swap(arr[root], arr[minimum]);
        // recurssive call to manage if swapping change the analogy of heap
        heapify(arr, size, minimum);
    }    
}

// Build Heap Methode
void build_heap(int arr[], int size){
    //  Construct heap from any given array by repeatedly calling heapify from bottom-to-top

    for(int i=size/2-1; i>=0; i--)
        heapify(arr, size, i);
}

int main(){
    // int *arr = new int[10];
    int arr[] = {100, 5, 3, 2, 8, 15, 6, 102};

    build_heap(arr, 8);

    for(int i=0; i<8; i++)
        cout << arr[i] << " " ;
    cout << endl;

    

    return 0;
}