#ifndef BST_H
#define BST_H

#include "stdin.h"
#include <string>


class BSTNode {
public:
	BSTNode() {}
	BSTNode(double key);
	BSTNode* parent;
	BSTNode* leftChild;
	BSTNode* rightChild;
	double data;
	int height;
	//used for RBTrees
	bool isBlack;
	int priority;
};

class BST {
public:
	BSTNode* root;
	BST(double key) { BSTInsert(new BSTNode(key)); }
	BST() {}
	BSTNode* BSTSearch(double key);
	BSTNode* BSTInsert(BSTNode* node);
	int BSTRemove(double key);
	bool BSTReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild);
	void BSTRemoveKey(double key);
	void BSTRemoveNode(BSTNode* node);
	void BSTPrintInorder(BSTNode* node);
	void BSTPrintPostorder(BSTNode* node);
	void BSTPrintPreorder(BSTNode* node);
	void BSTChangeHeights(BSTNode* currentNode, int amount, bool leafNode);

};
class AVLTree : public BST {
public:
	//BSTNode* root;
	//BST* tree;
	void AVLTreeUpdateHeight(BSTNode* node);
	bool AVLTreeSetChild(BSTNode* parent, std::string whichChild, BSTNode* child);
	bool AVLTreeReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild);
	int AVLTreeGetBalance(BSTNode* node);
	BSTNode* AVLTreeRotateRight(BSTNode* node);
	BSTNode* AVLTreeRotateLeft(BSTNode* node);
	BSTNode* AVLTreeRebalance(BSTNode* node);
	void AVLTreeInsertNode(BSTNode* node);
	void AVLTreeInsertKey(double key);
	bool AVLTreeRemoveNode(BSTNode* node);
	void AVLTreeRemoveKey(double key);

private:

};


class RBTree : public BST {
public:
	bool RBTreeSetChild(BSTNode* parent, std::string whichChild, BSTNode* child);
	bool RBTreeReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild);
	void RBTreeRotateLeft(BSTNode* node);
	void RBTreeRotateRight(BSTNode* node);
	void RBTreeInsertNode(BSTNode* node);
	void RBTreeBalance(BSTNode* node);
	BSTNode* RBTreeGetGrandparent(BSTNode* node);
	BSTNode* RBTreeGetUncle(BSTNode* node);
	void RBTreeRemove(double key);
	void RBTreeRemoveNode(BSTNode* node);
	void RBTreeRemoveKey(double key);
	BSTNode* RBTreeGetPredecessor(BSTNode* node);
	BSTNode* RBTreeGetSibling(BSTNode* node);
	bool RBTreeIsNonNullAndRed(BSTNode* node);
	bool RBTreeIsNullOrBlack(BSTNode* node);
	bool RBTreeAreBothChildrenBlack(BSTNode* node);
	void RBTreePrepareForRemoval(BSTNode* node);

	bool RBTreeTryCase1(BSTNode* node);
	bool RBTreeTryCase2(BSTNode* node, BSTNode* sibling);
	bool RBTreeTryCase3(BSTNode* node, BSTNode* sibling);
	bool RBTreeTryCase4(BSTNode* node, BSTNode* sibling);
	bool RBTreeTryCase5(BSTNode* node, BSTNode* sibling);
	bool RBTreeTryCase6(BSTNode* node, BSTNode* sibling);

	void RBTreePrintInorder(BSTNode* node);
	void RBTreePrintPreorder(BSTNode* node);
	void RBTreePrintPostorder(BSTNode* node);
};

#endif