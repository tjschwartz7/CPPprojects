#ifndef LL_H
#define LL_H

template <class T>
class Node {
public:
	Node<T>(T data) { this->data = data; next = nullptr; };
	Node<T>() { next = nullptr; };
	Node<T>* next;
	T data;

};

template <class T>
class LLNode {
public:
	Node<T>* head;
	Node<T>* tail;
	LLNode() { head = nullptr; tail = head; };
	void insert(Node<T>* node, T data);
	void push_back(T data);
	void push_front(T data);
	void remove(T data);
	T pop_front();
	T pop_back();
	Node<T>* peek_front();
	Node<T>* peek_back();
	bool isEmpty();
	Node<T>* search(T data);
};

template <typename T>
void LLNode<T>::insert(Node<T>* node, T data) {
	if (node == nullptr) return;
	if (head == tail) {
		if (head == nullptr) {
			head = new Node<T>(data);
			tail = head;
			return;
		}
		head->next = new Node<T>(data);
		tail = head->next;
		return;
	}
	if (node == tail) {
		node->next = new Node<T>(data);
		tail = node->next;
		return;
	}
	Node<T>* curNext = node->next;
	curNext->data = node->next->data;
	curNext->next = node->next->next;
	node->next = new Node<T>(data);
	node = node->next;
	node->next = curNext;

}

template <typename T>
void LLNode<T>::push_back(T data) {
	if (head == tail) {
		if (head == nullptr) {
			head = new Node<T>(data);
			tail = head;
			return;
		}
		head->next = new Node<T>(data);
		tail = head->next;
		return;
	}
	Node<T>* cur = tail;
	cur->next = new Node<T>(data);
	tail = cur->next;
	cur = nullptr;
}


template <typename T>
void LLNode<T>::push_front(T data) {
	if (head == tail) {
		if (head == nullptr) {
			head = new Node<T>(data);
			tail = head;
			return;
		}
		head->next = new Node<T>(data);
		tail = head->next;
		return;
	}
	Node<T>* curNext = head;
	curNext->data = head->data;
	curNext->next = head->next;
	head = new Node<T>(data);
	head->next = curNext;
}

template <typename T>
void LLNode<T>::remove(T data) {
	Node<T>* prev = nullptr;
	Node<T>* cur = head;

	while (cur != nullptr) {
		if (cur->data == data) {
			if (cur == tail) tail = prev;
			if (cur == head) head = head->next;
			prev->next = cur->next;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}
template <typename T>
Node<T>* LLNode<T>::search(T data) {
	Node<T>* cur = head;
	while (cur != nullptr) {
		if (cur->data == data) {
			return cur;
		}

		cur = cur->next;
	}
	return nullptr;
}

template <typename T>
T LLNode<T>::pop_front() {
	Node<T> ret = *head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		return ret.data;
	}
	head = head->next;
	return ret.data;
}

template <typename T>
T LLNode<T>::pop_back() {
	Node<T>* prev = nullptr;
	Node<T>* cur = head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		return cur->data;
	}

	while (cur != nullptr) {
		if (cur == tail) {
			Node<T> ret = *tail;
			tail = prev;
			return ret.data;
		}
		prev = cur;
		cur = cur->next;
	}
	return NULL;
}

template <typename T>
Node<T>* LLNode<T>::peek_front() { return head; }
template <typename T>
Node<T>* LLNode<T>::peek_back() { return tail; }
template <typename T>
bool LLNode<T>::isEmpty() { return head == nullptr; }

#endif // !LL_H


