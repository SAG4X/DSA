#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fact(int n){
    if(n==0)
        return 1;    
    else{
        return n*fact(n-1);
    }    
}

int main(){
    int t,i; 
    scanf("%d",&t);
    for(i = 0; i <= t; i++){
        int n; 
        printf("Factorial of %d is : %d\n", i, fact(i));
    }
    return 0;
}


