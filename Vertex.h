#ifndef _VERTEX
#define _VERTEX

class Vertex
{
private:

	int nodeNumber; // Node's number
	Vertex* nextPtr; // Next Pointer
	bool visited; // If the edge is visited or not.

public:
	Vertex(); // Default constructor
	Vertex(const int& nodeNum); // Sets up node number
	Vertex(const int& nodeNum, Vertex* next); // Sets up node number and next vertex
	bool isVisited() const; // Returns if the node is visited or not.
	void setVisited(const bool& boolean); // Sets the visited value
	Vertex* getNextPtr() const; // Returns next ptr.
	void setNextPtr(Vertex* next); // Sets next ptr
	int getNodeNumber() const; // Returns node number
	void setNodeNumber(const int& nodeNum); // Sets node number

};
#include "Vertex.cpp"
#endif

