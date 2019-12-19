def bubbleSort(arr):
    n = len(arr)
 
    for i in range(n):      #Traversing through all the elements of the Array
 
        for j in range(0, n-i-1): # Comparing the first (n-i) elements because the last i elements are already in place
 
            # when traversing the array from 0 to n-i-1
            # if the element found is greater than
            # the next element, swap
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
 
# Driver code to test above
arr = [64, 34, 25, 12, 22, 11, 90]
 
bubbleSort(arr)
 
print ("Sorted array is:")
print (*arr, sep = ", ")
