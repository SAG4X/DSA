#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// get the factorial number(recusrive)
int fact(int n){
    if(n==0)
        return 1;    
    else{
        return n*fact(n-1);
    }    
}
// get the custom factorial number(non -recursive)
int getfib(int n){
    int i,sum=0,fibo_value;
    for(i=0;i<n;i++){
         fibo_value=fact(i);
        if(fibo_value%2==0 && fibo_value<=n)
            sum+=fibo_value;
    }
    return sum;
}
int main(){
    int t,i,a0; 
    scanf("%d",&t);
    for(a0 = 0; a0 <= t; a0++){
        int n; 
        printf("Factorial of %d is : %d\n",a0,fact(a0));
    }
    return 0;
}


