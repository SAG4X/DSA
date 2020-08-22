//Rabin karp is most suitable algorithm for this case.Hence,our text string is a bigger text
#include <iostream>
#include <sstream>
#include <bits/stdc++.h> 

using namespace std;

//our alphabet contains only 0-9 numbers
#define d 10

vector <int> matchIndex;
vector <int> queryIndex;
int point = 0;//global variable to point the index
int query = 0;//query number maintained by this variable

//Returns the birthday pi string(pattern)
string GenerateMyPi(){
	//year 1998 -> 98
	//month june -> 06
	//date 8th -> 08
	string a = "980608";
	return a;
}
int ResultSet(){
	cout<<"\nCheck "<<query<<" Queries"<<endl;
	cout<<"Number of Matchings : "<<matchIndex.size()<<endl;
	if(matchIndex.size()==0){
		cout<<"No matching found"<<endl;
	}else{
		for(int k =0;k<matchIndex.size();k++){
			//just because if add up last 5 digits we need to care about the query if it is in two queries
			if(matchIndex[k]%10 == 0 or matchIndex[k] >= 5){
				cout<<"Pattern found at index : "<<(queryIndex[k]*10-10)+matchIndex[k]<<endl;
			}else{
				cout<<"Pattern found at index : "<<queryIndex[k]*10+matchIndex[k]<<endl;
			}
		}		
	}	
}
string lastFive(string input){
     return input.substr(input.size() - 5);
}

////////////////////////////////////////////////////////////////
void rabinKarpSearch(string text,string pattern, int q) {
  int m = pattern.length();
  int n = text.length();
  int i, j;
  int p = 0;//hash value for pattern
  int t = 0;//hash value for text(word)
  int h = 1;

  // Calculate h value(h = d^(m-1)
  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Find the matching
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m){
        if(i<=5){
				matchIndex.push_back(i+5);	
			}else{
				matchIndex.push_back(i-5);
			}
			queryIndex.push_back(query);//set the query
		}
    }
	//if negative hashing
    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}
/////////////////////////////////////////////////////////////////

int main() {
	
	cout<<"----- String matching by Rabin Karp Algorithm-----"<<endl;
	string pi,word,temp,filename;
	int q = 19;//suitable prime number to avoid collisions
	
	pi = GenerateMyPi();
	
	cout<<"My Birthday PI value is : "<<pi<<endl;
	
	// filestream variable file 
    fstream file; 
    
    // filename of the file 
    filename = "formatPI.txt"; 
  
    // opening file 
    file.open(filename.c_str()); 
    
    // extracting words from the file 
    while (file >> word && query<10000000) {
		if(word.length()==10){
			if(query==0){
				//cout<<word<<endl;
				rabinKarpSearch(word, pi, q);	
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl; 
			}else{
				word = temp + word;
				//cout<<word<<endl;
				rabinKarpSearch(word, pi, q);	
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl;		
			}
			query++;	
		}
    }
	ResultSet(); 	
	return 0;  
}
