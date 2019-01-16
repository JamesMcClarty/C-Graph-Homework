#include "Graph.h"


Graph::Graph()
{
	adjacencyList = new Vertex*[DEFAULT];
	nodes = DEFAULT;
	for (int i = 0; i < DEFAULT; i++)
	{
		addListNode(i);
	}
	edges = 0;
	lastNodeVisted = adjacencyList[0];
} // Default constructor

Graph::Graph(const int& nodesNum)
{
	adjacencyList = new Vertex*[nodesNum]; // Sets up new array of pointers
	nodes = nodesNum; // sets up number of nodes.
	for (int i = 0; i < nodesNum; i++) //Populates array with nodes.
	{
		addListNode(i);
	}
	edges = 0;
	lastNodeVisted = adjacencyList[0]; 
}

Graph::~Graph()
{
	delete adjacencyList;
}

int Graph::getNumberOfEdges() const {
	return edges; 
} //Returns number of edges

void Graph::addListNode(const int& nodeNum) {
	Vertex* newVertex = new Vertex(nodeNum);
	adjacencyList[nodeNum] = newVertex;
} //Makes a new node and adds it to the array

void Graph::addEdge(const int& source, const int& dest) {
	Vertex* newNode = new Vertex(dest); // Creates new node
	Vertex* sourceNode = adjacencyList[source]; //Gets source node.
	while (sourceNode->getNextPtr() != nullptr) // Traverses the source node until an empty pointer is found.
	{
		sourceNode = sourceNode->getNextPtr();
	}
	sourceNode->setNextPtr(newNode); // Set the next pointer.
	edges++; // Increase number of edges.
	Tuple tuple; // Make new tuple and add the path between the two nodes.
	tuple.dest = dest;
	tuple.source = source;
	listOfDirections.push(tuple); //Add tuple to the new list.
}

bool Graph::traverse() {

	if (!listOfDirections.empty()) { // If the list isn't empty
		Tuple tuple = listOfDirections.front(); //Get next tuple
		int source = tuple.source;
		int destination = tuple.dest;
		Vertex* currentVertex = adjacencyList[source]; // Set up source
		while ((currentVertex->getNextPtr() != nullptr) && (currentVertex->getNodeNumber() != destination)) //Find the edge listed.
		{
			currentVertex = currentVertex->getNextPtr();
		}
		if ((currentVertex->getNodeNumber() == destination) && (lastNodeVisted->getNodeNumber() == source)) { //If source is the same as last node visited and destination is found...
			if (!currentVertex->isVisited()) { // If the edge isn't visited
				currentVertex->setVisited(true); //Mark it as visited
				edges--; // lower edges left
				listOfDirections.pop(); // Discard tuple
				lastNodeVisted = currentVertex; //Update last node visited.
				return traverse(); // 
			}

			else if ((currentVertex->isVisited()) && (lastNodeVisted->getNodeNumber() == source)) {// Else if it's visited.
				std::cout << "This street has already been plowed." << std::endl;
				listOfDirections.pop(); // discard tuple.
				return traverse();
			}
		}

		else if ((lastNodeVisted->getNodeNumber() != source)) { // If snow plow isn't in the source node
			std::cout << "The destination cannot be reached in its current node." << std::endl;
			listOfDirections.pop(); //discard
			return traverse();
		}

		else if (currentVertex->getNodeNumber() != destination) { //If the edge isn't found.
			std::cout << "A connection to node " << destination << "cannot be found."<< std::endl;
			listOfDirections.pop(); //Discard
			return traverse();
		}
	}

	else { //Else, if the list is empty
		if ((edges == 0) && (lastNodeVisted->getNodeNumber() == 0)){ //If all the streets are cleared and plow is back in starting position.
			std::cout << "The snow plow has made it around without missing any streets." << std::endl;
			return true;
		}

		if ((edges == 0) && (lastNodeVisted->getNodeNumber() != 0)) { //If all the streets are cleared, but the plow is not back at the start...
			std::cout << "The snow plow cleared all the streets, but it did not return to the first node." << std::endl;
			return false;
		}

		else{ //Else, show how many streets are left.
			std::cout << "The snow plow was unable to get all the streets. It missed " << edges << "." << std::endl;
			return false;
		}
	}
	return false;
}

void Graph::getValue() { //Shows the adjacency list of the current graph.
	Vertex* newVertex; 
	std::cout << "The nodes and edge of this graph is: " << std::endl;
	for (int i = 0; i < nodes; i++) {
		newVertex = adjacencyList[i];
		std::cout << newVertex->getNodeNumber() << " ";
		while (newVertex->getNextPtr() != nullptr)
		{
			newVertex = newVertex->getNextPtr();
			std::cout << newVertex->getNodeNumber() << " ";
		}
		std::cout << std::endl;
	}
}