#include <bits/stdc++.h> 

using namespace std; 

// get the factorial number(recusrive)
int fact(int n)
{
    if(n==0)
        return 1;    
    else{
        return n*fact(n-1);
    }    
}

int main()
{
    int t; 
    cout << "Enter a number to find factorial: ";
    cin >> t;
    cout << "Factorial of " << t << " is " << fact(t);
    return 0;
}
