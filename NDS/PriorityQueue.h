#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H
#include "stdin.h"
#include <deque>
#include "Heap.h"
#include <queue>

template <class T>
class PriorityQueue {
public:
	std::deque<T> queue;
//	std::list<T> queue;
	void enqueue(T val);
	T dequeue();
	T peek();
	bool isEmpty();
	int getLength();


};

class PriorityHeap {
	MinHeap mhp;

	void enqueue(int val);
	int dequeue();
	int peek();
	bool isEmpty();
	int getLength();
};

template <class T>
void PriorityQueue<T>::enqueue(T val) {
	//std::cout << "Ok" << std::endl;
	if (queue.size() == 0 || val >= queue[queue.size() - 1]) {
		queue.push_back(val);
		return;
	}
	for (int i = 0; i < queue.size(); i++) {
		if (val < queue[i]) {
			queue.emplace(queue.begin() + i, val);
			return;
		}
	}
	//std::cout << "Ok?" << std::endl;
	//Something went horribly wrong
	abort();
}

template <class T>
T PriorityQueue<T>::dequeue() {
	T ret = queue.front();
	queue.pop_front();
	return ret;
}
template <class T>
T PriorityQueue<T>::peek() {
	return queue.front();
}
template <class T>
bool PriorityQueue<T>::isEmpty() {
	return queue.empty();
}
template <class T>
int PriorityQueue<T>::getLength() {
	return queue.size();
}



#endif