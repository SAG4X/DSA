#include<iostream>
#include<cstdlib>

using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int *arr,int left,int right){
	int l = left;
	int r = right-1;
	int size = right - left;
	
	if(size>1){
		int pivot = arr[rand()%size +1];
		while(l>r){
			while(arr[r] > pivot && r>l)
				r--;
			while(arr[l] < pivot && l<=r)
				l++;
		}
		if(l<r){
			swap(&arr[l],&arr[r]);
			l++;
		}
	}
	QuickSort(arr,left,l);
	QuickSort(arr,r,right);
}

int main(){
	int array[]={21,56,10,78,34,88};
	
	
	//quick sort use the divide and conquer method to sorting  
	QuickSort(array,0,7);//pass the relevent parameters
	
	for(int i=0;i<7;i++){
		cout<<array[i]<<" ";
	}
	
	return 0;	
}
