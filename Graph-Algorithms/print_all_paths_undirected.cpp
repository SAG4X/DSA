#include <bits/stdc++.h> 
using namespace std; 

int isNotVisited(int x, vector<int>& path) 
{ 
    for (int i = 0; i < path.size(); i++)  
        if (path[i] == x)  
            return 0;  
    return 1; 
} 
void findpaths(vector<vector<int> >&g, int src, int dst, int v) { 
    queue<vector<int> > q; 
    int ab = 0;
    int count = 0;
    int num[v] =  { 0 }; 
  
    vector<int> path; 
    path.push_back(src); 
    q.push(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        int last = path[path.size() - 1]; 
  
        if (last == dst){
            for(int i = 0;i<path.size();i++){
            	cout<<path[i]<<" ";//printing
                num[path[i]]++;
            }
            cout<<endl;
            ab++;
        }  
       
        for (int i = 0; i < g[last].size(); i++) { 
            if (isNotVisited(g[last][i], path)) { 
                vector<int> newpath(path); 
                newpath.push_back(g[last][i]); 
                q.push(newpath); 
            } 
        } 
    }
    for(int x = 0;x<v+1;x++){
        if(num[x]==ab){
            count++;
        }
    }
    cout<<count<<endl;
} 

// driver program 
int main(){ 
    int n,edges = 0;
    int t = 0;
    vector<vector<int> > g; 
    // number of vertices 
    cin>>n>>edges;
    g.resize(n);
    
    for(int i =0;i<edges;i++){
        int x,y =0;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    cin>>t;
    //
    for(int i =0;i<t;i++){
        int a,b =0;
        cin>>a>>b;
        findpaths(g, --a, --b, n);
    }
    return 0; 
} 
/////// sample test case ///////
//6 5 six vertices five edges
//1 2
//1 3
//3 4
//4 5
//2 4
//2 queries
//1 5 how many paths from 1 to 5
//3 4 paths from 4 to 3

