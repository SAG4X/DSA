
def selectionSort(array):
    n=len(array)
    for i in range(0,n-1):
        for j in range(i,n):
            if(array[j]<array[i]):
                temp=array[j]       #swapping process
                array[j]=array[i]
                array[i]=temp
    return array

a=[5,2,4,3,0,6,7,8,12,11] #edit as needed
print(selectionSort(a))
