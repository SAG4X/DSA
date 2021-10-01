def mergeSort(array):
    if(len(array)>1):       #only proceed if array size is greater than 1
        
        m=len(array)//2
        left=array[:m]
        right=array[m:]
        mergeSort(left)
        mergeSort(right)

        i=j=k=0
        while(i<len(left) and j<len(right)):  #go through the 2 arrays
            if(left[i]<right[j]): 
                array[k] = left[i] 
                i+=1
            else: 
                array[k] = right[j] 
                j+=1
            k+=1
    
        while(i<len(left)):     #if left array has left over elements
            array[k]=left[i]
            i+=1
            k+=1

        while(j<len(right)):    #if right array has left over elements
            array[k]=right[j]
            j+=1
            k+=1

a=[1,2,4,3,0,6,56,7,8,12,11] #edit as needed
mergeSort(a)
print(a)
