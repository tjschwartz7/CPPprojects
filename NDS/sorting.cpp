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

//O(N^2)
void Sorts::SelectionSort(int a[], int n) {
	//PrintArr(a, n);
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
//O(N^2)
void Sorts::BubbleSort(int a[], int n) {
	//PrintArr(a, n);
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


//O((N-1)*(N/2))
void Sorts::InsertionSort(int a[], int n) {
	//PrintArr(a, n);
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

void Sorts::ShellSort(int a[], int n) {
	//PrintArr(a, n);
	cout << "Shell Sort: " << endl;
	auto t0 = system_clock::now();

	//Call insertion sort divvied between 3 different arrays each having size n / gap
	//Since insertion sort is faster on smaller lists, this will end up faster than your standard insertion sort
	int exp = floor(log2(n));
	int gap;
	for (int i = exp; i > 0; i--) {
		gap = pow(2, i) - 1;
		for (int i = 0; i < gap; i++) {
			InsertionSortInterleaved(a, n, i, gap);
		}

	}


	//This is essentially a standard insertion sort
	InsertionSortInterleaved(a, n, 0, 1);

	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;
	//PrintArr(a, n);
}

void Sorts::InsertionSortInterleaved(int *a, int n, int start, int gap) {
	int temp = 0;
	for (int i = start+gap; i < n; i+=gap) {
		int j = i;
		while (j - gap > start && a[j] < a[j - gap]) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - gap] = temp;
			j-=gap;
		}
	}

}

void Sorts::Quicksort(int a[], int n) {
	//PrintArr(a, n);
	cout << "Quicksort: " << endl;
	auto t0 = system_clock::now();
	Quicksort(a, 0, n - 1);
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;
	//PrintArr(a, n);
}

void Sorts::Quicksort(int a[], int low, int high) {
	if (low >= high) {
		return;
	}
	int lowEndIndex = Partition(a, low, high);
	Quicksort(a, low, lowEndIndex);
	Quicksort(a, lowEndIndex + 1, high);

}

int Sorts::Partition(int* a, int low, int high) {
	int midpoint = low + (high - low) / 2;
	int pivot = a[midpoint];
	bool done = false;
	while (!done) {
		while (a[low] < pivot) {
			low += 1;
		}
		while (pivot < a[high]) {
			high -= 1;
		}

		//if zero or one elements remain, then all numbers are partitioned.
		//Return highindex.
		if (low >= high) {
			done = true;
		}
		else {
			//swap 
			int temp = a[low];
			a[low] = a[high];
			a[high] = temp;

			low++;
			high--;
		}
	}
	return high;
}