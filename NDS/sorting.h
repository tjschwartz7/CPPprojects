#ifndef SORTING_H
#define SORTING_H

class Sorts {
public:
	void PrintArr(int a[], int n);
	void FillArr(int *a, int n);
	void SelectionSort(int a[], int n);
	void BubbleSort(int a[], int n);
	void InsertionSort(int a[], int n);
	void ShellSort(int a[], int n);
	void InsertionSortInterleaved(int *a, int n, int start, int gap);
	void Quicksort(int a[], int size);
	int Partition(int* a, int low, int high);
	void Quickselect(int a[], int n, int k);
	void Quicksortselect(int a[], int n, int k);
	void Mergesort(int a[], int n);
	void Bucketsort(int a[], int n, int numBuckets);
private:
	int Quickselect(int* a, int first, int last, int k);
	void Quicksort(int a[], int low, int high);
	void Mergesort(int a[], int i, int k);
	void Merge(int* a, int i, int j, int k);
};



#endif


