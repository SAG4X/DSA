#include<Stdio.h>

void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	
}

void bubble_sort(int array[],int n);

int main(){
	
	int a[]={1,2,4,3,0,6,7,8,12,11}; 		//change as pleased
	int n=sizeof(a)/sizeof(a[0]);
	
	bubble_sort(a,n);
	
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}

void bubble_sort(int array[],int n){
	
	int i,j,k;
	for(i=0;i<n-1;i++){
		for(j=n-1;j>i;j--){
			if(array[j]<array[j-1]){
				swap(&array[j],&array[j-1]);
			}
		}
	}
}
