// RabinKarp string matching algorithm implemented in C++

#include <bits/stdc++.h>
using namespace std;

void rabin (string text, string pattern, int d, int q);

int main() {
    string text = "001010102203040402422442420429402940249940";
    string pattern = "42";

    rabin(text, pattern, 10, 101);
    
}

void rabin (string text, string pattern, int d, int q) {
    int n = text.length();
    int m = pattern.length();
    int h = (int)pow(d, m-1) % q;
    int t = 0;
    int p = 0;

    for(int i = 0; i < m; ++i) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(int s=0; s <= n-m; ++s) {
        if(p = t) {
            int i;
            for(i = 0; i < m; ++i) {
                if(pattern[i]!=text[s+i])
                    break;
            }
            if(i==m) {
                cout << s << '\n';
            }
        }
        if(s < n-m) {
            t = (d*(t - text[s]*h) + text[s+m]) % q;

            // if t is negative make it positive
            if (t<0)
                t = t + q;
        }
    }
}