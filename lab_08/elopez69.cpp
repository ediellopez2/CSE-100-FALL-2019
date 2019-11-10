/*
Author: Ediel Lopez
Course: CSE 100
Term: Fall 2019
About: Implementation of a Hash Table with Chaining
Sources used: 
http://www.cplusplus.com/reference/list/list/
https://www.geeksforgeeks.org/iterators-c-stl/
https://www.geeksforgeeks.org/list-size-function-in-c-stl/
https://www.geeksforgeeks.org/c-program-hashing-chaining/
https://www.geeksforgeeks.org/list-cpp-stl/
*/
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// ====== Hash Function =======
int hash_value(int value, int mod) {	return value % mod;	}

int main() {
	// ======================== Hash Table with Chaining ========================
	string argument = "";
	int buckets = 0;
	cin >> buckets;
		
	list<int> *ptr = new list<int>[buckets];

	while (cin >> argument) {
		if (argument == "e") {	// Terminate the program
			return 0;
		}
		
		if (argument == "o") {	// Display the Hash Table
			for (int marker = 0; marker < buckets; marker++) { 
				cout << marker << ":"; 
				for (auto x : ptr[marker]) 
					cout << x << "->"; 
				cout << ";" << endl; 
			}
		}
		else if (!argument.empty())	{		// Delete, Search, or Insert an element
			int value;
			if (argument.front() == 'i') {			// Insert
				argument = argument.erase(0, 1);	// removes the 'i'
				value = stoi(argument);

				ptr[hash_value(value, buckets)].push_front(value);	// inserts the value at the front		
			} 
			else if (argument.front() == 's') {	// Search 
				argument = argument.erase(0, 1);	// removes the 's'
				value = stoi(argument);	
				
				list<int>::iterator it; 
				int location = 0;
				bool flag = false;

				// use an iterator to traverse the list
    			for(it = ptr[hash_value(value, buckets)].begin(); it != ptr[hash_value(value, buckets)].end(); it++) {
					if (*it == value) {
						cout << value << ":FOUND_AT" << hash_value(value, buckets) << "," << location << ";" << endl;
						flag = true;		// success, value was found.
					}
					location++;
				}
				if (flag == false)		// value was not found in the list.
					cout << value << ":NOT_FOUND;" << endl;
			} 
			else if (argument.front() == 'd') {	// Delete
				argument = argument.erase(0, 1);	// removes the d
				value = stoi(argument);				// converts string to int

				list<int>::iterator it; 
				bool flag = false;
				bool marker = true;
				int loc = hash_value(value, buckets);

				list<int> temp;
				int extracted_value;

				// copy all but the value we want to delete into the list temp
				while (!ptr[loc].empty()) {
					extracted_value = ptr[loc].front();
					ptr[loc].pop_front();

					// in the event that we multiple instances of the value that we want to delete, only delete one copy.
					if ((extracted_value == value) && marker) {
						flag = true;
						marker = false;
					} else if (extracted_value != value) {
						temp.push_back(extracted_value);
					} else if (!marker) {
						temp.push_back(extracted_value);
					}
				}

				ptr[loc].clear();
				temp.reverse();

				// copy the values in temp back to ptr[loc]
				for(it = temp.begin(); it != temp.end(); it++) 
        			ptr[loc].push_front(*it);

				temp.clear();

				if (flag == false)		// value was not found in the list.
					cout << value << ":DELETE_FAILED;" << endl;
				else
					cout << value << ":DELETED;" << endl;
			}
		}
	}

	delete[] ptr;
	return 0;
}