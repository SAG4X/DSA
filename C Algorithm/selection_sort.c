#include<Stdio.h>

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	
}

void selection_sort(int array[],int n);

int main(){
	
	int a[]={5,4,2,1,6,0,9,34,54,7};
	int n=sizeof(a)/sizeof(a[0]);
	
	selection_sort(a,n);
	
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

void selection_sort(int array[],int n){
	
	int i,j;
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(array[j]<array[i]){
				min=j;
			}
		}
	swap(&array[min],&array[i]);
	}
}
