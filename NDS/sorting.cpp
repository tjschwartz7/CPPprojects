#include "sorting.h"
#include "stdin.h"
#include <chrono>
using namespace std::chrono;
#include <vector>
//Gives us the vector sort function
#include <algorithm>

void Sorts::PrintArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void Sorts::FillArr(int *a, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % rand();
	}
}

//O(N^2)
void Sorts::SelectionSort(int a[], int n) {
	//PrintArr(a, n);
	std::cout << "Selection Sort: " << std::endl;
	auto t0 = system_clock::now();
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
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

	//PrintArr(a, n);
}

//this is a slightly more efficient version of bubblesort, which ends when it iterates through the
//array once without any swaps occurring. Usually, it is best and worst case O(N^2), as it uses two for loops i < size and j < size
//O(N^2)
void Sorts::BubbleSort(int a[], int n) {
	//PrintArr(a, n);
	std::cout << "Bubble Sort: " << std::endl;
	auto t0 = system_clock::now();
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
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

	//PrintArr(a, n);

}


//O((N-1)*(N/2))
void Sorts::InsertionSort(int a[], int n) {
	//PrintArr(a, n);
	std::cout << "Insertion Sort: " << std::endl;
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
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
	//PrintArr(a, n);
}

void Sorts::ShellSort(int a[], int n) {
	//PrintArr(a, n);
	std::cout << "Shell Sort: " << std::endl;
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
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
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
	std::cout << "Quicksort: " << std::endl;
	auto t0 = system_clock::now();
	Quicksort(a, 0, n - 1);
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
	PrintArr(a, n);
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
	PrintArr(a, high);
	PrintArr(a, low);
	//PrintArr(a, high+1);
	return high;
}

//this is the base recursive function for quickselect
int Sorts::Quickselect(int *a, int first, int last, int k) {
	if (first >= last)
		return a[first];
	int lowLastIndex = Partition(a, first, last);

	if (k <= lowLastIndex)
		return Quickselect(a, first, lowLastIndex, k);
	return Quickselect(a, lowLastIndex + 1, last, k);

}


//This is the same as calling quicksort and returning index of k
//BUT this is actually faster since it is not required to sort the entire list - it could sort only a portion and get its answer
//also- this function is the version of quickselect to be called externally - it contains the output data and timer
void Sorts::Quickselect(int a[], int n, int k) {
	//PrintArr(a, n);
	std::cout << "Quickselect: " << std::endl;
	auto t0 = system_clock::now();
	int out = Quickselect(a, 0, n - 1, k);
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
	std::cout << "Smallest kth number at k = " << k << ": " << " : Number = " << out << std::endl;
}

void Sorts::Quicksortselect(int a[], int n, int k) {
	//PrintArr(a, n);
	std::cout << "Quicksortselect: " << std::endl;
	auto t0 = system_clock::now();
	Quicksort(a, 0, n - 1);
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
	std::cout << "Smallest kth number at k = " << k << ": " << " : Number = " << a[k] << std::endl;
}

void Sorts::Mergesort(int a[], int i, int k) {
	int j = 0;
	if (i < k) {
		j = (i + k) / 2;
		Mergesort(a, i, j);
		Mergesort(a, j + 1, k);

		Merge(a, i, j, k);
	}
}

void Sorts::Merge(int* a, int i, int j, int k) {
	//PrintArr(a, k);
	int mergedSize = k - i + 1;
	int mergePos = 0;
	int leftPos = 0;
	int rightPos = 0;
	int *mergedNumbers = new int[mergedSize];
	leftPos = i;
	rightPos = j + 1;
	while (leftPos <= j && rightPos <= k) {
		if (a[leftPos] <= a[rightPos]) {
			mergedNumbers[mergePos] = a[leftPos];
			++leftPos;
		}
		else {
			mergedNumbers[mergePos] = a[rightPos];
			++rightPos;
		}
		++mergePos;
	}

	//if left partition is not empty, add remaining elements to merged nums
	while (leftPos <= j) {
		mergedNumbers[mergePos] = a[leftPos];
		++leftPos;
		++mergePos;
	}

	//if right partition is not empty, add remaining elements to merged nums
	while (rightPos <= k) {
		mergedNumbers[mergePos] = a[rightPos];
		++rightPos;
		++mergePos;
	}

	//copy merge numbers back to numbers
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
		a[i + mergePos] = mergedNumbers[mergePos];
	}

}

void Sorts::Mergesort(int a[], int n) {
	//PrintArr(a, n);
	std::cout << "Mergesort: " << std::endl;
	auto t0 = system_clock::now();
	Mergesort(a, 0, n - 1);
	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;
	//PrintArr(a, n);
}


//just passing int a[] is not passing an array
//its actually just passing a pointer int *a;
//I used this solution to force it to act like an array
void Sorts::Bucketsort(int a[], int n, int numBuckets) {
	PrintArr(a, n);
	std::cout << "Bucket Sort: " << std::endl;
	auto t0 = system_clock::now();
	if (n < 1) {
		return;
	}

	std::vector<std::vector<int>> buckets(numBuckets);
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}

	//put each num in a bucket

	for (int i = 0; i < n; i++) {
		int index = floor(i * numBuckets / (max + 1));
		buckets[index].push_back(a[i]);
	}

	//sort buckets
	for (std::vector<int> bucket : buckets)
		sort(bucket.begin(), bucket.end());

	//combine the buckets
	std::vector<int> result(n);
	for (int i = 0; i < numBuckets; i++)
		result.insert(result.begin(), buckets[i].begin(), buckets[i].end());

	auto t1 = system_clock::now();
	duration<double> elapsed_seconds = t1 - t0;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

	for (int out : result)
		std::cout << out << " ";
}