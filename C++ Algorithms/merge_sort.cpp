#include<iostream>
using namespace std;


void Merge(int arr[],int l,int r,int m){
	int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort(int *a,int from,int to){
	int mid;
	if(from<to){
		mid = (from +to)/2;
		
		MergeSort(a,from, mid);
		MergeSort(a,mid+1,to);
		
		Merge(a,from,to,mid);
	}
}

int main(){
	int a[] = { 12, 34, 8, 11, 89, 45, 27, 55};
	//Merge Sort is Sorting Algorith which is using the divide and conquor methodology to sort
	//Call Merge Sort
	MergeSort(a,0,7);
	
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}

