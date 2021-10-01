#include <bits/stdc++.h> 

using namespace std;

int fib(int n){
    if(n==1)
        return 1;
    else if(n==0)
        return 0;    
    else{
        return fib(n-1)+fib(n-2);
    }    
}

int main()
{
	int t;
	cout << "Enter a number: ";
    cin >> t;
    cout << "[ ";
    for(int i = 0; i < t; i++){
        int n; 
        cout << fib(i) << ", ";
    }
    cout << "\b\b]";
    return 0;
}
