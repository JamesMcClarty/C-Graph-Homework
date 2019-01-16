#include<fstream>
#include"Graph.h"

using namespace std;


int main()
{
	//Variables
	int numOfNodes=0, tupleOne=0, tupleTwo=0;

	//Street 1

	ifstream inFile("instructions1.txt"); // Open file
	if (!inFile) { // If no file is made, shut the program down.
		cout << "File not found. Shutting down." << endl;
		return 0;
	}

	inFile >> numOfNodes; // Get number of nodes.
	Graph* graph = new Graph(numOfNodes);


	while (!inFile.eof()) { // Get tuples
		inFile >> tupleOne;
		inFile >> tupleTwo;
		graph->addEdge(tupleOne, tupleTwo);
	}
	inFile.close(); //Close file.

	cout << "Street 1" << endl; 
	graph->getValue(); //Show adjacency list.
	if (graph->traverse()) { //Traverse the instructions and show the result.
		cout << "Finished!" << endl;
	}
	else {
		cout << "Failure" << endl;
	}

	//Street 2

	inFile.open("instructions2.txt");
	if (!inFile) {
		cout << "File not found. Shutting down." << endl;
		return 0;
	}

	inFile >> numOfNodes;
	graph = new Graph(numOfNodes);


	while (!inFile.eof()) {
		inFile >> tupleOne;
		inFile >> tupleTwo;
		graph->addEdge(tupleOne, tupleTwo);
	}
	inFile.close();

	cout << "Street 2" << endl;
	graph->getValue();
	if (graph->traverse()) {
		cout << "Finished!" << endl;
	}
	else {
		cout << "Failure" << endl;
	}

	//Street 3

	inFile.open("instructions3.txt");
	if (!inFile) {
		cout << "File not found. Shutting down." << endl;
		return 0;
	}

	inFile >> numOfNodes;
	graph = new Graph(numOfNodes);


	while (!inFile.eof()) {
		inFile >> tupleOne;
		inFile >> tupleTwo;
		graph->addEdge(tupleOne, tupleTwo);
	}
	inFile.close();

	cout << "Street 3" << endl;
	graph->getValue();
	if (graph->traverse()) {
		cout << "Finished!" << endl;
	}
	else {
		cout << "Failure" << endl;
	}

	cin.get();
	return 0;
}

