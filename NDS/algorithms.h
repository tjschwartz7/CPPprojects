#pragma once

#include "Graph.h"
#include "PriorityQueue.h"

class Algos {
public:
	void DijkstraShortestPath(ALVertex startV, AdjacencyGraph* ag) {

		PriorityQueue<ALVertex>* unvisitedQueue = new PriorityQueue<ALVertex>();
		for (int i = 0; i < ag->vertices.size(); i++) {
			ag->vertices[i].distance = 2e31;
			ag->vertices[i].predV = 0;
			//std::cout << "mmk" << std::endl << (unvisitedQueue.peek() == nullptr) << std::endl;

			unvisitedQueue->enqueue(ag->vertices[i]);
		}


		// startV has a distance of 0 from itself
		startV.distance = 0;

		while (!unvisitedQueue->isEmpty()) {
			// Visit vertex with minimum distance from startV
			ALVertex currentV = unvisitedQueue->dequeue();
			ALVertex* loc = &currentV;
			int index = 0;
			for (int i = 0; i < ag->vertices.size(); i++) {
				if (ag->vertices[i].data == currentV.data) index = i;
			}
			AdjacencyList* adjV = ag->vertices[index].front;
			//ag->vertices[index].data = 'F';
			adjV = adjV->next;
			//for each vertex adjV adjacent to currentV{
			while (adjV != nullptr) {
				int edgeWeight = adjV->weight;
				//std::cout << "Edge Weight: " << edgeWeight << std::endl;
				int alternativePathDistance = ag->vertices[index].distance + edgeWeight;
				std::cout << "DISTANCE!! " << alternativePathDistance << std::endl;

				// If shorter path from startV to adjV is found,
				// update adjV's distance and predecessor
				if (alternativePathDistance < adjV->distance) {
					adjV->distance = alternativePathDistance;
					adjV->predV = loc;
				
				}
				adjV = adjV->next;
			}



		}
	}

};