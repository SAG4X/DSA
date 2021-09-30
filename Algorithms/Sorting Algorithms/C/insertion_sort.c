#include<Stdio.h>
void insertion_sort(int array[],int n);

int main(){
	int a[]={5,4,2,1,6,0,9,34,54,7};
	int n=sizeof(a)/sizeof(a[0]);
	insertion_sort(a,n);
	return 0;
}

void insertion_sort(int array[],int n){
	
	int i,j;
	
	for(i=1;i<n;i++){
		int temp=array[i];
		for(j=i;j>0 && temp<array[j-1];j--){
			array[j]=array[j-1];
			
		}
		array[j]=temp;
	}
	
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	
}
