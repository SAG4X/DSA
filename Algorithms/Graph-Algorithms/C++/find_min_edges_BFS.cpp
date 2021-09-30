// C++ program to find minimum edge 
// between given two vertex of Graph 
#include<bits/stdc++.h> 
using namespace std; 
  
// function for finding minimum no. of edge 
// using BFS 
int minEdgeBFS(vector <int> edges[], int u, 
                              int v, int n) 
{ 
    // visited[n] for keeping track of visited 
    // node in BFS 
    vector<bool> visited(n, 0); 
  
    // Initialize distances as 0 
    vector<int> distance(n, 0); 
  
    // queue to do BFS. 
    queue <int> Q; 
    distance[u] = 0; 
  
    Q.push(u); 
    visited[u] = true; 
    while (!Q.empty()) 
    { 
        int x = Q.front(); 
        Q.pop(); 
  
        for (int i=0; i<edges[x].size(); i++) 
        { 
            if (visited[edges[x][i]]) 
                continue; 
  
            // update distance for i 
            distance[edges[x][i]] = distance[x] + 1; 
            Q.push(edges[x][i]); 
            visited[edges[x][i]] = 1; 
        } 
    } 
    return distance[v]; 
} 
  
// function for addition of edge 
void addEdge(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
} 
  
// Driver function 
int main() 
{ 
    // To store adjacency list of graph 
    
    int n,edgec = 0;
    cin>>n>>edgec;
    vector <int> edges[edgec];
	int a,b=0;
	for(int i=0;i<edgec;i++){
		cin>>a>>b;
		a--;
		b--;
		addEdge(edges,a,b);
	} 
	a = 0;
	cin>>a;
	
    int u,v = 0;
	for(int i = 0;i<a;i++){
		cin>>u>>v;
		cout<<u<<v;
		cout << minEdgeBFS(edges, u, v, n)<<endl; 
	} 
    
    return 0; 
} 
