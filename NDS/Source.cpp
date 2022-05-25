#define _CRT_SECURE_NO_WARNINGS
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
#include <chrono> 
#include "UnboundedArray.h"

using namespace std;
void terminal();

int main() {
	terminal();
	huffmanDecoding hd;
	std::string codes = hd.HuffmanCompress("ACTG");

	std::string output = hd.HuffmanDecompress(codes, hd.root);
	cout << "Codes: " << codes << " Output: " << output << endl;
	cout << "Codes length: " << codes.length() << " Output string size: " << output.length() << endl;
	cout << "Bits to character ratio: " << codes.length() / (double)output.length() << endl;
	cout << "Standard bit representation no compression: " << output.length() * 8 << endl;

	Algos al;
	cout << al.ShuntingYard("2*2-3-3+7") << endl;
	cout << al.ShuntingYard("2-1*9+8-3") << endl;
	cout << al.ShuntingYard("2+2*4") << endl;
	cout << al.ShuntingYard("2+2*4^2") << endl;
	cout << al.LongestCommonSubstring("CTCAAG", "CAAG") << endl;
	cout << "LCS problem: " << al.DynamicLongestCommonSubstring("myassisgrass", "sassiest") << endl;
	cout << al.FibonacciNumber(24) << endl;
	//std::string scrambledLetters = al.scramble(codes, 503, 3);
	//cout << scrambledLetters << endl;
	//cout << al.descramble(scrambledLetters, 503, 3, codes.size()) << endl;
	std::string hexCode = al.BinaryToHexConverter("111010");
	cout << hexCode << endl;
	cout << al.HexToBinaryConverter(hexCode) << endl;
	cout << al.HexBinaryConversionTester(100000) << endl;
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
void printOptions();
void printAlgorithms();
void fibonacci();
void binaryToHex();
void hexToBinary();
void scramble();
void descramble();
void shuntingYard();
void math();
void huffman();
void longestCommonSubstring();
void longestCommonSubstringOld();
void fizzbuzz();
void createArray(Array<double>& arr);
void viewArray(Array<double>& arr);
void printDataStructures();

void terminal() {
	Array<double> arr(10);
	map<string, int> options = { {"?", 0}, {"ALGORITHMS", 1}, {"FIBONACCI", 2}, {"HEXTOBINARY", 3}, {"BINARYTOHEX", 4}, {"SCRAMBLE", 5}, {"DESCRAMBLE", 6}, {"MATH", 7}, {"SHUNTINGYARD", 8},
		{"42", 9}, {"HUFFMAN", 10},{"DYNAMICALLYBROKEN", 11}, {"LONGESTCOMMONSUBSTRING", 12}, {"FOO", 13}, {"FIZZBUZZ", 14}, {"HELLOWORLD", 15}, {"TIME", 16}, {"CREATEARRAY", 17}, {"VIEWARRAY", 18}, {"DATASTRUCTURES", 19} };
	string input;
	cout << ":>>";
	cin >> input;
	for (int i = 0; i < input.size(); i++) input[i] = toupper(input[i]);
	int option = options[input];
	while (input != "EXIT") {
		auto time = std::chrono::system_clock::now();
		std::time_t cur_time = std::chrono::system_clock::to_time_t(time);
		switch (option) {
		case 0:
			cout << "Options include: " << endl;
			printOptions();
			break;
		case 1:
			cout << "Please enter a specific algorithm. Options include:" << endl;
			printAlgorithms();

			break;
		case 2:
			fibonacci();

			break;
		case 3:
			hexToBinary();
			break;
		case 4:
			binaryToHex();
			break;
		case 5:
			scramble();
			break;
		case 6:
			descramble();
			break;
		case 7:
			math();
			break;
		case 8:
			shuntingYard();
			break;
		case 9:
			for (int j = 0; j < 42; j++) cout << "the end is never ";
			break;
		case 10:
			huffman();
			break;
		case 11:
			longestCommonSubstring();
			break;
		case 12:
			longestCommonSubstringOld();
			break;
		case 13:
			cout << "bar" << endl;
			break;
		case 14:
			fizzbuzz();
			break;
		case 15:
			cout << "Hello user!" << endl;
			break;
		case 16:
			std::cout << "It is currently " << std::put_time(std::localtime(&cur_time), "%F %T") << std::endl;
			break;
		case 17:
			createArray(arr);
			break;
		case 18:
			viewArray(arr);
			break;
		case 19:
			printDataStructures();
			break;
		}
		cout << endl << ":>>";
		cin >> input;
		for (int i = 0; i < input.size(); i++) input[i] = toupper(input[i]);
		option = options[input];
	}
}


void printOptions() {
	cout << "Algorithms" << endl;
	cout << "DataStructures" << endl;
	cout << "Math" << endl;
}
void printAlgorithms() {
	cout << "Fizzbuzz" << endl;
	cout << "BinaryToHex" << endl;
	cout << "HexToBinary" << endl;
	cout << "Fibonacci" << endl;
	cout << "Scramble" << endl;
	cout << "Descramble" << endl;
	cout << "ShuntingYard" << endl;
	cout << "LongestCommonSubstring" << endl;
	cout << "Huffman" << endl;
}

void printDataStructures() {
	cout << "Functions: CREATE/VIEW" << endl;
	cout << "Array" << endl;
}

void fibonacci() {
	Algos algorithms;
	int termIndex = 1;
	cout << "Enter which term index of the Fibonacci Sequence you would like to receive: ";
	cin >> termIndex;
	while (termIndex == 0) {
		cout << "Invalid input; Please enter a non-zero integer: ";
		cin >> termIndex;
	}
	auto t1 = std::chrono::system_clock::now();
	int fibNum = algorithms.FibonacciNumber(termIndex);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << "The fibonacci number at term index " << termIndex << " is " << fibNum << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void binaryToHex() {
	Algos algorithms;
	string binaryCodes = "";
	cout << "Please enter a binary sequence (Press any key other than 1 or 0 to exit): ";
	char key;
	cin >> key;
	while (key == '1' || key == '0') {
		binaryCodes += key;
		cin >> key;
	}
	auto t1 = std::chrono::system_clock::now();
	string hexCodes = algorithms.BinaryToHexConverter(binaryCodes);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << "The output hex codes: " << hexCodes << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void hexToBinary() {
	Algos algorithms;
	string hexCodes = "";
	cout << "Please enter a hex sequence (Press any key other than 0-9 a-f to exit): ";
	char key;
	cin >> key;
	while ((key - '0' < 10 && key - '0' >= 0) || (toupper(key) - 'A' >=0 && toupper(key) - 'A' <= 5)) {
		hexCodes += key;
		cin >> key;
	}
	//cout << "The input: " << hexCodes << endl;
	auto t1 = std::chrono::system_clock::now();
	string binaryCodes = algorithms.HexToBinaryConverter(hexCodes);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << "The output binary codes: " << binaryCodes << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void scramble() {
	Algos algorithms;
	string binaryCodes = "";
	cout << "Please enter a binary sequence (Press any key other than 1 or 0 to exit): ";
	char key;
	cin >> key;
	while (key == '1' || key == '0') {
		binaryCodes += key;
		cin >> key;
	}

	cout << "How many operations to perform: ";
	int operations;
	cin >> operations;
	while (operations == 0) {
		cout << "Please enter a nonzero integer: ";
		cin >> operations;
	}
	cout << endl;
	int numKey = 0;
	cout << "Enter some integer key: ";
	cin >> numKey;
	auto t1 = std::chrono::system_clock::now();
	string scrambledOutput = algorithms.scramble(binaryCodes, operations, numKey);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << "The codes: " << scrambledOutput << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

}

void descramble() {
	Algos algorithms;
	string binaryCodes = "";
	cout << "Please enter a string value to descramble: ";
	string codes;
	cin >> codes;


	cout << "How many operations to perform: ";
	int operations;
	cin >> operations;
	while (operations == 0) {
		cout << "Please enter a nonzero integer: ";
		cin >> operations;
	}
	cout << endl;
	int numKey = 0;
	cout << "Enter some integer key: ";
	cin >> numKey;

	cout << "How the original length of bits: ";
	int size;
	cin >> size;
	while (size == 0) {
		cout << "Please enter a nonzero integer: ";
		cin >> size;
	}
	cout << endl;

	auto t1 = std::chrono::system_clock::now();
	string bits = algorithms.descramble(codes, operations, numKey, size);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << "The output bits: " << bits << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void shuntingYard() {
	Algos algorithms;
	string arithmeticSequence;
	cout << "Enter an arithmetic sequence: ";
	cin >> arithmeticSequence;
	auto t1 = std::chrono::system_clock::now();
	string output = algorithms.ShuntingYard(arithmeticSequence);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << endl << "The output sequence: " << output << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void math() {
	Algos algorithms;
	string arithmeticSequence;
	cout << "Enter an arithmetic sequence: ";
	cin >> arithmeticSequence;
	algorithms.ShuntingYard(arithmeticSequence);
	auto t1 = std::chrono::system_clock::now();
	string output = algorithms.ShuntingYard(arithmeticSequence);
	int answer = algorithms.ShuntingYardSolver(output);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << endl << "Output: " << answer << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void huffman() {
	huffmanDecoding huffman;
	string input;
	cout << "Enter a string: ";
	cin >> input;
	auto t1 = std::chrono::system_clock::now();
	std::string codes = huffman.HuffmanCompress(input);

	std::string output = huffman.HuffmanDecompress(codes, huffman.root);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << endl << "Huffman codes: " << codes << endl;
	cout << "Codes: " << codes << " Output: " << output << endl;
	cout << "Codes length: " << codes.length() << " Output string size: " << output.length() << endl;
	cout << "Bits to character ratio: " << codes.length() / (double)output.length() << endl;
	cout << "Standard bit representation no compression: " << output.length() * 8 << " bits total." << endl;
	std::cout << "Elapsed time during compression and decompression: " << elapsed_seconds.count() << "s" << std::endl;
}

void longestCommonSubstring() {
	Algos algorithms;
	string input1;
	cout << "Enter an string: ";
	cin >> input1;
	for (int i = 0; i < input1.size(); i++) input1[i] = toupper(input1[i]);
	string input2;
	cout << "Enter a shorter string: ";
	cin >> input2;
	for (int i = 0; i < input2.size(); i++) input2[i] = toupper(input2[i]);
	auto t1 = std::chrono::system_clock::now();
	string output = algorithms.DynamicLongestCommonSubstring(input1, input2);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << endl << "Longest common substring: " << output << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void longestCommonSubstringOld() {
	Algos algorithms;
	string input1;
	cout << "Enter an string: ";
	cin >> input1;
	for (int i = 0; i < input1.size(); i++) input1[i] = toupper(input1[i]);
	string input2;
	cout << "Enter a shorter string: ";
	cin >> input2;
	for (int i = 0; i < input2.size(); i++) input2[i] = toupper(input2[i]);
	auto t1 = std::chrono::system_clock::now();
	string output = algorithms.LongestCommonSubstring(input1, input2);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << endl << "Longest common substring: " << output << endl;
	std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
}

void fizzbuzz() {
	int fizz;
	cin >> fizz;
	while (fizz > 0) {
		if (fizz % 3 == 0 && fizz % 5 == 0) cout << "FIZZBUZZ";
		else if (fizz % 3 == 0) cout << "FIZZ";
		else if (fizz % 5 == 0) cout << "BUZZ";
		else cout << fizz;
		fizz--;
		cout << endl;
	}
}

void createArray(Array<double>& arr) {

	cout << "Enter a double value(0 to leave): ";
	double input;
	cin >> input;
	while (input != 0) {
		if (input == -999)
		{
			viewArray(arr);
		}
		else {
			arr.push_back(input);
		}


		cout << endl << "Enter a double value (0 to leave or -999 to print the list): ";
		cin >> input;
	}

}

void viewArray(Array<double>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}