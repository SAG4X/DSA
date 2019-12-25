
def selectionSort(array):
    n=len(array)
    for i in range(0,n-1):
        min=i
        for j in range(i,n):
            if(array[j]<array[i]):
                min=j
        temp=array[min]       #swapping process
        array[min]=array[i]
        array[i]=temp
    return array

a=[1,2,4,3,0,6,7,8,12,11] #edit as needed
print(selectionSort(a))
