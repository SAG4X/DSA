def bubbleSort(array):

    n=len(array)
    for i in range(0,n):
        for j in range(i,n-i-1,-1):
            if(array[j]<array[j-1]):       
                array[j],array[j-1]=array[j-1],array[j]         #swapping process
    return array

a=[1,2,4,3,0,6,7,8,12,11] #edit as needed
print(bubbleSort(a))
