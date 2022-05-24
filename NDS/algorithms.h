#pragma once

#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>
#include<map>
#include<chrono>

class BHConversion {
public:
	std::map<std::string, std::string> chartBH = { {"0000", "0"},{"0001", "1"},{"0010", "2"},{"0011", "3"},
		{"0100", "4"},{"0101", "5"},{"0110", "6"},{"0111", "7"},
		{"1000", "8"},{"1001", "9"},{"1010", "A"},{"1011", "B"},
		{"1100", "C"},{"1101", "D"},{"1110", "E"},{"1111", "F"} };
	std::map<char, std::string> chartHB = { {'0',"0000"},{'1', "0001"},{'2',"0010"},{'3',"0011"},
	{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
	{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},
	{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};

};

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

	std::string LongestCommonSubstring(std::string str1, std::string str2);
	std::string DynamicLongestCommonSubstring(std::string str1, std::string str2);
	int FibonacciNumber(int termIndex);
	std::string ShuntingYard(std::string infixString);

	std::string scramble(std::string bits, int operations, double key);
	std::string descramble(std::string bits, int operations, int key, int size);
	std::vector<int> bitonicSequence(std::vector<int> set);
	std::string BinaryToHexConverter(std::string bits);
	std::string HexToBinaryConverter(std::string hex);
	bool HexBinaryConversionTester(int numTests);
};