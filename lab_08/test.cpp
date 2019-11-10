
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int>::iterator it; 
    for(it = g.begin(); it != g.end(); it++) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

int main() {
    list<int> listOne;
    list<int> listTwo;

    for (int index = 1; index <= 10; index++) {
        listOne.push_back(index);
        listTwo.push_front(index);
    }

    // Printing listOne
    cout << "List One: " << endl;
    showlist(listOne);

    // Printing listTwo
    cout << "List Two: " << endl;
    showlist(listTwo);


    // remove an element
    cout << "Removing 3 from List One ... " << endl;
    listOne.remove(3);
    showlist(listOne);

    // pop_front()
    cout << "Removing an element from the front of List One ... " << endl;
    listOne.pop_front();
    showlist(listOne);

    // pop_back()
    cout << "Removing an element from the back of List One ... " << endl;
    listOne.pop_back();
    showlist(listOne);


    while (!listOne.empty()) {
	    cout << listOne.front() << endl;
        listOne.pop_front();
	}

    return 0;
}