#include "Graph.h"


ALVertex::ALVertex(char data) {
	this->data = data;
}

AdjacencyList::AdjacencyList(char data, int weight) {
	this->data = data;
	this->weight = weight;
	this->next = nullptr;
}

AdjacencyList::AdjacencyList() {}

void ALVertex::ALInsert(char data, int weight) {
	if (front == nullptr) {
		front = new AdjacencyList(data, weight);
		front->next = nullptr;
		return;
	}

	AdjacencyList* cur = front;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = new AdjacencyList(data, weight);
}

void AdjacencyGraph::insertVertex(ALVertex av) {
	vertices.push_back(av);
}

void AdjacencyGraph::insertVertex(char data) {
	vertices.push_back(*(new ALVertex(data)));
}

void AdjacencyGraph::insertEdge(char d1, char d2) {
	ALVertex* av1 = getNode(d1);
	ALVertex* av2 = getNode(d2);
	av1->ALInsert(d2, 0);
	av2->ALInsert(d1, 0);


}

void AdjacencyGraph::insertEdge(char d1, char d2, int weight) {
	ALVertex* av1 = getNode(d1);
	ALVertex* av2 = getNode(d2);
	av1->ALInsert(d2, weight);
	av2->ALInsert(d1, weight);
}

ALVertex* AdjacencyGraph::getNode(char data) {
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i].data == data) return &vertices[i];
	}
	return nullptr;
}

void AdjacencyGraph::printAdjacencies() {
	for (int i = 0; i < vertices.size(); i++) {
		std::cout << "Vertex: " << vertices[i].data << " Adjacencies-Weight: ";
		AdjacencyList* cur = vertices[i].front;
		cur = cur->next;
		while (cur != nullptr) {
			std::cout << cur->data << "-" << cur->weight << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}
}

bool ALVertex::operator==(const ALVertex& rhs) {
	return this->data == rhs.data;
}

bool ALVertex::operator<(const ALVertex& rhs) {
	//std::cout << (this->distance < rhs.distance ? "yes" : "no") << std::endl;
	return this->distance < rhs.distance;
}

bool ALVertex::operator>(const ALVertex& rhs) {
	//std::cout << (this->distance > rhs.distance ? "yes" : "no") << std::endl;
	return this->distance > rhs.distance;
}

bool ALVertex::operator>=(const ALVertex& rhs) {
	//std::cout << (this->distance >= rhs.distance ? "yes" : "no") << std::endl;
	return this->distance >= rhs.distance;
}

ALVertex& ALVertex::operator=(const ALVertex& h) {
	this->data = h.data;
	this->weight = h.weight;
	AdjacencyList* cur2 = h.front;
	this->front = new AdjacencyList(cur2->data, cur2->weight);
	cur2 = cur2->next;
	while (cur2 != nullptr) {
		ALInsert(cur2->data, cur2->weight);
		cur2 = cur2->next;

	}
	return *this;
}

int AdjacencyGraph::getWeight(ALVertex a, ALVertex b) {
	AdjacencyList* list = a.front;
	list = list->next;
	while (list != nullptr) {
		if (list->data == b.data) return list->weight;
		list = list->next;
	}
	return 0;
}


void AdjacencyGraph::BFS(ALVertex start) {
	LLNode<ALVertex> searchQueue;
	LLNode<ALVertex> discovered;
	//Enqueue startV in frontierQueue
	//head == tail here
	searchQueue.push_front(start);
		//Add startV to discoveredSet
	discovered.push_back(start);

		while (!searchQueue.isEmpty()) {
			ALVertex currentV = searchQueue.pop_front();
				//"Visit" currentV
			std::cout << "Vertex: " << currentV.data << std::endl;
			AdjacencyList* list = currentV.front;
				while(list != nullptr){
				   ALVertex* adjV = getNode(list->data);
				   if ((adjV != nullptr) && discovered.search(*adjV) == nullptr) {
						searchQueue.push_front(*adjV);
						discovered.push_back(*adjV);
				   }
				   list = list->next;
				}
		}		
}

void AdjacencyGraph::DFS(ALVertex start) {
	LLNode<ALVertex> stack;
	stack.push_back(start);
	LLNode<ALVertex> visited;

		while (!stack.isEmpty()) {
			ALVertex currentV = stack.pop_back();
			std::cout << "VW: " << currentV.data << "-" << currentV.weight << std::endl;
				if (visited.search(currentV) == nullptr) {
					//"Visit" currentV
					std::cout << "Vertex: " << currentV.data << std::endl;
					//Add currentV to visitedSet
					visited.push_back(currentV);
					//for each vertex adjV adjacent to currentV
					AdjacencyList* list = currentV.front;
					while (list != nullptr) {
						if (list->data != NULL) {
							ALVertex* adjV = getNode(list->data);
							//Push adjV to stack
							stack.push_back(*adjV);
						}

						list = list->next;
					}						
				}
		}
}

void AdjacencyGraph::DijkstraShortestPath(ALVertex startV) {

	PriorityQueue<ALVertex> *unvisitedQueue = new PriorityQueue<ALVertex>();
	for (ALVertex currentV : vertices) {
		currentV.distance = 2e31;
		currentV.predV = 0;
		//std::cout << "mmk" << std::endl << (unvisitedQueue.peek() == nullptr) << std::endl;
		
		unvisitedQueue->enqueue(currentV);
	}


		// startV has a distance of 0 from itself
	startV.distance = 0;

		while (!unvisitedQueue->isEmpty()) {
			// Visit vertex with minimum distance from startV
			ALVertex currentV = unvisitedQueue->dequeue();
			std::cout << "Vertex-Distance:" << currentV.data << "-" << currentV.distance << std::endl;
			AdjacencyList* adjV = currentV.front;
			adjV = adjV->next;
			//for each vertex adjV adjacent to currentV{
			while (adjV != nullptr) {
				int edgeWeight = adjV->weight;
				std::cout << "EW: " << edgeWeight << std::endl;
				int alternativePathDistance = currentV.distance + edgeWeight;

					// If shorter path from startV to adjV is found,
					// update adjV's distance and predecessor
					if (alternativePathDistance < adjV->distance) {
						adjV->distance = alternativePathDistance;
						adjV->predV = &currentV;
					}
				adjV = adjV->next;
			}


				
		}
}
/*
std::vector<ALVertex>* GraphTopologicalSort(std::vector<ALVertex> graph) {
	std::vector<ALVertex>* resultList;
		noIncoming = list of all vertices with no incoming edges
		remainingEdges = list of all edges in the graph

		while (noIncoming is not empty) {
			currentV = remove any vertex from noIncoming
				Add currentV to resultList
				outgoingEdges = remove currentV's outgoing edges from remainingEdges
				for each edge currentE in outgoingEdges{
				   inCount = GraphGetIncomingEdgeCount(remainingEdges, currentE⇢toVertex)
				   if (inCount == 0)
					  Add currentE⇢toVertex to noIncoming
				}
		}
	return resultList
}

GraphGetIncomingEdgeCount(edgeList, vertex) {
	count = 0
		for each edge currentE in edgeList{
		   if (edge⇢toVertex == vertex) {
			  count = count + 1
		   }
		}
			return count
}
*/

AdjacencyMatrix::AdjacencyMatrix() {
	size = 0;
}

void AdjacencyMatrix::insertVertex() {
	size++;
	adjustMatrixSize();
}

void AdjacencyMatrix::insertEdge(int d1, int d2) {
	if (d1 * d2 > matrix.size()) throw std::out_of_range("Index out of bounds");
	if (d1 == d2) return;
	matrix[d1 * size + d2] = 1;
	matrix[d2 * size + d1] = 1;
}

void AdjacencyMatrix::adjustMatrixSize() {
	while (matrix.size() < (int)pow(size, 2)) {
		matrix.push_back(0);
	}
}

void AdjacencyMatrix::printMatrix() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i * size + j] << " ";
		}
		std::cout << std::endl;
	}
}


void Digraph::insertEdge(char origin, char pointsTo) {
	ALVertex* av1 = getNode(origin);
	ALVertex* av2 = getNode(pointsTo);
	av1->ALInsert(pointsTo, 0);
}

void Digraph::insertEdge(char origin, char pointsTo, int weight) {
	ALVertex* av1 = getNode(origin);
	ALVertex* av2 = getNode(pointsTo);
	av1->ALInsert(pointsTo, weight);
}

