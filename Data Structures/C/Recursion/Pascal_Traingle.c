#include<stdio.h>

int pascal(int,int);

int main(){
	int n=0,m=0,k=0;
	printf("Input the range to print pascal traingle : ");
	scanf("%d",&n);
	for(k=1; n>=k; k++){
		for(m=1; k>=m; m++){
			int f=pascal(k,m);
			printf(" %d ",f);
		}
		printf("\n");
		
	}
	return 0;
}

int pascal(int k,int m){
	if(m<0 || k<0 || m>k){
		return 0;
	}
	else if(m==1){
		return 1;
	}else{
		return pascal(k-1,m)+ pascal(k-1,m-1);
	}
}
