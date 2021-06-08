// Programmer: Asha Karmakar
// Project Number: 9 
// Project Desc: MaxHeap
// Course: COSC 2436 PF III Data Structures
// Date: 5/12/21

#include <iostream>
#include <string>
#include "ArrayMaxHeap.h"
using namespace std;

int main()
{
   ArrayMaxHeap<int> *heap1Ptr = new ArrayMaxHeap<int>(); 
   
   heap1Ptr->add(50);
   heap1Ptr->add(10);
   heap1Ptr->add(40);
   heap1Ptr->add(30);
   heap1Ptr->add(60);
   heap1Ptr->add(20);
   
   cout << "Heap 1: " << endl;
   while (!heap1Ptr->isEmpty())
   {
      cout << "# of nodes: " << heap1Ptr->getNumberOfNodes() << endl;
      cout << "Height: "     << heap1Ptr->getHeight() << endl;
      cout << "max value: "  << heap1Ptr->peekTop() << endl;
      cout << "remove: "     << (heap1Ptr->remove()? "success": "failure\n") << endl << endl;
   }
   
   ArrayMaxHeap<string> *heap2Ptr = new ArrayMaxHeap<string>(); 
   heap2Ptr->add("Abby");
   heap2Ptr->add("Carl");
   heap2Ptr->add("Brad");
   heap2Ptr->add("Evan");
   heap2Ptr->add("James");
   heap2Ptr->add("Harry");
   
   cout << "Heap 2: " << endl;
   while (!heap2Ptr->isEmpty())
   {
      cout << "# of nodes: " << heap2Ptr->getNumberOfNodes() << endl;
      cout << "Height: "     << heap2Ptr->getHeight() << endl;
      cout << "max value: "  << heap2Ptr->peekTop() << endl;
      cout << "remove: "     << (heap2Ptr->remove()? "success": "failure\n") << endl << endl;
   }

   int sortArray[5] = {1,5,3,8,6};
   cout << "Original array: " << endl;
   for (int i = 0; i < 5; i++)
      cout << sortArray[i] << " ";
   ArrayMaxHeap<int> arrayHeap(sortArray, 5);
   int ind = 4;
   while (!arrayHeap.isEmpty()) {
      sortArray[ind] = arrayHeap.peekTop();
      arrayHeap.remove();
      ind--;
   }

   cout << endl << "Sorted array using maxheap: " << endl;
   for (int i = 0; i < 5; i++)
      cout << sortArray[i] << " ";

   return 0;
}  // end main

