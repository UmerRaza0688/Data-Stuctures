#include <iostream>
#include <string>

using namespace std;

// Linear search
bool linearSearch(int arr[], int &size, int &x){
    for(int i = 0; i < size-1; i++){
        if(arr[i] == x) {
            return true;
        }
    }
    return false;
}

// Selection sort
int sortArr(int arr[], int &size){

    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[i]){
                swap(arr[j], arr[i]);
            }
        }
    }
    return *arr;
}

// Binary search
bool binarySearch(int arr[], int &size, int &x){
    int start = 0;
    int end = size[arr] - 1;

    for(int i = 0; i < size; i++){
        int midle = (start + end) / 2;
        if(x == arr[midle]){
            return true;
        }
        else if(x < arr[midle]){
            end = midle - 1;
        }
        else{
            start = midle + 1;
        }
    }
    return false;
}



int main() {
    int arr[] = {3, 5, 2, 8, 7, 9, 0};
    int arrSize = size(arr);      // size of array

    int targetValue = 4;

    cout << linearSearch(arr, arrSize, targetValue) << endl;

    sortArr(arr, arrSize);

    // cout << binarySearch(arr, arrSize, targetValue) << endl;


    return 0;
}