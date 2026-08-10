// Merge Sort Algorithm by recursion
#include <iostream>
using namespace std;

// Helper function of mergeSort, to merge sorted parts of given array
void Merge(int arr[], int l, int mid, int h){
    int i = l, j = mid+1, k = 0;    // assign specific indexes to i, j, k
    int *brr = new int[h];         // create a aux array, to store sorted elements, of same size

    while(i <= mid && j <= h){      // sort until one part of array, is complete
        if(arr[i] < arr[j])
            brr[k++] = arr[i++];    // copy and increement
        else
            brr[k++] = arr[j++];    // copy and increement
    }

    // if there are remaining elements in any part of array
    // if in first half
    while(i <= mid)
        brr[k++] = arr[i++];        // copy and increement
    
    // if in second half
    while(j <= h)
        brr[k++] = arr[j++];        // copy and increement

    // Now put all sorted elements back into arr from brr
    for(int i=l; i<=h; i++)
        arr[i] = brr[i-l];

    // free allocated memory
    delete [] brr;
}

// merge_Sort
void mergeSort(int arr[], int l, int h){
    // base case, if low >= high, also for invalid index & for empty array
    if (l >= h)  return;
    
    // mid of array, we will sort it by dividing it
    int mid = (l+h) / 2;

    // calling recursively, for left & right side of array sepratley
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, h);
    // we get sorted parts, merge them
    Merge(arr, l, mid, h);
}

int main() {
    int arr[] = {9, 8, 1, 2, 1, 7, 3, 11};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, size-1);

    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;    

return 0;
}