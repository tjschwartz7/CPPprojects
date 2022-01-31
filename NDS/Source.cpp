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
	const int size = 5e3;
	int arr[size];
	sort.FillArr(arr, size);
	int arr1[size];
	int arr2[size];
	int arr3[size];
	int arr4[size];
	copy(begin(arr), end(arr), begin(arr1));
	copy(begin(arr), end(arr), begin(arr2));
	copy(begin(arr), end(arr), begin(arr3));
	copy(begin(arr), end(arr), begin(arr4));
	sort.SelectionSort(arr1, size);
	sort.BubbleSort(arr2, size);
	sort.InsertionSort(arr3, size);
	sort.ShellSort(arr4, size);

	return 0;
}

void NumBitsDif(int word1, int word2) {

}