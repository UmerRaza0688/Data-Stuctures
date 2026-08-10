// here we will merge two or more sorted arrays and also the final will be sorted also
#include <iostream>
using namespace std;

int* Merge(int arr1[], int size1, int arr2[], int size2){
    int size3 = size1 + size2;
    int *arr3 = new int[size3];

    int i = 0, j = 0, k = 0;

    // Logic is
    while(i < size1 and j < size2){ // until one array must complete
        if(arr1[i] < arr2[j]){      // compare elements of both, put smaller in 3rd array
            arr3[k] = arr1[i];      
            k++; i++;
        }
        else {
            arr3[k] = arr2[j];
            k++; j++;
        }
    }

    // handle the case if one array completed, and other have elements remaining in it
    // if array 1 has elements, condition will be true else false, control move to other loop
    while(i < size1){
        arr3[k] = arr1[i];
        k++; i++;
    }

    while(j < size2){
        arr3[k] = arr2[j];
        k++; j++;
    }

    return arr3;
}

int main(){
    int arr1[] = {2, 4, 7, 8};
    int arr2[] = {1, 5, 8, 10, 13, 15};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // store the address of result array
    int *merged_arr = Merge(arr1, size1, arr2, size2);
    int size3 = size1 + size2;
    
    for(int i=0; i<size3; i++){
        cout << merged_arr[i] << " ";
    }
    cout << endl;

    delete [] merged_arr;

    return 0;
}