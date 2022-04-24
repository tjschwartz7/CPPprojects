#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "LL.h"
#include "PriorityQueue.h"

class ALVertex;

class AdjacencyList {
public:
	AdjacencyList(char data, int weight);
	AdjacencyList();
	char data;
	int weight;
	int distance = 2e31;
	ALVertex* predV;
	AdjacencyList* next;
};

class ALVertex {
public:
	AdjacencyList* front = new AdjacencyList();
	void ALInsert(char data, int weight);
	ALVertex() {}
	ALVertex(char data);
	char data;
	int weight;
	int distance = 0;
	ALVertex* predV;
	bool operator==(const ALVertex& rhs);
	ALVertex& operator=(const ALVertex& h);
	bool operator<(const ALVertex& rhs);
	bool operator>(const ALVertex& rhs);
	bool operator>=(const ALVertex& rhs);
};


class AdjacencyGraph {
public:
	std::vector<ALVertex> vertices;
	void insertVertex(ALVertex av);
	void insertEdge(char d1, char d2);
	void insertEdge(char d1, char d2, int weight);
	ALVertex* getNode(char data);
	void printAdjacencies();
	void insertVertex(char data);
	void BFS(ALVertex start);
	void DFS(ALVertex start);
	void DijkstraShortestPath(ALVertex startV);
	int getWeight(ALVertex a, ALVertex b);
	std::vector<ALVertex>* GraphTopologicalSort(std::vector<ALVertex> graph);
};

class AdjacencyMatrix {
	//matrix.size() must always be equal to 'size^2'
public:
	std::vector<bool> matrix;
	int size;
	AdjacencyMatrix();
	void insertVertex();
	void insertEdge(int d1, int d2);
	void adjustMatrixSize();
	void printMatrix();

};

class Digraph : public AdjacencyGraph {
public:
	void insertEdge(char origin, char pointsTo);
	void insertEdge(char origin, char pointsTo, int weight);
};

#endif