/*
Author: Ediel Lopez
Course: CSE 100 - Algorithm Design and Analysis
Term: 	Fall 2019
Assignment: Implementation of the Heap-Sort Algorithm
*/

#include <iostream>
#include <cmath>	// floor()
using namespace std;

// Function Prototype
void heapSort(int array[], int length);
void buildMaxHeap(int array[], int heapSize);
void maxHeapify(int array[], int heapSize, int i);

int main() {
	int size = 0;

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

	heapSort(myList, size);

	// Sorted Sequence
	for (int index = 0; index < size; index++) {
		cout << myList[index] << ";";
	}

	delete[] myList;	// Release the memory allocated
	return 0;
}

// Function Definition
void heapSort(int array[], int length) {
	// BUILD-MAX-HEAP goes through the remaining nodes and runs MAX-HEAPIFY on each one.
	buildMaxHeap(array, length);

	for (int index = length-1; index >= 0; index--) {
		// Exchange A[1] with A[index]
		swap(array[0],array[index]);

		maxHeapify(array, index, 0);
	}
}

void buildMaxHeap(int array[], int heapSize) {
	for (int marker = floor(heapSize/2); marker >= 0; marker--) {
		maxHeapify(array, heapSize, marker);
	}
}

void maxHeapify(int array[], int heapSize, int i) {
	int left = 2*i;
	int right = 2*i + 1;

	int largest;

	if ((left < heapSize) && (array[left] > array[i]))
		largest = left;
	else
		largest = i;


	if ((right < heapSize) && (array[right] > array[largest]))
		largest = right;

	if (largest != i) {
		swap(array[i], array[largest]);
		maxHeapify(array, heapSize, largest);
	}
}

