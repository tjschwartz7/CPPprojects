#pragma once
#include <vector>

template <class T>
class BTreeNode {
    std::vector<T>* keys;
	int minimumDegree;
    std::vector<BTreeNode<T>*>* children;
	int currentNumKeys;
	bool leaf;
public:

    template <class T>
    bool BTreeNodeSearch(T value) {
        for (T key : this->keys) {
            if (key == value) return true;
        }
        return false;
    }

	BTreeNode(int minimumDegree, bool leaf) {
		this->minimumDegree = minimumDegree;
		this->leaf = leaf;
       keys = new std::vector<T>(2*minimumDegree-1);
       children = new std::vector<BTreeNode<T>*>(2*minimumDegree);
       currentNumKeys = 0;
	}


    template <class T>
	friend class BTree;
};

template <class T>
class BTree
{
	BTreeNode<T>* root;
	int minimumDegree;
public:
	BTree(int minimumDegree) { this->minimumDegree = minimumDegree; }
    BTreeNode<T>* BTreeSearch(BTreeNode<T>* node, T key);

};


template <class T>
BTreeNode<T>* BTreeSearch(BTreeNode<T>* node, T key) {
    if (node != nullptr) {
        for (int i = 0; i < node->keys->size(); i++) {
            if (node->keys[i] != nullptr && this->key == node->keys[i])
                return node;
            if (node->keys[i] != nullptr && this->key < node->keys[i])
                return BTreeSearch(node->children[i], key);
        }
        if (node->keys[node->keys->size() - 1] != nullptr)
            return BTreeSearch(node->children[node->keys->size() - 1]);
    }
    return nullptr;
}

