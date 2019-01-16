#include "Vertex.h"


Vertex::Vertex()
{
	nodeNumber = 0;
	visited = false;
	nextPtr = nullptr;
}

Vertex::Vertex(const int& nodeNum)
{
	nodeNumber = nodeNum;
	visited = false;
	nextPtr = nullptr;
}

Vertex::Vertex(const int& nodeNum, Vertex* next)
{
	nodeNumber = nodeNum;
	visited = false;
	nextPtr = next;
}

bool Vertex::isVisited() const {
	return visited;
}

void Vertex::setVisited(const bool& boolean) {
	visited = boolean;
}

Vertex* Vertex::getNextPtr() const {
	return nextPtr;
}

void Vertex::setNextPtr(Vertex* next) {
	nextPtr = next;
}

int Vertex::getNodeNumber() const {
	return nodeNumber;
}

void Vertex::setNodeNumber(const int& nodeNum) {
	nodeNumber = nodeNum;
}