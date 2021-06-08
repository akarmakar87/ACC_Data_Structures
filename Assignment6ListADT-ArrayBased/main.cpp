/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 6
// Project Desc: List ADT - Array Based Implementation
// Course: COSC 2436 PF III Data Structures
// Date: 04/01/2021

#include "ArrayList.h" // ADT list operations
#include <iostream>
#include <string>
using namespace std;

void displayList(ListInterface<std::string>* listPtr)
{
   std::cout << "The list contains " << std::endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      try
      {
         std::cout << listPtr->getEntry(pos) << " ";
      }
      catch(PrecondViolatedExcep except)
      {
         std::cout << "Exception thrown getting entry inserted at position " << pos << std::endl;
         std::cout << except.what() << std::endl;
      }
    } // end for
	std::cout << std::endl;
}  // end displayList

int main()
{
   ListInterface<std::string>* listPtr = new ArrayList<std::string>();
   cout << "Testing the Array-Based List:" << endl;
	//listTester(listPtr);   
   string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   for (int i = 0; i < 6; i++)
   {
      if (listPtr->insert(i + 1, data[i]))
      {
         try
         {
           cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) << endl;
         } 
		 catch (PrecondViolatedExcep except)
         {
            cout << "Exception thrown getting entry inserted at list end!" << endl;
            cout << except.what() << endl;
         }
      }
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
   }  // end for
   
   displayList(listPtr);
   
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 5" << endl;
   
   try
   {
      cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << std::endl;
   }
   catch (PrecondViolatedExcep except)
   {
      cout << "Exception thrown getting entry at position 4!" << endl;
      cout << except.what() << endl;
   }

   cout << "list contains 'three': " << listPtr->contains("three")<< "; should be 1 (true)" << endl;

   try
   {
      listPtr->replace(3,"XXX");
      cout << "After replacing the entry at position 3 with XXX: The list contains" << endl;
   }
   catch (PrecondViolatedExcep except)
   {
      cout << "Exception replacing the entry at position 3 with XXX!" << endl;
      cout << except.what() << endl;
   }

   displayList(listPtr);

   cout << "list contains 'three': " << listPtr->contains("three")<< "; should be 0 (false)" << endl;

   cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" << endl;
   cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" << endl;
   cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" << endl;
   displayList(listPtr);
   
   cout << "clear: " << endl;
   listPtr->clear();
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   
   try
   {
      cout << "Attempt an illegal retrieval from position 6: " << endl;
      listPtr->getEntry(6);
   }
   catch(PrecondViolatedExcep e)
   {
      cout << e.what() << endl;
   }  // end try/catch

   return 0;
}  // end main