#pragma once

template <class T>
class Array {
private:
	T* elements = nullptr;
	T* head;
	T* tail;
	int numElements = 0;
	int maxSize = 100;

public:
	Array() {
		numElements = 0;
	    maxSize = 100;
		elements = new T[maxSize];
		for (int i = 0; i < maxSize; i++)
			elements[i] = 0;
	}

	Array(int size) {
		numElements = 0;
		maxSize = size;
		elements = new T[maxSize];
		for (int i = 0; i < maxSize; i++)
			elements[i] = 0;
	}


	~Array() {
		delete[] elements;
	}

	int size() {
		return numElements;
	}

	int capacity() {
		return maxSize;
	}

	//& allows you to return by reference : if a change is made to the variable after being returned it effects the original copy
	T& operator[](int index) {
		return elements[index];
	}

	T& at(int index) {
		if (index >= numElements)
			throw std::out_of_range("Invalid index " + std::to_string(index));
		return operator[](index);
	}

	T* data() {
		return elements;
	}

	Array& operator=(Array& b) {
		if (elements != nullptr)
			delete[] elements;

		numElements = b.size();
		maxSize = b.capacity();
		elements = new T[maxSize];
		for (int i = 0; i < numElements; i++)
			elements[i] = b[i];
		for (int i = numElements; i < maxSize; i++)
			elements[i] = 0;

		return *this;
	}

	void resize() {
		maxSize *= 2;
		T* placeholder = new T(maxSize);
		elements = placeholder;
	}

	bool isEmpty() {
		return numElements == 0;
	}

	void insert(int index, T element) {
		
		if (numElements >= maxSize) {
			resize();
		}

		if (index > numElements) {
			throw("Index out of range");
		}
		
		for (int i = maxSize - 1; i >= index; i--) {
			elements[i + 1] = elements[i];
		}
		numElements++;
		//tail = &elements[numElements - 1];
		elements[index] = element;
	}

	void push_back(T element) {
		if (numElements >= maxSize) {
			resize();
		}
		//std::cout << "What is this" << std::endl;
		elements[numElements] = element;
		numElements++;

	}

	void enqueue(T element) {
		insert(0, element);
	}

	T dequeue() {
		if (isEmpty()) throw("Array is empty");
		T element = elements[0];
		remove(0);
		return element;
	}

	T remove(int index) {
		if (index >= numElements) {
			throw std::out_of_range("Index out of range");
		}
		T element = elements[index];
		for (int i = index; i < numElements; i++) {
			elements[i] = elements[i + 1];
		}
		numElements--;
		tail = elements[numElements];
		elements[index] = element;
		return element;
	}

	T pop_back() {
		T element = elements[numElements - 1];
		remove(numElements - 1);
		numElements--;
		return element;
	}
};