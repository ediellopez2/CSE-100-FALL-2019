/*
Author: Ediel Lopez
Course: CSE 100
Term: Fall 2019
About: Implementation of the Huffman Code Algorithm
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct Node {
	char letter;
	int frequency;
	Node* left;				// Pointer to left child node
	Node* right;			// Pointer to right child node

	// Default Constructor
	Node() {
		this->letter = '\0';
		this->frequency = 0;
		left = nullptr;
		right = nullptr;
	}
	// Overloading Constructor
	Node(char let, int freq) {
		this->letter = let;
		this->frequency = freq;
		left = nullptr;
		right = nullptr;
	}
};

struct compare {
	bool operator()(const Node* left, const Node* right) {
		return (left->frequency > right->frequency);
	}
};


typedef priority_queue<Node *, vector<Node *>, compare> minPriorityQueue;
// =========================== Function Prototypes ======================================
void huffmanAlgorithm(char dictionary[], int frequency[], int SIZE);
void printStructure(Node* ptr, string str, char dictionary[], int num);

//minPriorityQueue& minPriorityQueue::operator=(const minPriorityQueue &rhs) {
//	if (this == &rhs) {		// same object?
//		return *this;		// skip assignment, and just return *this.
//	}
//	minPriorityQueue prQueue;
//	if (size != rhs.size) {
//		// cout << "we got diiferent size yo!" << endl
//		Node* arga = nullptr;
//		Node* newnode = nullptr;
//
//		do {
//			arga = rhs.top();		// get the smallest value
//			rhs.pop();
//
//			newnode = new Node(arga->letter,arga->frequency);	// creata a new node
//			newnode->left = arga->left;
//			newnode->right = arga->right;
//			prQueue.push(newnode);
//
//		} while (prQueue.size() != 1);	// !pq.empty()
//	}
//	return *this;
//}



int main() {
	const int SIZE = 6;
	char dictionary[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int frequency[SIZE] = { 0 };

	// Range-Based for Loop to get the frequencies of each character
	// ================================================================
	for (int &index : frequency) {
		cin >> index;
	}
	// ================================================================

	huffmanAlgorithm(dictionary, frequency, SIZE);

	// system("pause");
	return 0;
}


// Function Definitions
void huffmanAlgorithm(char dictionary[], int frequency[], int SIZE) {
	// Create a Minimum Priority Queue. 
	// Arguments include: A. data type, B. a vector of dynamically created structs, C. the comparator 
	// priority_queue<Node *, vector<Node *>, compare> pq;
	minPriorityQueue pq;

	int index = 0;
	while (index < SIZE)
	{	// Add a Node to the vector
		pq.push(new Node(dictionary[index], frequency[index]));
		index++;
	}
	
	Node* argA = nullptr;
	Node* argB = nullptr;
	Node* newNode = nullptr;

	do {
		//cout << "\t\tSIZE:" << pq.size() << endl;

		argA = pq.top();		// Get the smallest value
		pq.pop();
		//cout << argA->frequency << endl;

		argB = pq.top();		// Get the next smallest value
		pq.pop();
		//cout << argB->frequency << endl;

		// cout << "\t\tAdding a new node ..." << argA->frequency + argB->frequency << endl;
		newNode = new Node('\0', (argA->frequency + argB->frequency));	// Creata a new Node
		newNode->left = argA;
		newNode->right = argB;
		pq.push(newNode);

	} while (pq.size() != 1);	// !pq.empty()

	// return minPriorityQueue();

	string s = ":";
	for (int index = 0; index < SIZE; index++) {
		printStructure(pq.top(), s, dictionary, index);
	}
}

void printStructure(Node* ptr, string s, char dictionary[], int num) {
	// If there is not node, return
	if (!ptr) { return; }

	// Print the letter
	if (ptr->letter == dictionary[num]) {
		cout << ptr->letter << s << endl;
	}
	// Traverse the structure, printing a 0 or 1
	printStructure(ptr->left, s + "0", dictionary, num);
	printStructure(ptr->right, s + "1", dictionary, num);
}
