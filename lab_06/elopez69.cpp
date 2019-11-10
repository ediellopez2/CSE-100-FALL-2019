/*
Author: Ediel Lopez
Course: CSE 100 - Algorithm Design and Analysis
Term: 	Fall 2019
Assignment: Implementation of RadixSort.
*/
#include <iostream>
#include <vector>
using namespace std;

const int K = 10;			// Each vector has 10 elements.

// Function Prototypes
void radixSort(vector<int>*, int);
void countingSort(vector<int>*, int, int);

int main() {
    int n = 0, value = 0;
	cin >> n;

	// 'n' dynamically allocated int vectors pointed to by a vector pointer.
	vector<int>* vectorPtr = new vector<int>[n];

	// Read the sequence of numbers
	for (int index = 0; index < n; index++) {
		for (int counter = 0; counter < K; counter++) {
			cin >> value;
			vectorPtr[index].push_back(value);

			value = 0;
		}
	}

	radixSort(vectorPtr, n);

	// Display the sorted vectors
	for (int index = 0; index < n; index++) {
		for (int counter = 0; counter < K; counter++) {
			cout << vectorPtr[index].at(counter) << ";";
		}
		cout << endl;
	}


	delete[] vectorPtr;
    return 0;
}

//                  FUNCTION DEFINITIONS

// ===================================================
// Implementation of Radix Sort. The function works
// by calling Counting Sort with each indice location.
// Sort the vectors based on the last (9th) indice,
// then the 8th indice, then the 7th indice until all
// the vectors are sorted in ascending order.
// ===================================================
void radixSort(vector<int>* ptr, int len) {
	for (int index = K - 1; index >= 0; index--) {
		countingSort(ptr, len, index);
	}
}

// ===================================================
// Implementation of Counting Sort. The function works
// by taking the ptr to the array of dynamically alloc.
// vectors each of which hold 10 ints, the number of 
// vectors that there is to sort, and the current indice
// which we will use to sort the vectors.
// ===================================================
void countingSort(vector<int>* ptr, int numOfVectors, int indice) {

	int rangeOfValues[4] = { 0 };			// Initialize all the values in the array to zero
	vector<int>* resultPtr = new vector<int>[numOfVectors];


	for (int index = 0; index < numOfVectors; index++) {
		rangeOfValues[ptr[index][indice] % 4] += 1;
	}

	for (int i = 1; i < 4; i++) {
		rangeOfValues[i] = rangeOfValues[i] + rangeOfValues[i - 1];
	}

	for (int j = numOfVectors - 1; j >= 0; j--) {
		resultPtr[rangeOfValues[ptr[j][indice] % 4] - 1] = ptr[j];
		rangeOfValues[ptr[j][indice] % 4] -= 1;
	}


	for (int i = 0; i < numOfVectors; i++)
		ptr[i] = resultPtr[i];


	if (indice == 9)
		delete[] resultPtr;
}
