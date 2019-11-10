/*
Author: Ediel Lopez
Course: CSE 100
Term: Fall 2019
About: Implementation of a Binary Search Tree
*/
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class binaryTree {
private:
	struct Node {
		int value;
		Node* left;		// Pointer to left child node
		Node* right;	// Pointer to right child node
	};

	Node* root;			// Pointer to the root node

	// Private member functions
	void insert(Node *&, Node *&);
	// void destroySubTree(Node *);
	void deleteNode(int, Node *&);


	// Display Member Functions
	void displayInOrder(Node *) const;
	void displayPreOrder(Node *) const;
	void displayPostOrder(Node *) const;
public:
	// Constructor
	binaryTree() { root = nullptr; }

	// Destructor 
	/*~binaryTree() {	destroySubTree(root);	}*/

	// Binary Tree Operations
	void insertNode(int);
	void remove(int);

	void displayInOrder() const
	{
		displayInOrder(root);
	}

	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
} tree;								// An instance of the binaryTree class

void binaryTree::insertNode(int val) {
	Node* newNode = nullptr;		// Pointer to a new node

	// Create a new node an store the letter and frequency in it.
	newNode = new Node;
	newNode->value = val;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

/*	=======================================================================
This function takes a pointer to a subtree and a pointer to a new node
as arguments. It searches the appropriate location in the subtree to insert
the node, and then makes the instertion.
	=======================================================================  */
void binaryTree::insert(Node *&nodePtr, Node *&newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode;						// Insert the Node
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);			// Search the left branch
	else
		insert(nodePtr->right, newNode);		// Search the right branch
}

// Remove the given value using the public function, which 
// then calls the private functions.
void binaryTree::remove(int num) {
	deleteNode(num, root);		// Passes the node to delete and the root node.
}


// deleteNode essentially finds the node that is to be deleted. 
// If it is found, then the makeDeletion function is called.
void binaryTree::deleteNode(int num, Node *&ptrToNode) {
	if (num < ptrToNode->value) {		// The num will be on the left subtree
		deleteNode(num, ptrToNode->left);
	}
	else if (num > ptrToNode->value) {	// The num will be on the right subtree
	deleteNode(num, ptrToNode->right);
	}
	else if (ptrToNode == nullptr) {	// Value is not in the binary tree, return.
	return;
	}
	else {
	// The said node will be deleted here. The process works by creating a temporary Node, 
	// and using it to connect the nodes back together after deleting the said node.
	Node* temp = nullptr;

	if (ptrToNode->right == nullptr) {
		temp = ptrToNode;		// Have temp point to whatever ptrToNode is pointing to
		ptrToNode = ptrToNode->left;
		delete temp;
	}
	else if (ptrToNode->left == nullptr) {
		temp = ptrToNode;
		ptrToNode = ptrToNode->right;
		delete temp;
	}
	else {	// The node that is to be deleted has two nodes
		temp = ptrToNode->right;

		while (temp->left) {
			temp = temp->left;
		}

		temp->left = ptrToNode->left;

		temp = ptrToNode;

		ptrToNode = ptrToNode->right;
		delete temp;
	}
	}
}


// =======================================================================
// ====================  TRAVERSAL FUNCTIONS =============================
// =======================================================================
//	==============================================================
//	The displayInOrder member function displays the values in the 
//	subtree pointed to by nodePtr, via inorder traversal.
//	A. Left Subtree
//  B. Node's Data
//  C. Right Subtree
//	==============================================================
void binaryTree::displayInOrder(Node* nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//	==============================================================
//	The displayInOrder member function displays the values in the 
//	subtree pointed to by nodePtr, via preorder traversal.
//	A. Node's Data
//  B. Left Subtree
//  C. Right Subtree
//	==============================================================
void binaryTree::displayPreOrder(Node* nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//	==============================================================
//	The displayInOrder member function displays the values in the 
//	subtree pointed to by nodePtr, via postorder traversal.
//	A. Left Subtree
//  B. Right Subtree
//  C. Node's Data
//	==============================================================
void binaryTree::displayPostOrder(Node* nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}


int main() {
	string argument = "";

	while (cin >> argument) {
		if (argument == "e") {	// Terminate
			// system("pause");
			return 0;
		}
		if (argument == "opre" || argument == "opost" || argument == "oin") {	// Display
			if (argument == "opre") {	// PreOrder
				tree.displayPreOrder();
			}
			if (argument == "opost") {	// PostOrder
				tree.displayPostOrder();
			}
			if (argument == "oin") {	// InOrder
				tree.displayInOrder();
			}
		}
		else if (!argument.empty()){		// Delete or Insert
			if(argument.front() == 'i') {	// insert
				argument = argument.erase(0, 1);
				int value = stoi(argument);
				tree.insertNode(value);
			}
			if (argument.front() == 'd') {	// delete
				argument = argument.erase(0, 1);
				int value = stoi(argument);
				tree.remove(value);
			}

		}
	}
}

