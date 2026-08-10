# Bubble Sort, good version
def BubbleSort2(arr):
    l = len(arr)
    for i in range(l - 1):
        swapped = False
        for j in range(l - i - 1):
            # Exchanging values
            if(arr[j] > arr[j + 1]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True      # if swap occure flage change
        # if swap is not occured break the loop
        if(swapped is False):
            break
    # return array
    return arr

# Bubble Sort, bad version
def BubbleSort1(arr):
    l = len(arr)
    for i in range(l - 1):
        for j in range(l - i - 1):
            # Exchanging values
            if(arr[j] > arr[j + 1]):
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
    return arr
# Selection Sort, bad version
def SelectionSort1(arr):
    n = len(arr)

    for i in range(n-1):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        min_value = arr.pop(min_index)
        arr.insert(i, min_value)
    return arr
# Selection Sort, good version
def SelectionSort2(arr):
    n = len(arr)

    for i in range(n-1):
        for j in range(i+1, n):
            if arr[j] < arr[i]:
                arr[j], arr[i] = arr[i], arr[j]  
    return arr
# Insertion sort
def insertionSort(arr):
    n = len(arr)

    i = 1
    while i < n:
        temp = arr[i]
        
        j = i - 1
        while j >= 0:
            if arr[j] > temp:
                arr[j+1] = arr[j]
            else:
                break
            
            j -= 1
        
        arr[j+1] = temp
        i += 1

    return arr




my_array = [12, 7, 4, 10, 1]



# Bubble Sort
print("Sorted array:", SelectionSort2(my_array))