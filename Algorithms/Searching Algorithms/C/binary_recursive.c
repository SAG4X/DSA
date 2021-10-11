//recursive binary search
#include <stdio.h>

int binarySearch(int arr[],int l,int r,int x){
    if(r>=l){
        int mid=l+(r-1)/2;

        if(arr[mid]==x)
            return mid;
        if(arr[mid]>x)
            return binarySearch(arr,l,mid-1,x);
        
        return binarySearch(arr,mid+1,r,x);
    }

    return -1;
}

void main(){
    int n;
    printf("Enter number of elements in the array: \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element: \n");
        scanf("%d",&arr[i]);
    }
    
    int x;
    printf("Enter the number you want to search: \n");
    scanf("%d",&x);
    int result = binarySearch(arr,0,n-1,x);
    (result==-1) ? printf("Element is not present in the array") : printf("Element is present at index %d",result);
}