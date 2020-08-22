#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "<< i << endl; 
    } 
} 

//my method for naive
void newSearch(string a,string b){
	
	//Naive Matching
	for(int i = 0;i<=a.length()-b.length();i++){
		int j;
		for(j =0;j<b.length();j++){
			if(a[i+j]!= b[j]){
				break;
			}
		}
		if(j==b.length()){
			cout<<"Pattern found at index : "<<i<<endl;
		}
	}
	
}


int main(){
	cout<<"Naive String Matching"<<endl;
	char txt[] = "ABCDABSDTHGFTHUYTABCDUIUXANGULARABSD";
	char pat[] = "ABSD";
	search(pat,txt);
	cout<<endl;
	string text = "AABBACABCBACCBAABCABCCBA";
	string pattern = "ABC";
	
	newSearch(text,pattern);
	return 0;
}
