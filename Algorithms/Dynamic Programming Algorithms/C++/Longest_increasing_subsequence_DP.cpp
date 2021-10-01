#include<bits/stdc++.h>
using namespace std;
int longestSubsequence(int n, int a[]){
    
   int dp[n];
   for(int i=0;i<n;i++) dp[i]=1;
   
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<i;j++)
       {
           if(a[i]>a[j])
           {
               dp[i]=max(dp[i],1+dp[j]);
           }
       }
   }
   int m=dp[0];
   for(int i=0;i<n;i++) m=max(m,dp[i]);
   return m;
    
}
int main()
{
	int a[]={1,4,2,6,4,7,8,9};
	cout<<longestSubsequence(8,a);
}
