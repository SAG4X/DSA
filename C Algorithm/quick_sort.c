#include<stdio.h>

void swap(int *x,int *y){
	
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int array[],int low,int high){
	
	int pivot=array[high];		//preferred position for pivot is last element
	int i=(low-1);
	int j;
	
	for(j=low;j<=high-1;j++){
		
		if(array[j]<pivot){
			i++;				//increments postion to adjust pivot position
			swap(&array[i],&array[j]);
		}
	}
	swap(&array[i+1],&array[high]);
	
	return (i+1);			//returns pivot position
}

void quick_sort(int array[],int low,int high){
	
	if(low<high){
		
		int index;
		index=partition(array,low,high);		//getting pivot to seperate array into 2 sub-parts for divide and conquer
		//printf("%d\n",index);
		quick_sort(array,low,index-1);
		quick_sort(array,index+1,high);
		
	}
}

void print_array(int array[],int n){
	
	int i;
	for(i=0;i<n;i++){		//displaying procedure
		printf("%d ",array[i]);
	}
}
int main(){
	
	int arr[]= {8,2, 11, 1, 6, 5};  				//change array as needed
    int n= sizeof(arr) / sizeof(arr[0]);  
    quick_sort(arr,0,n-1);  
    print_array(arr,n);  
    return 0;
	
}
