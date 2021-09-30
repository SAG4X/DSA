
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 100001
#define INF 987654321
using namespace std;
typedef long long lld;

int n;

struct Node
{
    int dist;
    vector<int> adj;
    vector<int> weight;
};
Node graph[MAX_N];
bool mark[MAX_N];

struct pq_entry
{
    int node, dist;
    bool operator <(const pq_entry &a) const
    {
        if (dist != a.dist) return (dist > a.dist);
        return (node > a.node);
    }
};

//Dijkstra's shortest path
//runtime: O((V+E)log V)

inline void Dijkstra(int source)
{
    priority_queue<pq_entry> pq;
    pq_entry P;
    for (int i=0;i<n;i++)
    {
        if (i == source)
        {
            graph[i].dist = 0;
            P.node = i;
            P.dist = 0;
            pq.push(P);
        }
        else graph[i].dist = INF;
    }
    while (!pq.empty())
    {
        pq_entry curr = pq.top();
        pq.pop();
        int nod = curr.node;
        int dis = curr.dist;
        for (int i=0;i<graph[nod].adj.size();i++)
        {
            if (!mark[graph[nod].adj[i]])
            {
                int nextNode = graph[nod].adj[i];
                if (dis + graph[nod].weight[i] < graph[nextNode].dist)
                {
                    graph[nextNode].dist = dis + graph[nod].weight[i];
                    P.node = nextNode;
                    P.dist = graph[nextNode].dist;
                    pq.push(P);
                }
            }
        }
        mark[nod] = true;
    }
}

int main()
{
    n = 4;
    
    graph[0].adj.push_back(1);			//connect	
    graph[0].weight.push_back(5);		//weight
    graph[1].adj.push_back(0);			//vice versa as both ways
    graph[1].weight.push_back(5);
    
    graph[1].adj.push_back(2);
    graph[1].weight.push_back(5);
    graph[2].adj.push_back(1);
    graph[2].weight.push_back(5);
    
    graph[2].adj.push_back(3);
    graph[2].weight.push_back(5);
    graph[3].adj.push_back(2);
    graph[3].weight.push_back(5);
    
    graph[3].adj.push_back(1);
    graph[3].weight.push_back(6);
    graph[1].adj.push_back(3);
    graph[1].weight.push_back(6);
    
    Dijkstra(0);
    
    printf("%d\n",graph[3].dist);
    return 0;
}
