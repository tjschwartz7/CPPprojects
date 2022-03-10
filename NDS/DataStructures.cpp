
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
	weight = 1;
	word = '0';
}


TrieNode* Trie::insert(TrieNode* root, std::string s) {
	TrieNode* node = root;
	std::string curString = "";
		for (char c : s) {
			curString += tolower(c);
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
		//std::cout << "Weight: " << node->children[0]->weight;
		std::cout << node->word << std::endl;
	}

	for (int i = 0; i <= 26; i++) {
		if (node->children[i] != nullptr) printChild(node->children[i]);
	}
	return;
}

TrieNode* Trie::getMaxWeight(TrieNode* node, TrieNode *maxWeight) {
	//std::cout << "Max-weight word before: " << node->word << std::endl;
	if ((node->children[0] != nullptr) && node->children[0]->weight >= maxWeight->weight) {
		maxWeight->weight = node->children[0]->weight;
		maxWeight->word = node->word;
		std::cout << " String-Weight: " << maxWeight->word << " - " << maxWeight->weight << std::endl;
	}

	for (int i = 0; i <= 26; i++) {
		if (node->children[i] != nullptr) maxWeight = getMaxWeight(node->children[i], maxWeight);
	}
	//std::cout << "Max-weight node word after: " << node->word << std::endl;
	return maxWeight;
}


TrieNode* Trie::findStringNode(TrieNode* root, std::string s) {
	TrieNode* node = root;
	//std::cout << "root->word" << root->word << std::endl;
	for (char c : s) {
		//std::cout << "Chars in order: " << c << std::endl;
		int index = toupper(c) - ('A' - 1);
		if (index <= 26 && node->children[index] == nullptr) {
			return nullptr;
		}
		node = node->children[index];
		//std::cout << "Node->word " << node->word << " " << s << " where index= " << index << std::endl;
		std::string lower1 = s;
		for (int i = 0; i < s.size(); i++) {
			lower1[i] = tolower(lower1[i]);
		}

		if (lower1 == node->word) return node;
	}
	return nullptr;
}

std::string Trie::weightPriority(std::string s) {
	//Search returns the terminal node not the node where the string exists - only returns full words.
	//std::cout << "String node of: " << s << std::endl;
	TrieNode* cur = findStringNode(root, s);
	if (cur == nullptr) return "";
	cur = getMaxWeight(cur, new TrieNode);


	return cur->word;

}

void Trie::printFromNode(TrieNode* node) {
	TrieNode* cur = node;
	printChild(cur);
}