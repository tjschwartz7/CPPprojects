#include "stdin.h"
#include "sorting.h"
#include "DataStructures.h"


int main() {
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


	Sorts sort;
	int numbers[] = { 45, 57, 66, 41, 49, 18, 68, 69, 77, 95 };
	sort.Partition(numbers, 0, 5);


	Trie* tr = new Trie();
	tr->insert(tr->root, "Apple");
	std::cout << std::endl;
	tr->insert(tr->root, "Apply");
	tr->insert(tr->root, "Applying");
	tr->insert(tr->root, "Applies");
	tr->insert(tr->root, "Please");
	tr->insert(tr->root, "Pleasing");
	tr->insert(tr->root, "Jump");
	tr->insert(tr->root, "Jumping");
	tr->insert(tr->root, "Jumps");
	std::cout<<tr->insert(tr->root, "Yolo")->word<<std::endl;
	std::cout << tr->search(tr->root, "Applying")->weight << std::endl;
	std::cout << tr->search(tr->root, "Applying")->weight << std::endl;
	std::cout << tr->search(tr->root, "Apply")->weight << std::endl;
	std::cout << std::endl;
	tr->printTrie();

	//Returns "Applying" with weight=6
	std::cout << std::endl << tr->weightPriority("Appl") << std::endl;
	return 0;
}

void NumBitsDif(int word1, int word2) {

}