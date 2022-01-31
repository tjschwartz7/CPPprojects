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
	void Quicksort(int a[], int low, int high);
	int Partition(int* a, int low, int high);
};



#endif


