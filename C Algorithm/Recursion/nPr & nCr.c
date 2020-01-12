#include<stdio.h>
int fact(int);
int main(){
	int n, r;
	printf("Enter n to find nPr & nCr: ");
	scanf("%d", &n);
	printf("Enter r to find nPr & nCr (r should be less than n): ");
	scanf("%d", &r);
	printf("\nP(%d,%d) = %d\n",n, r, fact(n)/fact(n-r));
	printf("C(%d,%d) = %d\n",n, r, fact(n)/fact(r)*fact(n-r));
	return 0;
}
int fact(int a){
	if (a==0)
		return 1;
	else
		return a*fact(a-1);
}
