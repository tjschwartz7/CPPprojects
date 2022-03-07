
#include "DataStructures.h"
#include "stdin.h"
#include "vector"
const int ARR_SIZE = 27;

#include <string>


//Making some changes - each node will store the entirety of the string up to that point instead of an individual char.
//This will trivialize the solution for returning the weighted maximum and only slightly increase memory inefficiency.


TrieNode::TrieNode(std::string s) {
	this->word = s;
	for (int i = 0; i <= 26; i++) {
		children[i] = nullptr;
	}
	this->weight = 0;
}

TrieNode::TrieNode() {

	for (int i = 0; i <= 26; i++) {
		children[i] = nullptr;
	}
	weight = 0;
	word = '0';
}


TrieNode* Trie::insert(TrieNode* root, std::string s) {
	TrieNode* node = root;
	std::string curString = "";
		for (char c : s) {
			curString += c;
			int index = toupper(c) - ('A'-1);
			if (index <= 26 && node->children[index] == nullptr) {
				node->children[index] = new TrieNode(curString);
				//std::cout << curString << std::endl;
			}
			node = node->children[index];
		}

	if (node->children[0] == nullptr) {
		node->children[0] = new TrieNode();
	}
	return (node->children[0]);

}

TrieNode* Trie::search(TrieNode* root, std::string s) {
	TrieNode* node = root;
		for (char c : s) {
			int index = toupper(c) - ('A'-1);
			if (index <= 26 && node->children[index] == nullptr) {
				return nullptr;
			}
			node = node->children[index];
		}
	if (node->children[0] != nullptr) {
		node->children[0]->weight += 3;
		return node->children[0];
	}
	return NULL;
}

void Trie::printTrie() {
	TrieNode* cur = root;
	printChild(cur);
}

void Trie::printChild(TrieNode* node) {
	if ((node->children[0] != nullptr)) {
		std::cout << "Weight: " << node->children[0]->weight;
		std::cout << " Word: " << node->word << " " << std::endl;
	}

	for (int i = 0; i <= 26; i++) {
		if (node->children[i] != nullptr) printChild(node->children[i]);
	}
	return;
}

TrieNode* getMaxWeight(TrieNode* node, TrieNode* maxWeight) {
	if ((node->children[0] != nullptr) && node->children[0]->weight > maxWeight->weight) {
		maxWeight->weight = node->children[0]->weight;
		maxWeight->word = node->word;
		std::cout << " String-Weight: " << maxWeight->word << " - " << maxWeight->weight << std::endl;
	}

	for (int i = 0; i <= 26; i++) {
		if (node->children[i] != nullptr) maxWeight = getMaxWeight(node->children[i], maxWeight);
	}
	return maxWeight;
}


TrieNode* findStringNode(TrieNode* root, std::string s) {
	TrieNode* node = root;
	for (char c : s) {
		int index = toupper(c) - ('A' - 1);
		if (index <= 26 && node->children[index] == nullptr) {
			return nullptr;
		}
		node = node->children[index];
		if (node->word == s) return node;
	}
	return nullptr;
}

std::string Trie::weightPriority(std::string s) {
	//Search returns the terminal node not the node where the string exists - only returns full words.
	TrieNode* cur = findStringNode(root, s);
	if (cur == nullptr) return "";
	cur = getMaxWeight(cur, cur);


	return cur->word;

}
