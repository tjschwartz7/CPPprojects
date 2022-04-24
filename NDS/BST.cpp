
#include "BST.h"


BSTNode::BSTNode(double key) {
	data = key;
	height = 0;
}


BSTNode* BST::BSTSearch(double key) {
	BSTNode* cur = root;
	while (cur != nullptr) {
		if (key == cur->data) {
			return cur; // Found
		}
		else if (key < cur->data) {
			cur = cur->leftChild;
		}
		else {
			cur = cur->rightChild;
		}
	}
	return nullptr; // Not found
}

BSTNode* BST::BSTInsert(BSTNode* node) {
	if (root == nullptr) {
		root = node;
		root->parent = nullptr;

	}
	else {
		BSTNode* currentNode = root;
		while (currentNode != nullptr) {
			if (node->data < currentNode->data) {
				if (currentNode->leftChild == nullptr) {
					currentNode->leftChild = node;
					node->parent = currentNode;
					currentNode = nullptr;
					if (node->parent->rightChild == nullptr) BSTChangeHeights(node, 1, false);
				}
				else {
					currentNode = currentNode->leftChild;
				}
			}
			else {
				if (currentNode->rightChild == nullptr) {
					currentNode->rightChild = node;
					node->parent = currentNode;
					currentNode = nullptr;
					if (node->parent->leftChild == nullptr) BSTChangeHeights(node, 1, false);
				}
				else {
					currentNode = currentNode->rightChild;
				}
			}

		}
	}
	return node;
}

//Increase the height of each node above cur by amount
//Use neg 1 if decrease
void BST::BSTChangeHeights(BSTNode* currentNode, int amount, bool leafNode) {
	if (!leafNode)
		while (currentNode->parent != nullptr) {
			currentNode = currentNode->parent;
			//std::cout << currentNode->data << " " << currentNode->height << std::endl;
			if (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr) {
				int curHeight = currentNode->height;
				currentNode->height = std::max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
				if (curHeight == currentNode->height) break; //Height above this has no need to change;
			}
			else
				currentNode->height += amount;

			//std::cout << currentNode->data << " " << currentNode->height << std::endl;
		}
	else
		while (currentNode->parent != nullptr) {
			//std::cout << currentNode->data << " " << currentNode->height << std::endl;
			if (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr) {
				int curHeight = currentNode->height;
				currentNode->height = std::max(currentNode->leftChild->height, currentNode->rightChild->height) + 1;
				if (curHeight == currentNode->height) break; //Height above this has no need to change;
			}
			else
				currentNode->height += amount;
			//std::cout << currentNode->data << " " << currentNode->height << std::endl;
			currentNode = currentNode->parent;

		}
}

bool BST::BSTReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild) {
	if (parent->leftChild != currentChild &&
		parent->rightChild != currentChild)
		return false;

	if (parent->leftChild == currentChild)
		parent->leftChild = newChild;
	else
		parent->rightChild = newChild;

	if (newChild != nullptr)
		newChild->parent = parent;
	//std::cout << "Replace child-" << newChild->data<<std::endl;
	if (newChild != nullptr)
		BSTChangeHeights(newChild, -1, false);
	else BSTChangeHeights(parent, -1, false);

	return true;
}

int BST::BSTRemove(double key) {
	BSTNode* par = nullptr;
	BSTNode* cur = root;
	while (cur != nullptr) { // Search for node
		if (cur->data == key) { // Node found 
			if (cur->leftChild == nullptr && cur->rightChild == nullptr) { // Remove leaf
				if (par == nullptr) // Node is root
					root = nullptr;
				else if (par->leftChild == cur)
					par->leftChild = nullptr;
				else
					par->rightChild = nullptr;

				if (par->leftChild == nullptr && par->rightChild == nullptr) BSTChangeHeights(par, -1, true);
			}
			else if (cur->rightChild == nullptr) {                // Remove node with only left child
				if (par == nullptr) // Node is root
					root = cur->leftChild;
				else if (par->leftChild == cur)
					par->leftChild = cur->leftChild;
				else
					par->rightChild = cur->leftChild;
				BSTChangeHeights(cur->leftChild, -1, false);
			}
			else if (cur->leftChild == nullptr) {                // Remove node with only right child
				if (par == nullptr) // Node is root
					root = cur->rightChild;
				else if (par->leftChild == cur)
					par->leftChild = cur->rightChild;
				else
					par->rightChild = cur->rightChild;
				BSTChangeHeights(cur->rightChild, -1, false);
			}
			else {                                      // Remove node with two children
			   // Find successor (leftmost child of right subtree)
				BSTNode* suc = cur->rightChild;
				while (suc->leftChild != nullptr)
					suc = suc->leftChild;
				double successorData = suc->data;
				BSTRemove(suc->data);     // Remove successor
				cur->data = successorData;

			}
			return 1;// Node found and removed
		}
		else if (cur->data < key) { // Search right
			par = cur;
			cur = cur->rightChild;
		}
		else {                    // Search left
			par = cur;
			cur = cur->leftChild;
		}
	}
	return 0;// Node not found
}

void BST::BSTRemoveKey(double key) {
	BSTNode* node = BSTSearch(key);
	//std::cout <<  "data " << node->data << std::endl;
	BSTRemoveNode(node);
}

void BST::BSTRemoveNode(BSTNode* node) {
	if (node == nullptr)
		return;
	//std::cout << "node->data" << node->data << std::endl;
		// Case 1: Internal node with 2 children
	if (node->leftChild != nullptr && node->rightChild != nullptr) {
		// Find successor
		BSTNode* succNode = node->rightChild;
		while (succNode->leftChild)
			succNode = succNode->leftChild;

		// Copy value/data from succNode to node
		node->data = succNode->data;

		// Recursively remove succNode
		std::cout << "what" << std::endl;
		BSTRemoveNode(succNode);
	}
	// Case 2: Root node (with 1 or 0 children)
	else if (node == root) {
		if (node->leftChild != nullptr)
			root = node->leftChild;
		else
			root = node->rightChild;

		// Make sure the new root, if non-null, has a null parent
		if (root != nullptr)
			root->parent = nullptr;
	}

	// Case 3: Internal with left child only
	else if (node->leftChild != nullptr)
		BSTReplaceChild(node->parent, node, node->leftChild);

	// Case 4: Internal with right child only OR leaf
	else
		BSTReplaceChild(node->parent, node, node->rightChild);
}


void BST::BSTPrintInorder(BSTNode* node) {
	if (node == nullptr) return;
	BSTPrintInorder(node->leftChild);
	std::cout << node->data << " " << node->height << std::endl;
	BSTPrintInorder(node->rightChild);
}

void BST::BSTPrintPreorder(BSTNode* node) {
	if (node == nullptr) return;
	std::cout << node->data << " " << node->height << std::endl;
	BSTPrintPreorder(node->leftChild);
	BSTPrintPreorder(node->rightChild);

}

void BST::BSTPrintPostorder(BSTNode* node) {
	if (node == nullptr) return;
	BSTPrintPostorder(node->leftChild);
	BSTPrintPostorder(node->rightChild);
	std::cout << node->data << " " << node->height << std::endl;
}



void AVLTree::AVLTreeUpdateHeight(BSTNode* node) {
	int leftHeight = -1;
	if (node->leftChild != nullptr)
		leftHeight = node->leftChild->height;
	int rightHeight = -1;
	if (node->rightChild != nullptr)
		rightHeight = node->rightChild->height;
	node->height = std::max(leftHeight, rightHeight) + 1;
}

bool AVLTree::AVLTreeSetChild(BSTNode* parent, std::string whichChild, BSTNode* child) {
	if (whichChild != "left" && whichChild != "right")
		return false;

	if (whichChild == "left")
		parent->leftChild = child;
	else
		parent->rightChild = child;
	if (child != nullptr)
		child->parent = parent;

	AVLTreeUpdateHeight(parent);
	return true;
}

bool AVLTree::AVLTreeReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild) {
	if (parent->leftChild == currentChild)
		return AVLTreeSetChild(parent, "left", newChild);
	else if (parent->rightChild == currentChild);
	return AVLTreeSetChild(parent, "right", newChild);
	return false;
}

int AVLTree::AVLTreeGetBalance(BSTNode* node) {
	int leftHeight = -1;
	if (node->leftChild != nullptr)
		leftHeight = node->leftChild->height;
	int rightHeight = -1;
	if (node->rightChild != nullptr)
		rightHeight = node->rightChild->height;
	return leftHeight - rightHeight;
}



BSTNode* AVLTree::AVLTreeRotateRight(BSTNode* node) {
	BSTNode* leftRightChild = node->leftChild->rightChild;
	if (node->parent != nullptr)
		AVLTreeReplaceChild(node->parent, node, node->leftChild);
	else { // node is root
		root = node->leftChild;
		root->parent = nullptr;
	}
	AVLTreeSetChild(node->leftChild, "right", node);
	AVLTreeSetChild(node, "left", leftRightChild);
	return node;
}

BSTNode* AVLTree::AVLTreeRotateLeft(BSTNode* node) {
	BSTNode* rightLeftChild = node->rightChild->leftChild;
	if (node->parent != nullptr)
		AVLTreeReplaceChild(node->parent, node, node->rightChild);
	else { // node is root
		root = node->rightChild;
		root->parent = nullptr;
	}
	AVLTreeSetChild(node->rightChild, "left", node);
	AVLTreeSetChild(node, "right", rightLeftChild);
	return node;
}

BSTNode* AVLTree::AVLTreeRebalance(BSTNode* node) {
	AVLTreeUpdateHeight(node);
	if (AVLTreeGetBalance(node) == -2) {
		if (AVLTreeGetBalance(node->rightChild) == 1) {
			// Double rotation case.
			AVLTreeRotateRight(node->rightChild);
		}
		return AVLTreeRotateLeft(node);
	}
	else if (AVLTreeGetBalance(node) == 2) {
		if (AVLTreeGetBalance(node->leftChild) == -1) {
			// Double rotation case.
			AVLTreeRotateLeft(node->leftChild);
		}
		return AVLTreeRotateRight(node);
	}
	return node;
}


void AVLTree::AVLTreeInsertNode(BSTNode* node) {
	BST::BSTInsert(node);
	node = node->parent;
	while (node != nullptr) {
		AVLTreeRebalance(node);
		node = node->parent;
	}
}

void AVLTree::AVLTreeInsertKey(double key) {
	AVLTreeInsertNode(new BSTNode(key));
}

bool AVLTree::AVLTreeRemoveNode(BSTNode* node) {
	if (node == nullptr) return false;
	BSTRemoveNode(node);
	node = node->parent;
	while (node != nullptr) {
		AVLTreeRebalance(node);
		node = node->parent;
	}
	return true;

}


void AVLTree::AVLTreeRemoveKey(double key) {
	AVLTreeRemoveNode(BSTSearch(key));
}

bool RBTree::RBTreeSetChild(BSTNode* parent, std::string whichChild, BSTNode* child) {
	if (whichChild != "left" && whichChild != "right")
		return false;

	if (whichChild == "left")
		parent->leftChild = child;
	else
		parent->rightChild = child;
	if (child != nullptr)
		child->parent = parent;
	return true;
}

bool RBTree::RBTreeReplaceChild(BSTNode* parent, BSTNode* currentChild, BSTNode* newChild) {
	if (parent->leftChild == currentChild)
		return RBTreeSetChild(parent, "left", newChild);
	else if (parent->rightChild == currentChild)
		return RBTreeSetChild(parent, "right", newChild);
	return false;
}

void RBTree::RBTreeRotateLeft(BSTNode* node) {
	BSTNode* rightLeftChild = node->rightChild->leftChild;
	if (node->parent != nullptr)
		RBTreeReplaceChild(node->parent, node, node->rightChild);
	else { // node is root
		root = node->rightChild;
		root->parent = nullptr;
	}
	RBTreeSetChild(node->rightChild, "left", node);
	RBTreeSetChild(node, "right", rightLeftChild);
}

void RBTree::RBTreeRotateRight(BSTNode* node) {
	BSTNode* leftRightChild = node->leftChild->rightChild;
	if (node->parent != nullptr)
		RBTreeReplaceChild(node->parent, node, node->leftChild);
	else { // node is root
		root = node->leftChild;
		root->parent = nullptr;
	}
	RBTreeSetChild(node->leftChild, "right", node);
	RBTreeSetChild(node, "left", leftRightChild);
}

void RBTree::RBTreeInsertNode(BSTNode* node) {
	BSTInsert(node);
	node->isBlack = false;
	RBTreeBalance(node);
}

void RBTree::RBTreeBalance(BSTNode* node) {
	if (node->parent == nullptr) {
		node->isBlack = true;
		return;
	}
	if (node->parent->isBlack)
		return;
	BSTNode* parent = node->parent;
	BSTNode* grandparent = RBTreeGetGrandparent(node);
	BSTNode* uncle = RBTreeGetUncle(node);
	if (uncle != nullptr && !uncle->isBlack) {
		parent->isBlack = uncle->isBlack = true;
		grandparent->isBlack = false;
		RBTreeBalance(grandparent);
		return;
	}
	if (node == parent->rightChild &&
		parent == grandparent->leftChild) {
		RBTreeRotateLeft(parent);
		node = parent;
		parent = node->parent;
	}
	else if (node == parent->leftChild &&
		parent == grandparent->rightChild) {
		RBTreeRotateRight(parent);
		node = parent;
		parent = node->parent;
	}
	parent->isBlack = true;
	grandparent->isBlack = false;
	if (node == parent->leftChild)
		RBTreeRotateRight(grandparent);
	else
		RBTreeRotateLeft(grandparent);
}

BSTNode* RBTree::RBTreeGetGrandparent(BSTNode* node) {
	if (node->parent == nullptr)
		return nullptr;
	return node->parent->parent;
}

BSTNode* RBTree::RBTreeGetUncle(BSTNode* node) {
	BSTNode* grandparent = nullptr;
	if (node->parent != nullptr)
		grandparent = node->parent->parent;
	if (grandparent == nullptr)
		return nullptr;
	if (grandparent->leftChild == node->parent)
		return grandparent->rightChild;
	else
		return grandparent->leftChild;
}

void RBTree::RBTreePrintInorder(BSTNode* node) {
	if (node == nullptr) return;
	RBTreePrintInorder(node->leftChild);
	std::cout << node->data << " " << ((node->isBlack) ? "Black" : "Red") << std::endl;
	RBTreePrintInorder(node->rightChild);
}

void RBTree::RBTreePrintPreorder(BSTNode* node) {
	if (node == nullptr) return;
	std::cout << node->data << " " << ((node->isBlack) ? "Black" : "Red") << std::endl;
	RBTreePrintPreorder(node->leftChild);
	RBTreePrintPreorder(node->rightChild);
}

void RBTree::RBTreePrintPostorder(BSTNode* node) {
	if (node == nullptr) return;
	RBTreePrintPostorder(node->leftChild);
	RBTreePrintPostorder(node->rightChild);
	std::cout << node->data << " " << ((node->isBlack) ? "Black" : "Red") << std::endl;
}

void RBTree::RBTreeRemove(double key) {
	BSTNode* node = BSTSearch(key);
	if (node != nullptr)
		RBTreeRemoveNode(node);
}

void RBTree::RBTreeRemoveNode(BSTNode* node) {
	if (node->leftChild != nullptr && node->rightChild != nullptr) {
		BSTNode* predecessorNode = RBTreeGetPredecessor(node);
		int predecessorData = predecessorNode->data;
		RBTreeRemoveNode(predecessorNode);
		node->data = predecessorData;
		return;
	}

	if (node->isBlack)
		RBTreePrepareForRemoval(node);
	BSTRemove(node->data);
}

void RBTree::RBTreeRemoveKey(double key) {
	RBTreeRemoveNode(BSTSearch(key));
}

BSTNode* RBTree::RBTreeGetPredecessor(BSTNode* node) {
	node = node->leftChild;
	while (node->rightChild != nullptr) {
		node = node->rightChild;
	}
	return node;
}

BSTNode* RBTree::RBTreeGetSibling(BSTNode* node) {
	if (node->parent != nullptr) {
		if (node == node->parent->leftChild)
			return node->parent->rightChild;
		return node->parent->leftChild;
	}
	return nullptr;
}

bool RBTree::RBTreeIsNonNullAndRed(BSTNode* node) {
	if (node == nullptr)
		return false;
	return (!node->isBlack);
}

bool RBTree::RBTreeIsNullOrBlack(BSTNode* node) {
	if (node == nullptr)
		return true;
	return (node->isBlack);
}

bool RBTree::RBTreeAreBothChildrenBlack(BSTNode* node) {
	if (node->leftChild != nullptr && !node->leftChild->isBlack)
		return false;
	if (node->rightChild != nullptr && !node->rightChild->isBlack)
		return false;
	return true;
}

void RBTree::RBTreePrepareForRemoval(BSTNode* node) {
	if (RBTreeTryCase1(node))
		return;

	BSTNode* sibling = RBTreeGetSibling(node);
	if (RBTreeTryCase2(node, sibling));
	sibling = RBTreeGetSibling(node);
	if (RBTreeTryCase3(node, sibling))
		return;
	if (RBTreeTryCase4(node, sibling))
		return;
	if (RBTreeTryCase5(node, sibling))
		sibling = RBTreeGetSibling(node);
	if (RBTreeTryCase6(node, sibling))
		sibling = RBTreeGetSibling(node);

	sibling->isBlack = node->parent->isBlack;
	node->parent->isBlack = true;
	if (node == node->parent->leftChild) {
		sibling->rightChild->isBlack = true;
		RBTreeRotateLeft(node->parent);
	}
	else {
		sibling->leftChild->isBlack = true;
		RBTreeRotateRight(node->parent);
	}
}


bool RBTree::RBTreeTryCase1(BSTNode* node) {
	if (!node->isBlack || node->parent == nullptr)
		return true;
	else
		return false; // not case 1
}

bool RBTree::RBTreeTryCase2(BSTNode* node, BSTNode* sibling) {
	if (!sibling->isBlack) {
		node->parent->isBlack = false;
		sibling->isBlack = true;
		if (node == node->parent->leftChild)
			RBTreeRotateLeft(node->parent);
		else
			RBTreeRotateRight(node->parent);
		return true;
	}
	return false; // not case 2
}

bool RBTree::RBTreeTryCase3(BSTNode* node, BSTNode* sibling) {
	if (node->parent->isBlack &&
		RBTreeAreBothChildrenBlack(sibling)) {
		sibling->isBlack = false;
		RBTreePrepareForRemoval(node->parent);
		return true;
	}
	return false; // not case 3
}

bool RBTree::RBTreeTryCase4(BSTNode* node, BSTNode* sibling) {
	if (!node->parent->isBlack &&
		RBTreeAreBothChildrenBlack(sibling)) {
		node->parent->isBlack = true;
		sibling->isBlack = false;
		return true;
	}
	return false; // not case 4
}

bool RBTree::RBTreeTryCase5(BSTNode* node, BSTNode* sibling) {
	if (RBTreeIsNonNullAndRed(sibling->leftChild) &&
		RBTreeIsNullOrBlack(sibling->rightChild) &&
		node == node->parent->leftChild) {
		sibling->isBlack = false;
		sibling->leftChild->isBlack = true;
		RBTreeRotateRight(sibling);
		return true;
	}
	return false; // not case 5
}



bool RBTree::RBTreeTryCase6(BSTNode* node, BSTNode* sibling) {
	if (RBTreeIsNullOrBlack(sibling->leftChild) &&
		RBTreeIsNonNullAndRed(sibling->rightChild) &&
		node == node->parent->rightChild) {
		sibling->isBlack = false;
		sibling->rightChild->isBlack = true;
		RBTreeRotateLeft(sibling);
		return true;
	}
	return false; // not case 6
}