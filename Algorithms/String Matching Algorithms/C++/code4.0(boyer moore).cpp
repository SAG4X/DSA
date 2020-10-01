#include <bits/stdc++.h> 
# define SIZE 128
using namespace std; 
 
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
///////////////////////////////////////////////////////////////////////////  
// The preprocessing function for Bad character heuristic  
void badCharHeuristic( string str, int size,int badchar[SIZE]){  
  
    // Initialize all occurrences as -1  
    for (int i = 0; i < SIZE; i++)  
        badchar[i] = -1;  
  
    // Fill the actual value of last occurrence of a character  
    for (int i = 0; i < size; i++)  
        badchar[(int) str[i]] = i;  
}  
  

void BoyerMooreSearch(string txt, string pat){  
    int m = pat.size();  
    int n = txt.size();  
  
    int badchar[SIZE];  
  
    //create bad charcter array
    badCharHeuristic(pat, m, badchar);  
  
    int shift = 0; //shift of the pattern with respect to text
	  
    while(shift <= (n - m)){  
        int j = m - 1;  
  
        // matching
        while(j >= 0 && pat[j] == txt[shift + j])  
            j--;  
  		
  		// If the matching will present j = -1 according to the loop
        if (j < 0){
			// shift is success  
			if(shift<=5){
				matchIndex.push_back(shift+5);	
			}else{
				matchIndex.push_back(shift-5);
			}
			queryIndex.push_back(query);//set the query index
	
            shift += (shift + m < n)? m-badchar[txt[shift + m]] : 1;  
  		}else{
        	shift += max(1, j - badchar[txt[shift + j]]); 	
		}
         
    }  
}  
//////////////////////////////////////////////////////////////////////////  

int main() {  
    cout<<"----- String matching by Boyer Boore Algorithm-----"<<endl;
	string pi,word,temp,filename;
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
				BoyerMooreSearch(word, pi);	
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl; 
			}else{
				word = temp + word;
				//cout<<word<<endl;
				BoyerMooreSearch(word, pi);	
				//get last five substring and connect it to next string
				temp = lastFive(word);
				//cout<<temp<<endl;		
			}
			query++;	
		}
    }
	ResultSet(); 		
}  
   

