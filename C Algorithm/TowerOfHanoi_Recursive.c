#include<stdio.h>

void TowerOfHanoi(int n, char from, char to, char aux){
	if(n==1){
		printf("Move disk 1 from %c to %c \n",from,to);
	}else{
		TowerOfHanoi(n-1,from,aux,to);
		printf("Move disk %d from %c to %c \n",n,from,to);
		TowerOfHanoi(n-1,aux,to,from);
	}
}

int main(){
	int n;
	printf("Input the value for n : ");
	scanf("%d",&n);
	TowerOfHanoi(n,'A','C','B');
	
	
	return 0;
}
