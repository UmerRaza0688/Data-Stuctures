// Max_Heapify or MaxHeap, HeapSort
#include <iostream>
using namespace std;

// heapify function or MaxHeap, with little changin it can be MinHeap
void heapify(int arr[], int size, int root){
    // this fun deals with every node, like it's a whole tree
    // this heapify function will MaxHeap the 'root' node, in arr with total 'size' node  
    int maximum = root;     // initial max is root
    int left = 2*root+1;    // left node of root 
    int right = 2*root+2;    // right node of root

    // here root, maximum, left, right are considered as indexes not actual values
    // they will be change around some conditions

    // if after evaluating left became greater then size then, arr is not complete binary tree
    if (left < size and arr[left] > arr[maximum])  // it will perform MinHeap Ops if > to <
        maximum = left;

    // if after evaluating left became greater then size then, arr is not complete binary tree
    if (right < size and arr[right] > arr[maximum]) // it will perform MinHeap Ops if > to <
        maximum = right;

    // if maximum changes
    if (maximum != root){
        swap(arr[maximum], arr[root]);
        //  recurssive call to manage if swapping change the analogy of heap
        heapify(arr, size, maximum);
    }    
}

// Building heap, from any given list with the help of heapify function
void build_heap(int arr[], int size){
    // Construct heap from any given list by repeatedly calling heapify from bottom-to-top

    for(int i=size/2; i>=0; i--){
        // in complete BST, half nodes must be the leaf nodes, so no need to heapify them
        heapify(arr, size, i);  // ith element in array will be root
    }
}

// Heap sort function
void HeapSort(int arr[], int size){
    // steps for sorting using HeapSort algorithm

    // step 1: build MaxHeap of given array
    build_heap(arr, size);

    // traverse through array, in reverse order
    for(int i=size-1; i>=0; i--){
        // root of heap will always be maximum in the heap, so replace root with the last node
        swap(arr[i], arr[0]);
        // heapify root element again but only until ith element, 
        // after every iteration drop the maximum val from heap, don't include it
        heapify(arr, i, 0);
    } 
}

int main(){
    int arr[] = {9, 8, 1, 2, 1, 7, 3, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    // build_heap(arr, size);

    HeapSort(arr, size);

    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;    

    return 0;
}