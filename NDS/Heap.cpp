
#include "Heap.h"



void MaxHeap::MaxHeapPercolateUp(int nodeIndex) {
	while (nodeIndex > 0) {
		int parentIndex = (nodeIndex - 1) / 2;
		if (heapArray[nodeIndex] <= heapArray[parentIndex])
			return;
		else {
			int temp = heapArray[parentIndex];
			heapArray[parentIndex] = heapArray[nodeIndex];
			heapArray[nodeIndex] = temp;
			nodeIndex = parentIndex;
		}
	}
}

void MaxHeap::MaxHeapPercolateDown(int nodeIndex, std::vector<double>& nums, int arraySize) {
	int childIndex = 2 * nodeIndex + 1;
		double value = nums[nodeIndex];
		while (childIndex < arraySize) {
			// Find the max among the node and all the node's children
			double maxValue = value;
			int maxIndex = -1;
				for (int i = 0; i < 2 && i + childIndex < arraySize; i++) {
					if (nums[i + childIndex] > maxValue) {
						maxValue = nums[i + childIndex];
						maxIndex = i + childIndex;
					}
				}

			if (maxValue == value) {
				return;
			}
			else {
				double temp = nums[nodeIndex];
				nums[nodeIndex] = nums[maxIndex];
				nums[maxIndex] = temp;
				nodeIndex = maxIndex;
				childIndex = 2 * nodeIndex + 1;
			}
		}
}

void MaxHeap::MaxHeapInsert(double key) {
	heapArray.push_back(key);
	MaxHeapPercolateUp(heapArray.size()-1);
}

double MaxHeap::MaxHeapRemove() {
	int temp = heapArray[0];
	heapArray[0] = heapArray[heapArray.size() - 1];
	heapArray.pop_back();
	MaxHeapPercolateDown(0, heapArray, heapArray.size());
	return temp;
}


void MaxHeap::heapsort(std::vector<double>& nums) {
	// Heapify numbers array
	for (int i = nums.size() / 2.0 - 1; i >= 0; i--) {
		MaxHeapPercolateDown(i, nums, nums.size());
	}

	for (int i = 0; i < nums.size(); i++)
		std::cout << nums[i] << " ";

	for (int i = nums.size() - 1; i > 0; i--) {
		int temp = nums[0];
		nums[0] = nums[i];
		nums[i] = temp;
		MaxHeapPercolateDown(0, nums, i);
	}
}




void MinHeap::MinHeapPercolateUp(int nodeIndex) {
	while (nodeIndex > 0) {
		int parentIndex = (nodeIndex - 1) / 2;
		if (heapArray[nodeIndex] >= heapArray[parentIndex])
			return;
		else {
			int temp = heapArray[parentIndex];
			heapArray[parentIndex] = heapArray[nodeIndex];
			heapArray[nodeIndex] = temp;
			nodeIndex = parentIndex;
		}
	}
}

void MinHeap::MinHeapPercolateDown(int nodeIndex, std::vector<double>& nums, int arraySize) {
	int childIndex = 2 * nodeIndex + 1;
	double value = nums[nodeIndex];
	while (childIndex < arraySize) {
		// Find the min among the node and all the node's children
		double minValue = value;
		int minIndex = -1;
		for (int i = 0; i < 2 && i + childIndex < arraySize; i++) {
			if (nums[i + childIndex] < minValue) {
				minValue = nums[i + childIndex];
				minIndex = i + childIndex;
			}
		}

		if (minValue == value) {
			return;
		}
		else {
			double temp = nums[nodeIndex];
			nums[nodeIndex] = nums[minIndex];
			nums[minIndex] = temp;
			nodeIndex = minIndex;
			childIndex = 2 * nodeIndex + 1;
		}
	}
}

void MinHeap::MinHeapInsert(double key) {
	heapArray.push_back(key);
	MinHeapPercolateUp(heapArray.size() - 1);
}

void MinHeap::heapsort(std::vector<double>& nums) {
	// Heapify numbers array
	for (int i = nums.size() / 2.0 - 1; i >= 0; i--) {
		MinHeapPercolateDown(i, nums, nums.size());
	}

	for (int i = nums.size() - 1; i > 0; i--) {
		int temp = nums[0];
		nums[0] = nums[i];
		nums[i] = temp;
		MinHeapPercolateDown(0, nums, i);
	}
}

//Incomplete

double MinHeap::MinHeapRemove() {
	int temp = heapArray[0];
	heapArray[0] = heapArray[heapArray.size() - 1];
	heapArray.pop_back();
	MinHeapPercolateDown(0, this->heapArray, heapArray.size());
	return temp;
}


BSTNode* Treap::TreapInsert(double val) {
	BSTNode* cur = bst.BSTInsert(new BSTNode(val));
	srand(time(NULL));
	cur->priority = rand() % 101;
	//Needs to percolate into position based on priority


	return cur;
}

/*
double Treap::TreapRemove(double val) {

}

BSTNode* Treap::TreapSearch(double val) {

}
*/