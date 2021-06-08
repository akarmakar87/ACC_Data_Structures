
/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 3
// Project Desc: Recursion & Set ADT
// Course: COSC 2436 PF III Data Structures
// Date: 02/13/2021

#include <iostream>
#include <string>
#include "ArraySet.h"
using namespace std;

void display(ArraySet<string>& set)
{
	cout << "The set contains " << set.getCurrentSize()
        << " items:" << endl;
   vector<string> setItems = set.toVector();
   
   int numberOfEntries = static_cast<int>(setItems.size());
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << setItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
  string load_in[] = {"red", "blue", "yellow"};
  ArraySet<string> load_set(load_in,3);
  cout << "Testing array-based Set (second constructor):" << endl;
	cout << "This set is initalized by passing in the load_in array." << endl;
  cout << "isEmpty: returns " << load_set.isEmpty() << "; should be 0 (false)" << endl;
  display(load_set);

  
	ArraySet<string> set;
	cout << "Testing array-based Set (default constructor):" << endl;
	cout << "The initial set is empty." << endl;
	cout << "isEmpty: returns " << set.isEmpty() 
        << "; should be 1 (true)" << endl;
	display(set);

	string items[] = {"one", "two", "three", "four", "one"};
	cout << "Add 5 items to the set (one repeat): " << endl;
	for (int i = 0; i < 5; i++)
	{
		set.add(items[i]);
	}  // end for
   
   display(set);
   
   cout << "isEmpty: returns " << set.isEmpty() 
        << "; should be 0 (false)" << endl;
	
   cout << "getCurrentSize: returns " << set.getCurrentSize() 
        << "; should be 4" << endl;    
   
   cout << "contains(\"three\"): returns " << set.contains("three")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"two\"): returns " << set.remove("two")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"two\"): returns " << set.remove("two")
        << "; should be 0 (false)" << endl;
   cout << endl;
   
   display(set);
   
   cout << "After clearing the set, ";
   set.clear();
   
   cout << "isEmpty: returns " << set.isEmpty()
        << "; should be 1 (true)" << endl;
   
   return 0;
}  // end main