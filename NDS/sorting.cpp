#include "sorting.h"
#include "stdin.h"
#include <chrono>
using namespace std::chrono;

void Sorts::PrintArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Sorts::FillArr(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}


void Sorts::SelectionSort(int a[], int n) {
	auto t0 = system_clock::now();
	cout << "Selection Sort: " << endl;
	int smallestIndex;
	for (int i = 0; i < n; i++) {
		smallestIndex = i;
		for (int j = i+1; j < n; j++) {
			if (a[smallestIndex] > a[j])smallestIndex = j;
		}
		//swap
		int temp = a[smallestIndex];
		a[smallestIndex] = a[i];
		a[i] = temp;
	}
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;

	//PrintArr(a, n);
}

//this is a slightly more efficient version of bubblesort, which ends when it iterates through the
//array once without any swaps occurring. Usually, it is best and worst case O(N^2), as it uses two for loops i < size and j < size
void Sorts::BubbleSort(int a[], int n) {
	auto t0 = system_clock::now();
	cout << "Bubble Sort: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j] < a[j - 1]) {
				//initiate swap
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;

	//PrintArr(a, n);

}

void Sorts::InsertionSort(int a[], int n) {
	cout << "Insertion Sort: " << endl;
	auto t0 = system_clock::now();
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			--j;
		}
	}
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;
	//PrintArr(a, n);
}