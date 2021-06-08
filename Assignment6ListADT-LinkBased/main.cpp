/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 6
// Project Desc: List ADT - Link Based Implementation
// Course: COSC 2436 PF III Data Structures
// Date: 04/01/2021

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
using namespace std;

void displayList(ListInterface<std::string>* listPtr)
{
	if (listPtr->isEmpty())
		cout << "The list is empty" << endl;
	else
	{
		cout << "The list contains " << endl;
		for (int pos = 1; pos <= listPtr->getLength(); pos++)
		{
			cout << listPtr->getEntry(pos) << " ";
   		}
		cout << endl;
	}
}

int main()
{

	ListInterface<std::string>* listPtr = new LinkedList<std::string>();
	
	cout << "List should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	
	listPtr->insert(1, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;	
	
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;		
	
	listPtr->insert(3, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;	
	
	listPtr->insert(3, "two.five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;	
	
	listPtr->insert(5, "five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	cout << "Remove first entry" << endl;
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	
	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;
	
	cout << "Remove remaining entries" << endl;
	listPtr->remove(1);
	listPtr->remove(1);
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
         cout << "Removed an entry" << endl << endl;
    else
         cout << "Cannot remove entry" << endl << endl;
	
	// test clear
	cout << "Testing clear method" << endl;
	cout << "Inserting one" << endl;
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;		
	
	cout << "Inserting two" << endl;
	listPtr->insert(2, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;

	//// NEW STUFF
	cout << "Replacing second entry: " << listPtr->replace(2,"x") << endl;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;

	cout << "Contains x: " << listPtr->contains("x") << "; should be 1 (true)" << endl;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;
	
	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;	

	// Create a LinkedList object
    LinkedList<std::string>* myListPtr = new LinkedList<std::string>();
	
    // Include code here to add some entries myList
    myListPtr->insert(1, "c");
	myListPtr->insert(1, "b");
	myListPtr->insert(1, "a");

    // Include code to display the entries in myList
	cout << "Original list contents" << endl;
	displayList(myListPtr);
	cout << "Length : " << myListPtr->getLength() << "; should be 3" << endl << endl;	

    // Create a new list that is a copy
    LinkedList<std::string>* copiedListPtr = new LinkedList<std::string>(*myListPtr);

    // Include code here to print entries in copiedList - should be the same a those in myList
	cout << "Copied list contents" << endl;
	displayList(copiedListPtr);
	cout << "Length : " << copiedListPtr->getLength() << "; should be 3" << endl << endl;
	
    // Include code here to make some changes in copiedList. Then print out

	cout << "Insert an entry into copied list: " << endl;
	copiedListPtr->insert(1,"d");
	
   // contents of each list. myList should have the old entries and copiedList should show the updates

	cout << "Copied list contents" << endl;
	displayList(copiedListPtr);
	cout << "Length : " << copiedListPtr->getLength() << "; should be 4" << endl << endl;
	cout << "Original list contents" << endl;
	displayList(myListPtr);
	cout << "Length : " << myListPtr->getLength() << "; should be 3" << endl << endl;

	return 0;
}  // end main