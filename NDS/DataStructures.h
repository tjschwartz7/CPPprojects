#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

const int SIZE = 27;
#include <string>

class TrieNode {

public:
	TrieNode* children[SIZE];
	std::string word;
	//char letter;
	int weight;
	TrieNode(std::string s);
	TrieNode();
	~TrieNode() {}
};

class Trie {
public:
	TrieNode* root;

	TrieNode* insert(TrieNode* root, std::string s);
	TrieNode* search(TrieNode* root, std::string s);
	void printTrie();
	void printChild(TrieNode* node);
	std::string weightPriority(std::string s);
	Trie() { root = new TrieNode(); }
private:
};


#endif // !DATASTRUCTURES_H


