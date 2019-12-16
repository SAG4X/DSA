//find the sum of n elements using linked list
#include<stdio.h>
#include<stdlib.h>

int main(){
	int num,i,*ptr,sum=0;
	
	printf("Enter number of elements : ");
	scanf("%d",&num);
	
	ptr=(int*)malloc(num*sizeof(int));
	if(ptr==NULL){
		printf("Memory is not allocated sucessfully\n");
		exit(0);
	}else{
		printf("Enter the elements of array : ");
		for(i=0;i<num;i++){
			scanf("%d",ptr+i);
			sum+=*(ptr+i);
		}
		printf("Sum is = %d",sum);
		free(ptr);
	}
	return 0;
}
