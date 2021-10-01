#include <stdio.h>
int GCD(int, int);
int main(){
	int num1, num2;
	printf("Enter a number to find GCD: ");
	scanf("%d", &num1);
	printf("Enter another number to find GCD: ");
	scanf("%d", &num2);
	printf("GCD of %d and %d : %d", num1, num2, GCD(num1, num2));
}
int GCD(int a, int b){
	if(a == 0 || b == 0){
		return 0;
	}else if(a == b){
		return a;
	}else if(a > b){
		return GCD(a-b,b);
	}else if(b > a){
		return GCD(a,b-a);
	}
}
