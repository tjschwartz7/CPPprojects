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
	tr->insert(tr->root, "Apply");
	tr->insert(tr->root, "Please");
	std::cout<<tr->insert(tr->root, "Yolo")->letter<<std::endl;
	std::cout << tr->search(tr->root, "Yolo")->weight << std::endl;
	return 0;
}

void NumBitsDif(int word1, int word2) {

}