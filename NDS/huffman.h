#pragma once
#include <map>
#include <string>
#include<vector>
#include "PriorityQueue.h"





class HuffmanTree {
public:
	bool operator>=(const HuffmanTree& h) { return this->frequency <= h.frequency; }
	bool operator<(const HuffmanTree& h) { return this->frequency > h.frequency; }
	int frequency;
	char character;
	HuffmanTree() {
		this->frequency = 0;
		this->character = 0;
	}
	HuffmanTree(int frequency) {
		this->frequency = frequency;
		this->character = 0;
	}
	int compareTree(HuffmanTree tree) {
		return this->frequency - tree.frequency;
	}
	HuffmanTree* left;
	HuffmanTree* right;
};


class HuffmanNode : public HuffmanTree {
public:
	HuffmanNode() {
		this->frequency = 0;
		this->character = 0;
	}
	HuffmanNode(int frequency) {
		this->frequency = frequency;
		this->character = 0;
	}
	HuffmanNode(int frequency, HuffmanTree* left, HuffmanTree* right) {
		this->frequency = frequency;
		this->left = left;
		this->right = right;
		this->character = 0;
	}
};

class HuffmanLeaf : public HuffmanNode {
public:
	
	HuffmanLeaf() {
		this->frequency = 0;
		this->character = 0;
	}
	HuffmanLeaf(int frequency, char character) {
		this->frequency = frequency;
		this->character = character;
	}
};

class huffmanDecoding {
public:
	HuffmanTree* root;
	std::map<char, int>* table = new std::map<char, int>();
	void BuildCharacterFrequencyTable(std::string inputString, std::map<char, int>* table);
	std::map<char, int>* BuildCharacterFrequencyTable(std::string inputString);
	HuffmanTree* HuffmanBuildTree(std::string inputString);
	std::map<char, std::string>* HuffmanGetCodes(HuffmanTree* node, std::string prefix, std::map<char, std::string>* output);
	std::string HuffmanDecompress(std::string compressedString, HuffmanTree* treeRoot);
	std::string HuffmanCompress(std::string inputString);

};

class FreqComp {
public:
	bool operator ()(const HuffmanTree* left, const HuffmanTree* right) const
	{
		return left->frequency > right->frequency;
	}
};