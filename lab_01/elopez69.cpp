/*
Author: Ediel Lopez
Date:   9/8/2019
Course: CSE 100 - Algorithm Design and Analysis
Term:   Fall 2019
About:  Implementing Insertion Sort using C++..
*/

#include <iostream>
#include <vector>
using namespace std;


// Function Prototype
void insertionSort(vector<int> &);


int main() {
	// Variables
	int size = 0;
	vector<int> values;

	cin >> size;

	// Populate the vector with the values that we wish to sort.
	int val;
	for (int index = 0; index < size; index++) {
		cin >> val;
		values.push_back(val);
	}

	// Pass the vector by reference to the Insertion Sort Algorithm.
	insertionSort(values);

	/*
	for (int index = 0; index < size; index++) {
		cout << values.at(index) << endl;
	}
	*/

	return 0;
}


// Function Definition
void insertionSort(vector<int> &values) {
	int key, i;

	for (int index = 1; index < values.size(); index++) {

		key = values[index];
		i = index - 1;

		while (i >= 0 && values.at(i) > key) {
			values[i + 1] = values.at(i);
			i = i - 1;
		}
		values[i + 1] = key;


		int x = 0;
		while (x < index+1) {
			cout << values.at(x)<< ";";
			x++;
		}
		cout << endl;
	}
}
