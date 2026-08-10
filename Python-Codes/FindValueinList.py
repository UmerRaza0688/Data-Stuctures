# find the value it is in list or not

#Find the pivot in array
def pivotVal(arr):
    low = 0
    high = len(arr) - 1

    while low < high:
        mid = (low + high) // 2

        if arr[mid] >= arr[0]:
            low = mid + 1
        else:
            high = mid
    return low

# Searchin the number
def BinarySearch(arr, s, e, item):
    low = s
    high = e

    while(low <= high):
        mid = (high + low) // 2

        if item == arr[mid]:
            return mid
        elif item < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return None




arr = [4, 5, 6, 7, 0, 1, 2]
n = len(arr)-1
# number to be find
num = 9          

pivot = pivotVal(arr)

if num >= arr[pivot] and num <= arr[n-1]:
    print(f"At index: {BinarySearch(arr, pivot, n-1, num)}")
else:
    print(f"At index: {BinarySearch(arr, 0, pivot-1, num)}")