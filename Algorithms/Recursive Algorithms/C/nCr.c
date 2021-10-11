  
//WAP to find nCr recursive
#include <stdio.h>

int factorial(int x){
    if (x==0)
        return 1;
    else
        return (x*factorial(x-1));
}

void main(){
    int n,c,r;
    printf("Enter the values of n and r: \n");
    scanf("%d %d",&n,&r);
    c = factorial(n)/(factorial(n-r)*factorial(r));
    printf("nCr = %d",c);
}
