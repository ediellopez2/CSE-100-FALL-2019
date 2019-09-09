/*
Author: Ediel Lopez
Date:   9/7/2019
Course: CSE 100 - Algorithm Design and Analysis
Term:   Fall 2019
About:  Find the minimum and maximum integer values in an array of length n.
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {

	int size = 0;
	vector<int> values;

	cin >> size; 		// The vector will contain this many elements.

	// Populate the vector with values.
	int val = 0;
	for(int index = 0; index < size; index++) {
		cin >> val;
		values.push_back(val);
	}


	//  Display the contents of the vector.
	/*
	cout << "\nHere are the contents of the vector!\n" << endl;
	for(int index = 0; index < size; index++) {
		cout << values.at(index) << endl;
	}
	cout << "\n\n" << endl;
	*/


	// Let's find the min and max values.
	if (values.size() > 1) {

		int min = values.at(0), max = values.at(0), temp = 0;

		for (int index = 1; index < values.size(); index++) {
			if (values.at(index) > max) {
				max = values.at(index);
			}
			if (values.at(index) < min) {
				min = values.at(index);
			}
		}
		cout << max << ";" << min << endl;
	}
	else if (values.size() == 1) {
		cout << values.at(0) << ";" << values.at(0) << endl;
	}
	else {
		cout << "Error! There exists no min or max." << endl;
	}


	return 0;
}
