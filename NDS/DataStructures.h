#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

const int SIZE = 26;
#include <string>

class TrieNode {

public:
	TrieNode* children[SIZE];
	char letter;
	int weight;
	TrieNode(int index);
	TrieNode();
	~TrieNode() {}
};

class Trie {
public:
	TrieNode* root;

	TrieNode* insert(TrieNode* root, std::string s);
	TrieNode* search(TrieNode* root, std::string s);

	Trie() { root = new TrieNode(); }
private:
};


#endif // !DATASTRUCTURES_H


