/*
Author: Ediel Lopez
Date: 9/14/2019
Term: Fall 2019
About: Implementation of Merge Sort in C++.
*/

#include <iostream>
#include <vector>
#include <cmath>	// floor()
#include <climits>	// INT_MIN, INT_MAX
using namespace std;

// Function Prototype
void merge_sort(vector<int> &vals, int p, int r);
void merge(vector<int> &vals, int p, int q, int r);

int main() {
	// Variables
	int size = 0, value = 0;
	vector<int> values;

	// User will input how many values will be sorted.
	cin >> size;

	// Populate the vector with values.
	for (int index = 0; index < size; index++) {
		cin >> value;
		values.push_back(value);
	}

	// Pass the vector by reference to the Merge Sort Algorithm.
	merge_sort(values, 0, values.size() - 1);


	// Displaying the result.
	for (auto number : values) {
		cout << number << ";";
	}
	// cout << endl;

	return 0;
}

void merge_sort(vector<int> &vals, int p, int r) {
	// Executes so as long as the array isn't of size one.
	if (p < r) {
		// This is the midpoint. Determines where to split the vector.
		int q = floor((p + r) / 2);

		merge_sort(vals, p, q);		// All values to the left of the midpoint.
		merge_sort(vals, q + 1, r); 	// All values to the right of the midpoint.

		merge(vals, p, q, r);		// Merge them.
	}
}

void merge(vector<int> &vals, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];


	// Copy the first half of the values into the new L array
	for (int index = 0; index < n1; index++) {
		L[index] = vals.at(p + index);
	}

	// Copy the second half of the values into the new R array
	for (int index = 0; index < n2; index++) {
		R[index] = vals.at(q + index + 1);
	}

	// Sentinel values
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0, j = 0;

	// Sort the elements in non-decreasing order.
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			vals[k] = L[i];
			i++;
		}
		else {
			vals[k] = R[j];
			j++;
		}
	}

	// Release the dynamically allocated memory.
	delete[] L;
	delete[] R;
}
