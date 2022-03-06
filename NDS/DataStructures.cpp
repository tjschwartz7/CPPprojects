
#include "DataStructures.h"
#include "stdin.h"
const int ARR_SIZE = 26;

#include <string>

TrieNode::TrieNode(int index) {
	letter = (char)(index + 'A');
	for (int i = 0; i < 26; i++) {
		children[i] = nullptr;
	}
	weight = 0;
}

TrieNode::TrieNode() {

	for (int i = 0; i < 26; i++) {
		children[i] = nullptr;
	}
	weight = 0;
	letter = '0';
}


TrieNode* Trie::insert(TrieNode* root, std::string s) {
	TrieNode* node = root;
		for (char c : s) {
			int index = toupper(c) - ('A'-1);
			if (index <= 26 && node->children[index] == nullptr) {
				node->children[index] = new TrieNode(index);
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
			std::cout << index << std::endl;
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
