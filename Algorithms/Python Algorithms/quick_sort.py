def sort(array):

    def partition(arr,low,high): 
        i = ( low-1 )         
        pivot = arr[high]    #take last element as pivot 
    
        for j in range(low , high): 
    
            # If current element is smaller than the pivot 
            if   arr[j] < pivot: 
            
                # increment index of smaller element 
                i = i+1 
                arr[i],arr[j] = arr[j],arr[i] 
    
        arr[i+1],arr[high] = arr[high],arr[i+1] 
        return ( i+1 ) 
    

    def quickSort(array,low,high): 
        if low < high:  
            point = partition(array,low,high) 
    
            # Separately sort elements 
            quickSort(array, low, point-1) 
            quickSort(array, point+1, high) 
    
    n = len(array) 
    quickSort(array,0,n-1) 
    return array
    