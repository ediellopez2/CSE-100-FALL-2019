/*
Author: Ediel Lopez
Course: CSE 100 - Algorithm Design and Analysis
Term: Fall 2019
Date: 9/23/2019
About: Solving the Max Subarray Problem via Divide-and-Conquer.
Sources: https://stackoverflow.com/questions/321068/returning-multiple-values-from-a-c-function
*/
#include<iostream>
#include<vector>
#include<cmath>			// floor()
#include<climits>		// INT_MIN, INT_MAX
#include<tuple>			// tie(). To be able to return multiple arguments from a function.
using namespace std;

// Function Prototypes
tuple<int, int, int> find_max_crossing_subarray(int values[], int low, int mid, int high);
tuple<int, int, int> find_maximum_subarray(int values[], int low, int high);

int main() {
	// Variables
	int size = 0;
	int value = 0;
	int a = 0, b = 0, c = 0;	// The values returned by the max subarray function.

	// User determines how many values we will be working with.
	cin >> size;

	// Dynamic Array
	int* values = new int[size];

	// Populate the array with values.
	for (int index = 0; index < size; index++) {
		cin >> values[index];
	}

	// Display the values in the vector. (Uses a range-based for-loop)
	/*for (int x : values) {
		cout << x << endl;
	}*/

	tie(a, b, c) = find_maximum_subarray(values, 0, size - 1);

	cout << c; // Displays the largest sum in the array.

	delete[] values;
	return 0;
}

tuple<int, int, int> find_maximum_subarray(int values[], int low, int high) {
	if (low == high) {
		return make_tuple(low, high, values[low]);
	}
	else {
		int mid = floor((low + high) / 2);
		int left_low = 0, left_high = 0, left_sum = 0, right_low = 0, right_high = 0, right_sum = 0,
			cross_low = 0, cross_high = 0, cross_sum = 0;
		/*cout << "First half: ";
		for (int index = 0; index < mid; index++) {
			cout << values[index] << " ";
		}

		cout << "Second half: ";
		for (int index = mid; index < high; index++) {
			cout << values[index] << " ";
		}*/

		tie(left_low, left_high, left_sum) = find_maximum_subarray(values, low, mid);

		tie(right_low, right_high, right_sum) = find_maximum_subarray(values, mid + 1, high);

		tie(cross_low, cross_high, cross_sum) = find_max_crossing_subarray(values, low, mid, high);

		if ((left_sum >= right_sum) && (left_sum >= cross_sum)) {
			return make_tuple(left_low, left_high, left_sum);
		}	
		else if ((right_sum >= left_sum) && (right_sum >= cross_sum)) {
			return make_tuple(right_low, right_high, right_sum);
		}	
		else {
			return make_tuple(cross_low, cross_high, cross_sum);
		}
	}
}

tuple<int, int, int> find_max_crossing_subarray(int values[], int low, int mid, int high) {
	int left_sum = INT_MIN, right_sum = INT_MIN;
	int max_left = 0, max_right = 0;
	int sum = 0;

	for (int i = mid; i >= low; i--) {
		sum = sum + values[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum = sum + values[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}

	return make_tuple(max_left, max_right, left_sum + right_sum);
}
