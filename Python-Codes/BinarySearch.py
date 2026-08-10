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

#Find the peak value of mountain
def peakVal(arr):
    low = 0
    high = len(arr) - 1

    while(low < high):
        mid = (high + low) // 2
        if arr[mid] < arr[mid+1]:
            low = mid + 1
        else:
            high = mid
    return low

#Find the first and last occurence ok key vlaue in list
def lastOcc(arr, key):
    low = 0
    high = len(arr) - 1

    while low < high:
        mid = high + low // 2

        if key is arr[mid]:
            ans = mid
            low = mid + 1
        elif key < arr[mid]:
            high = mid - 1
        elif key > arr[mid]:
            low = mid + 1
        else:
            return None
        
    return ans
def firstOcc(arr, key):
    low = 0
    high = len(arr) - 1

    while low < high:
        mid = high + low // 2

        if key is arr[mid]:
            ans = mid
            high = mid - 1
        elif key < arr[mid]:
            high = mid - 1
        elif key > arr[mid]:
            low = mid + 1
        else:
            return None
        
    return ans

#simple binary search
def BinarySearch(arr, item):
    low = 0
    high = len(arr) - 1

    while(low <= high):
        mid = (high + low) // 2
        guess = arr[mid]
        if item == guess:
            return guess
        elif item < guess:
            high = mid - 1
        else:
            low = mid + 1
    return None





arr = [1, 3, 5, 6, 8, 9, 13, 17]


# Get the pivot value from rotated sorted array
# arr1 = [4, 5, 6, 7, 0, 1, 2]
# print(f"Pivot value: {pivotVal(arr1)}")

# Get the peak value of mountain
# arr1 = [1, 3, 5, 6, 8, 7, 4, 1]
# print(f"Peak value: {peakVal(arr1)}")


# Count the occurence of key vlaue in list
# key = 9
# keyOcc = lastOcc(arr, key) - firstOcc(arr, key) + 1
# print(f"{key} repeated {keyOcc} time in list.")


# finding first and last occurence of key value
# key = 9
# print(f"First Occurence of {key} is at index {firstOcc(arr, key)}.")
# print(f"Last Occurence of {key} is at index {lastOcc(arr, key)}.")


# if BinarySearch(arr, 0):
#     print("Founded in the list")
# else:
#     print("Not found.")