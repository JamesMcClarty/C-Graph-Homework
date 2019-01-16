#ifndef _GRAPH
#define _GRAPH

#include "Vertex.h"
#include <queue>
#include <iostream>

struct Tuple{
	int source;
	int dest;
};

class Graph
{
private:

	int DEFAULT = 10;
	int nodes;
	Vertex** adjacencyList;
	int edges;
	Vertex* lastNodeVisted;
	std::queue<Tuple> listOfDirections;

public:
	Graph();
	Graph(const int& nodesNum);
	~Graph();
	int getNumberOfEdges() const;
	void addListNode(const int& nodeNum);
	void addEdge(const int& source, const int& dest);
	bool traverse();
	void getValue();

};
#include "Graph.cpp"
#endif