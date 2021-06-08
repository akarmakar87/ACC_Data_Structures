/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 4 
// Project Desc: LinkedBag
// Course: COSC 2436 PF III Data Structures
// Date: 2/19/21

#include <iostream>
#include <string>
#include "LinkedBag.h"
using namespace std;

void display(LinkedBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<string> bagItems = bag.toVector();
   
   int numberOfEntries = static_cast<int>(bagItems.size());
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	LinkedBag<string> bag;
	cout << "Testing array-based Set:" << endl;
	cout << "The initial bag is empty." << endl;
	cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" << endl;
	display(bag);

  // NOTE: Adds items to bag using modified add method
	string items[] = {"one", "two", "three", "four", "five"};
	cout << "Add 5 items to the end of the bag: " << endl;
	for (int i = 0; i < 5; i++)
	{
		bag.add(items[i]);
	}  // end for
   
   display(bag);
   
   cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 0 (false)" << endl;
	
   cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 5" << endl;    
   
   cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"two\"): returns " << bag.remove("two")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"two\"): returns " << bag.remove("two")
        << "; should be 0 (false)" << endl;
   cout << endl;
   
   display(bag);

   // NOTE: Demonstrates functionality of new remove method that removes a random entry from the bag
   cout << "remove random entry: returns " << bag.remove()
        << "; should be 1 (true)" << endl;
   cout << endl;
   
   display(bag);
   
   cout << "After clearing the bag, ";
   bag.clear();
   
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << endl;
   
   return 0;
}  // end main
