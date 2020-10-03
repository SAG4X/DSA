// C++ program for implementation of BoyerMoore pattern searching algorithm 

#include <bits/stdc++.h>
using namespace std;

void bmSearch(string pattern, string text) {
    int h = text.length(); 
    int n = pattern.length();

    int i = n-1;
    int j = n-1;
    int k = 0;
    // Preprocess - Bad Character rule
    // concept of the right most occurrence of each letter
    int *tb = new int[n];
    for(int i=0; i<n; ++i) 
        tb[pattern[i]] = i;

    while(i<h) {
        if(text[i]==pattern[j]) {
            if(j==0)
                cout << i << '\n';
            i--;
            j--;
        } else {
            k = tb[i];
            i += n - min(j, k+1);
            j = n -1;
        }

    }
}



int main() {
    string text = "abcdeSSjklfghijSlmnopqjkXXXl";
    string pattern = "jkl";
 
    bmSearch(pattern, text);
}

