/*
Author: Ediel Lopez
Course: CSE 100 - Algorithm Design and Analysis
Term: 	Fall 2019
Assignment: Implementation of the Quicksort Algorithm
*/

#include <iostream>
#include <cstdlib>	// srand, rand
#include <time.h>	// time
using namespace std;


// Function Prototype
void randomizedQuickSort(int Array[], int p, int r);
int randPartition(int Array[], int p, int r);
int partition(int Array[], int p, int r);

int main() {
	int size = 0, begin = 0;

	cin >> size;

	// Dynamic Memory Allocation. If memory allocation fails, then
	// the pointer returned by new is a null pointer.
	int *myList = new (nothrow) int[size];

	// Unable to allocate memory
	if (myList == nullptr)
		cout << "Memory could not be allocated!" << endl;
	else {
		// Get input stream
		for (int index = 0; index < size; index++) {
			cin >> myList[index];
		}
	}

	randomizedQuickSort(myList, begin, size-1);

	// Sorted Sequence
	for (int index = 0; index < size; index++) {
		cout << myList[index] << ";";
	}

	delete[] myList;	// Release the memory allocated
	return 0;
}

// Function Definition
void randomizedQuickSort(int Array[], int p, int r) {
	int q;

	if (p < r) {
		q = randPartition(Array, p, r);
		randomizedQuickSort(Array, p, q - 1);
		randomizedQuickSort(Array, q + 1, r);
	}
}

int randPartition(int Array[], int p, int r) {

	srand(time(NULL));		// Initialize Random Seed
	int i = (rand() % (r+1-p)) + p;	// Number between 1 and A.length
	swap(Array[r], Array[i]);	// exchange Array[r] and Array[i]


	return partition(Array, p, r);
}

int partition(int Array[], int p, int r) {

	int x = Array[r];	// pivot
	int i = p - 1;

	for (int j = p; j <= (r - 1); j++) {
		if (Array[j] <= x) {
			i = i + 1;
			swap(Array[i], Array[j]);
		}
	}
	swap(Array[i+1], Array[r]);
	return (i + 1);
}
