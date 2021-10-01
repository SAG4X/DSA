#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int fib(int n){
    if(n==1)
        return 1;
    else if(n==0)
        return 0;    
    else{
        return fib(n-1)+fib(n-2);
    }    
}

int main(){
    int t, i;
    printf("Enter a number: ");
    scanf("%d",&t);
    printf("[ ");
    for(i = 0; i<t; i++){
        int n; 
        printf("%d, ",fib(i));
    }
    printf("\b\b]");
    return 0;
}
