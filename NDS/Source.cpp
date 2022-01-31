#include "stdin.h"
#include "sorting.h"


int main() {
	cout << setw(10) << left << "Dog Age" << "|";
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

	Sorts sort;
	const int size = 1e4;
	int arr[size];
	sort.FillArr(arr, size);
	
	sort.SelectionSort(arr, size);
	sort.BubbleSort(arr, size);
	sort.InsertionSort(arr, size);

	return 0;
}

void NumBitsDif(int word1, int word2) {

}