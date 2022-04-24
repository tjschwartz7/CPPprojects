#include "stdin.h"
#include "sorting.h"
#include "BST.h"
#include "Heap.h"
#include "Trie.h"
#include "autocompletion.h"
#include "searchbar.h"
#include "PriorityQueue.h"
#include "Graph.h"
#include "LL.h"
#include "algorithms.h"
#include "huffman.h"
using namespace std;
int main() {
	huffmanDecoding hd;
	std::string codes = hd.HuffmanCompress("Secret compartment of my secret box");

	std::string output = hd.HuffmanDecompress(codes, hd.root);
	cout << "Codes: " << codes << " Output: " << output << endl;

	/*cout << setw(10) << left << "Dog Age" << "|";
	cout << setw(12) << right << "Human Age" << endl;
	cout << setfill('-') << setw(23) << "" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "2 months" << "|";
	cout << setw(12) << right << "14 months" << endl;
	cout << setw(10) << left << "6 months" << "|";
	cout << setw(12) << right << "5 years" << endl;
	cout << setw(10) << left << "8 months" << "|";
	cout << setw(12) << right << "9 years" << endl;
	cout << setw(10) << left << "1 year" << "|";
	cout << setw(12) << right << "15 years" << endl;

	// Produce long line
	cout << setfill('-') << setw(23) << "" << endl;

	string str = "Amy";
	cout << setw(6) << setfill('.') << str << endl;
	*/

	
//	std::cout << *pa << " " << pb << std::endl;
	/*LLNode<int> ln;
	int t = 1;
	ln.push_front(0);
	ln.push_back(1);
	ln.push_back(5);
	ln.push_back(6);
	ln.insert(ln.search(1), 2);
	ln.insert(ln.search(2), 3);
	ln.insert(ln.search(3), 4);
	ln.insert(ln.search(6), 7);
	//std::cout << ln.tail->data << std::endl;
	//ln.insert(ln.search(5), 6);
	//std::cout << ln.tail->data << " ";
	//std::cout << ln.tail->data << std::endl;
	//ln.remove(2);
	ln.push_back(8);
	ln.insert(ln.search(8), 9);
	ln.push_front(-1);
	//ln.remove(4);
	//std::cout << ln.tail->data << " ";

	Node<int>* cur = ln.head;
	while (cur != nullptr) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;

	AdjacencyMatrix am;
	am.insertVertex();
	am.insertVertex();
	am.insertVertex();
	am.insertVertex();
	am.insertVertex();
	am.insertVertex();
	am.insertVertex();
	am.insertEdge(0, 1);
	am.insertEdge(1, 2);
	am.insertEdge(5, 2);
	am.printMatrix();

	MinHeap mhp;
	mhp.MinHeapInsert(5);
	mhp.MinHeapInsert(2);
	mhp.MinHeapInsert(7);
	mhp.MinHeapInsert(9);
	mhp.MinHeapInsert(8);
	mhp.MinHeapInsert(4);
	mhp.MinHeapInsert(1);
	mhp.MinHeapInsert(0);
	mhp.MinHeapRemove();

	for(int i = 0; i < mhp.heapArray.size(); i++)
	std::cout << mhp.heapArray[i] << std::endl;
	std::cout << std::endl;



	//mhp.heapsort(v);
	/*
	Autocomplete ac;
	Searchbar sb;
	while(true)
	sb.SBWordInput();
	*/
	/*

	Digraph ag;
	ag.insertVertex('A');
	ag.insertVertex('B');
	ag.insertVertex('C');
	ag.insertVertex('D');
	ag.insertEdge('A', 'B', 3);
	ag.insertEdge('A', 'C', 2);
	ag.insertEdge('B', 'C', 5);
	ag.insertEdge('B', 'D', 1);
	ag.insertEdge('D', 'C', 7);
	ag.insertEdge('C', 'D', 9);

	ag.printAdjacencies();
	Algos alg;
	std::cout << ag.vertices[0].front->next->weight << std::endl;
	ag.BFS(ag.vertices[0]);
	ag.DFS(ag.vertices[3]);
	cout << "Dijkstra" << endl;
	alg.DijkstraShortestPath(ag.vertices[0], &ag);
	for (auto al : ag.vertices) {
		cout << "Data: " << al.data << " Edges: ";
		auto edge = al.front;
		while (edge != nullptr) {
			cout << "Distance from startV: " << edge->distance;
			cout << " Previous: " << edge->predV << " Edge weight: " << edge->weight << endl;
			edge = edge->next;
		}
	}
	Digraph dg;
	dg.insertVertex('A');
	dg.insertVertex('B');
	dg.insertVertex('C');
	dg.insertEdge('A', 'B');
	dg.insertEdge('B', 'C');
	dg.insertEdge('C', 'A');
	dg.printAdjacencies();
	*/
	return 0;


}
