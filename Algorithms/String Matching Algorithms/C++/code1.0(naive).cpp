#include<iostream>
#include<sstream>
#include <bits/stdc++.h>
#include<vector> 

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
// Naive string serach
///////////////////////////////////////////////////////////
void naiveSearch(string text,string pattern){
	
	for(int i = 0;i<=text.length()-pattern.length();i++){
		int j;
		for(j =0;j<pattern.length();j++){
			if(text[i+j]!= pattern[j]){
				break;
			}
		}
		if(j==pattern.length()){
			if(i<=5){
				matchIndex.push_back(i+5);	
			}else{
				matchIndex.push_back(i-5);
			}
			queryIndex.push_back(query);
		}
		point++;
	}
}
///////////////////////////////////////////////////////////
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



int main(){
	cout<<"----- String matching by Naive Search Algorithm-----"<<endl;
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
				naiveSearch(word,pi);
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl; 
			}else{
				word = temp + word;
				//cout<<word<<endl;
				naiveSearch(word,pi);
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
