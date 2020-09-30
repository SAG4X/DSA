// A Dynamic Programming solution for Rod cutting problem 
#include<stdio.h> 
#include<limits.h> 

using namespace std;

//-----Problem-----
//Given a rod of length n inches and a table of prices for i = 1,2,...n;
//detemine the maximum revenue rn 
//obtainable by cutting up the rod and selling the pieces
  
// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b)? a : b;} 
  
int cutRod(int price[], int n){ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (i = 1; i<=n; i++) 
   { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) 
         max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 
  
/* Driver program to test above functions */
int main(){ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int arr1[] = {1,5,8,9,10,17,17,20,24,30}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size)); 
    printf("Maximum Obtainable Value is %d\n", cutRod(arr1, size)); 
    getchar(); 
    return 0; 
} 
