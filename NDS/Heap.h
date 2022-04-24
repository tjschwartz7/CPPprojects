#ifndef HEAP_H
#define HEAP_H


#include "BST.h"





class MaxHeap {
public:
	std::vector<double> heapArray;
	void MaxHeapInsert(double key);
	void MaxHeapPercolateUp(int nodeIndex);
	void MaxHeapPercolateDown(int nodeIndex, std::vector<double>& nums, int arraySize);
	double MaxHeapRemove();
	void heapsort(std::vector<double>& nums);
};

class MinHeap {
public:
	std::vector<double> heapArray;
	void MinHeapInsert(double key);
	void MinHeapPercolateUp(int nodeIndex);
	void MinHeapPercolateDown(int nodeIndex, std::vector<double>& nums, int arraySize);
	double MinHeapRemove();
	void heapsort(std::vector<double>& nums);
};

class Treap {
	BST bst;
	Treap();
	BSTNode* TreapInsert(double val);
	double TreapRemove(double val);
	BSTNode* TreapSearch(double val);

};

#endif // !HEAP_H


