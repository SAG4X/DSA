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
int getfib(int n){
    int i,sum=0,fibo_value;
    for(i=0;i<n;i++){
         fibo_value=fib(i);
        if(fibo_value%2==0 && fibo_value<=n)
            sum+=fibo_value;
    }
    return sum;
}
int main(){
    int t,i;
    int a0;
    int sum; 
    scanf("%d",&t);
    for(a0 = 0; a0 <= t; a0++){
        int n; 
        //scanf("%d",&n);
        //sum=getfib(a0++);
        printf("%d\n",fib(a0));
    }
    return 0;
}


