//KMP Algorithm search for PI
#include <iostream>
#include <bits/stdc++.h>
#include <vector> 

using namespace std;

vector <int> matchIndex;
vector <int> queryIndex;
int point = 0;//global variable to point the index
int query = 0;//query number maintained by this variable

// Returns the birthday pi string(pattern)
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
	}
	for(int k =0;k<matchIndex.size();k++){
		//just because if add up last 5 digits we need to care about the query if it is in two queries
			if(matchIndex[k]%10 == 0 or matchIndex[k] >= 5){
				cout<<"Pattern found at index : "<<(queryIndex[k]*10-10)+matchIndex[k]<<endl;
			}else{
				cout<<"Pattern found at index : "<<queryIndex[k]*10+matchIndex[k]<<endl;
			}
	}	
}
string lastFive(string input){
     return input.substr(input.size() - 5);
}

///////////////////////////////////////////////////////////////  
void findPrefix(string pattern, int m, int prefArray[]) {
   int length = 0;
   prefArray[0] = 0;     //first place is always 0 as no prefix

   for(int i = 1; i<m; i++) {
      if(pattern[i] == pattern[length]) {
         length++;
         prefArray[i] = length;    
      }else {
         if(length != 0) {
            length = prefArray[length - 1];
            i--;     //decrease i to avoid effect of increasing after iteration
         }else
            prefArray[i] = 0;
      }
   }
}

void kmpPattSearch(string mainString, string pattern) {
   int n, m, i = 0, j = 0;
   n = mainString.size();
   m = pattern.size();
   int prefixArray[m];    //prefix array as same size of pattern
   findPrefix(pattern, m, prefixArray);

   while(i < n) {
      if(mainString[i] == pattern[j]) {
         i++; j++;
      }

      if(j == m) {
         //item found at i-j position.
			if(i<=5){
				matchIndex.push_back(i-j+5);	
			}else{
				matchIndex.push_back(i-j-5);
			}
		 	queryIndex.push_back(query);//set the query
         	j = prefixArray[j-1];    //get the prefix length from array
      }else if(i < n && pattern[j] != mainString[i]) {
         if(j != 0)
            j = prefixArray[j-1];
         else
            i++;
      }
   }
}
////////////////////////////////////////////////////////////////////



int main(){
	cout<<"----- String matching by KMP Search Algorithm-----"<<endl;
	string pi,word,temp;
	
	// filestream variable file 
    fstream file; 
    string filename; 
  
    // filename of the file 
    filename = "formatPI.txt"; 
	pi = GenerateMyPi();
	cout<<"My Birthday PI value is : "<<pi<<endl;
	
    // opening file 
    file.open(filename.c_str()); 
    
    // extracting words from the file 
    while (file >> word && query<10000000) {
		if(word.length()==10){
			if(query==0){
				//cout<<word<<endl;
				kmpPattSearch(word, pi);	
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl; 
			}else{
				word = temp + word;
				//cout<<word<<endl;
				kmpPattSearch(word, pi);	
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
