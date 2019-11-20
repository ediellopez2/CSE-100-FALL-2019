/*
Author: Ediel Lopez
Course: CSE 100 (Algorithm Design and Analysis)
Term: Fall 2019
About: The Bellman-Ford Algorithm
*/
#include <iostream>
#include <climits>			// INT_MAX
#include <list> 			// To create the Adjacency Matrix
#include <iterator>			// To traverse the Adjacency Matrix
#include <utility>			// To create a set of pairs set<pair<datatype1, datatype2>> set_name;
#include <set>				// To create a set of pairs
using namespace std;

typedef pair<int, int> pairs;

struct Edge {
	int a;
	int b;
	int weight;

	Edge(int a, int b, int w) {
		this->a = a;
		this->b = b;
		this->weight = w;
	}
};

class Graph {
private:
	int max = 1000;
	int V;				// No. of vertices 
	int E;				// No. of edges
	list<Edge> *adj;	// An array of adjacency lists

	int *distance;			
	int *predecessor_value;

	set<pairs> s;
public:
	Graph();				// Default Constructor
	Graph(int v);			// Constructor
	void setVertices(int v);
	void setEdges(int e);
	int getVertices() const;
	int getEdges() const;
	void getDistances();

	void init_single_source(int ver, int s);
	void addEdge(int u, int v, int w);
	void showSize();
	set<pairs> getCoordinates() const;
	void relax(int u, int v);
	bool negative_weight_cycle_check();

	~Graph();
};


// =======================================================================
// =======================================================================
Graph::Graph() {
	this->V = 0; 
	adj = nullptr;
	distance = nullptr;
	predecessor_value = nullptr;
}

Graph::Graph(int v) {
	this->V = v; 
	adj = new (nothrow) list<Edge>[v];
	distance = new (nothrow) int[v];
	predecessor_value = new (nothrow) int[v];
}

void Graph::setVertices(int v) {
	this->V = v;
	adj = new (nothrow) list<Edge>[v];
	distance = new (nothrow) int[v];
	predecessor_value = new (nothrow) int[v];
}

void Graph::setEdges(int e) {
	this->E = e;
}

int Graph::getVertices() const {
	return V;
}

int Graph::getEdges() const {
	return E;
}

void Graph::init_single_source(int ver, int s) {
	for (int v = 0; v < ver; v++)	{
		distance[v] = max;
		predecessor_value[v] = 0;
	}
	distance[s] = 0;
}

// Creates the Adjacency List and the set of pairs.
void Graph::addEdge(int u, int v, int w) {
	Edge myEdge(u, v, w);					
	adj[u].push_back(myEdge);

	pairs x = make_pair(u, v);
	s.insert(x);
	// cout << s.size() << endl;
}

void Graph::showSize() {
	list<Edge>::iterator it;
	for (int index = 0; index < V; index++) {
		cout << "Vertex " << index << ": ";
		for (it = adj[index].begin(); it != adj[index].end(); it++)
			cout << it->b << " ";
		cout << endl;
	}
}

set<pairs> Graph::getCoordinates() const {
	return s;
}

void Graph::relax(int u, int v) {
	// First we have to find the edge the connects vertices u and v.
	list<Edge>::iterator it;
	int w; 	// Variable to hold the weight of the edge.
	for (it = adj[u].begin(); it != adj[u].end(); it++) {
		if (it->b == v) {
			w = it->weight;
		}
	}

	if (distance[v] > (distance[u] + w)) {
		distance[v] = distance[u] + w;
		predecessor_value[v] = u;
	}
}

bool Graph::negative_weight_cycle_check() {
	// First we have to find the edge the connects vertices u and v.
	list<Edge>::iterator it;
	int w; 	// Variable to hold the weight of the edge.
	
	for (auto const &c : s) {
		for (it = adj[c.first].begin(); it != adj[c.first].end(); it++) {
			if (it->b == c.second) {
				w = it->weight;
			}
		}


		if (distance[c.second] > (distance[c.first] + w)) {
			return false;
		}
	}
	return true;
}	

void Graph::getDistances() {
	for (int index = 0; index < V; index++) {
		if (distance[index] != max)
			cout << distance[index] << endl;
		else 
			cout << "INFINITY" << endl;
	}
	//cout << endl;
}

Graph::~Graph() {
	delete[] adj;
	// cout << "Calling the Destructor ... " << endl;
}

// =======================================================================
// =======================================================================

bool bellman_ford(Graph &myGraph, int source);

int main() {
	int vertices = 0, edges = 0;
	int u = 0, v = 0, w = 0;						// weight w from edge u to edge v
	cin >> vertices  >> edges;						// Get the number of vertices and edges.

	Graph myGraph;
	myGraph.setVertices(vertices);
	myGraph.setEdges(edges);
	
	for(int index = 0; index < edges; index++) {	// Enter the arguments for u, v, and w.
		cin >> u >> v >> w;
		myGraph.addEdge(u, v, w);
	}
	


	// Graph myGraph;
	// myGraph.setVertices(6);
	// myGraph.setEdges(10);
	// myGraph.addEdge(0, 1, 6);
	// myGraph.addEdge(1, 2, 5);
	// myGraph.addEdge(1, 3, -4);
	// myGraph.addEdge(1, 4, 8);
	// myGraph.addEdge(2, 1, -2);
	// myGraph.addEdge(3, 0, 2);
	// myGraph.addEdge(3, 2, 7);
	// myGraph.addEdge(3, 4, 9);
	// myGraph.addEdge(4, 0, 7);
	// myGraph.addEdge(5, 2, 5);

	// myGraph.setVertices(6);
	// myGraph.setEdges(11);
	// myGraph.addEdge(0, 1, 6);
	// myGraph.addEdge(1, 2, 5);
	// myGraph.addEdge(1, 3, -4);
	// myGraph.addEdge(1, 4, 8);
	// myGraph.addEdge(2, 1, -2);
	// myGraph.addEdge(3, 0, 2);
	// myGraph.addEdge(3, 2, 7);
	// myGraph.addEdge(3, 4, 9);
	// myGraph.addEdge(3, 5, -14);
	// myGraph.addEdge(4, 0, 7);
	// myGraph.addEdge(5, 2, 5);

	// myGraph.showSize();

	if (bellman_ford(myGraph, 0) == 1) {
		cout << "TRUE" << endl;
		myGraph.getDistances();
	}
	else {
		cout << "FALSE" << endl;
	}
	// cout << bellman_ford(myGraph, 0) << endl;

	return 0;
}

bool bellman_ford(Graph &myGraph, int source) {
	myGraph.init_single_source(myGraph.getVertices(), 0);
	set<pairs> coordinates = myGraph.getCoordinates();
	//cout << coordinates.size() << endl;

	for (int index = 0; index < myGraph.getVertices() - 1; index++)	{
		for (auto const &c : coordinates) {
			// cout << c.first << "\t" << c.second << endl;
			myGraph.relax(c.first, c.second);
		}
	}

	return myGraph.negative_weight_cycle_check();

	// for (auto const &c : coordinates) {
	// 	myGraph.relax(c.first, c.second);
	// }
	// return true;
}