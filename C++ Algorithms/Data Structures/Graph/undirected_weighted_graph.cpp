// --------Undirected and Weighted graph----------------- 
// Using adjacency List 
// representation of graph 
#include<vector>
#include<iostream>
using namespace std; 
  
// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
                                     int v, int wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
  
// Print adjacency list representaion ot graph 
void printGraph(vector<pair<int,int> > adj[], int V) 
{ 
    int u, x=0; 
    for (u = 0; u < V; u++) 
    { 
        cout << "Node " << u << " makes an edge with \n"; 
        while(x<adj[u].size()) 
        { 
            cout<<adj[u][x].first<<" weight "<<adj[u][x].second<<" "<<endl;
            x++;
        }
		x=0; 
        cout << "\n"; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int V=5;
    
    vector<pair<int, int> > adj[V]; 
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70); 
    printGraph(adj, V); 
    return 0; 
} 
