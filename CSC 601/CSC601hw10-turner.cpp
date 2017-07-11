#include <iostream>
#include <string>
#include <vector>
#include "graph.h"
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment 10											//
//															//
//	CSC601hw10-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: Demonstrate the use of graphs		//
//															//
// ======================================================== //

int main(){
	Graph myGraph;
	Vertex v1("Vertex 1"), v2("Vertex 2"), v3("Vertex 3"), v4("Vertex 4"), v5("Vertex 5");
	
	// Insert vertices into graph
	myGraph.insert(&v1);
	myGraph.insert(&v2);
	myGraph.insert(&v3);
	myGraph.insert(&v4);
	myGraph.insert(&v5);
	
	// V1 Edges
	v1.addEdge(&v2, 10);
	v1.addEdge(&v3, 16);
	v1.addEdge(&v4, 13);
	
	// V2 Edges
	v2.addEdge(&v1, 10);
	v2.addEdge(&v3, 8);
	v2.addEdge(&v4, 11);
	v2.addEdge(&v5, 20);
	
	// V3 Edges
	v3.addEdge(&v1, 16);
	v3.addEdge(&v2, 8);
	v3.addEdge(&v4, 8);
	v3.addEdge(&v5, 20);
	
	// V4 Edges
	v4.addEdge(&v1, 13);
	v4.addEdge(&v2, 11);
	v4.addEdge(&v3, 8);
	
	// V5 Edges
	v5.addEdge(&v2, 20);
	v5.addEdge(&v3, 20);
	
	cout << endl;
	myGraph.printGraph();
	
	return 0;
}
