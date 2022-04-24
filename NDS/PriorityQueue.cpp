#include "PriorityQueue.h"

void PriorityHeap::enqueue(int val) {
	mhp.MinHeapInsert(val);
}

int PriorityHeap::dequeue() {
	return mhp.MinHeapRemove();
}

int PriorityHeap::peek() {
	return mhp.heapArray[0];
}

bool PriorityHeap::isEmpty() {
	return (mhp.heapArray.empty());
}

int PriorityHeap::getLength() {
	return mhp.heapArray.size();
}
