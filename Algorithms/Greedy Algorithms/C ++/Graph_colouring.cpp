#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V; // Number of vertices
	list<int> *adj; // A dynamic array of adjacency lists
	public:
		Graph(int V) { this->V = V; adj = new list<int>[V]; }
		~Graph()	 { delete [] adj; }
		void addEdge(int v, int w);	
		void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::greedyColoring()
{
	int result[V];

	result[0] = 0;

	for (int u = 1; u < V; u++)
		result[u] = -1;

	bool available[V];
	for (int cr = 0; cr < V; cr++)
		available[cr] = false;

	for (int u = 1; u < V; u++)
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = true;

		int cr;
		for (cr = 0; cr < V; cr++)
			if (available[cr] == false)
				break;

		result[u] = cr;

		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = false;
	}

	for (int u = 0; u < V; u++)
		cout << "Vertex " << u << " --> Color " << result[u] << endl;
}

int main()
{
	int v, e; // Number of vertices and edges
	
	cout << "Number of Vertices: ";
	cin >> v;
	Graph g(v);
	cout << "Graph : [ ";
	for (int i=0; i<v; i++)
	{
		cout << i << " , ";
	}
	cout << "\b\b]\n";
	
	cout << "\nNumber of Edges: ";
	cin >> e;
	int edge1, edge2;
	for (int i=0; i<e; i++)
	{
		cout << "\nEdge " << i+1 << endl;
		cout << "Vertices : ";
		cin >> edge1 >> edge2;
		if (edge1 >= v || edge2 >= v) {
			cout << "\tInvalid Vertex/Vertices! Rewrite the Edge\n";
			cout << "Vertices : ";
			cin >> edge1 >> edge2;
		}
		g.addEdge(edge1, edge2);
	}
	cout << "\n\nColoring of the graph \n";
	g.greedyColoring();

	return 0;
}
