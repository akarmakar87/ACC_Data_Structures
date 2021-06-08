//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 11-5.
#include <iostream>
using namespace std;

const int MIN_SIZE = 4;

// Arranges the first, middle, and last entries in an array into ascending order
template <class ItemType>
void sortLastMiddleFirst(ItemType theArray[], int first, int mid, int last)
{
  if (theArray[first] > theArray[mid])
    swap(theArray[first], theArray[mid]); 
  if (theArray[mid] > theArray[last])
    swap(theArray[mid], theArray[last]);
  if (theArray[first] > theArray[mid])
    swap(theArray[first], theArray[mid]);
}

template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
  int mid = first + (last - first) / 2;
  sortLastMiddleFirst(theArray, first, mid, last);
  swap(theArray[mid],theArray[last-1]);
  int pivotIndex = last - 1;
  ItemType pivot = theArray[pivotIndex];

  // Determine the regions S 1 and S 2
  int indexFromLeft = first + 1;
  int indexFromRight = last - 2;
  bool done = false;

  while (!done){
  // Locate first entry on left that is ≥ pivot
    while (theArray[indexFromLeft] < pivot){
      indexFromLeft = indexFromLeft + 1;
    }
  // Locate first entry on right that is ≤ pivot
    while (theArray[indexFromRight] > pivot){
      indexFromRight = indexFromRight - 1;
    }

    if (indexFromLeft < indexFromRight)
    {
      swap(theArray[indexFromLeft],theArray[indexFromRight]);
      indexFromLeft = indexFromLeft + 1;
      indexFromRight = indexFromRight - 1;
    }
    else{
      done = true;
    }
  }
  // Place pivot in proper position between S 1 and S 2 , and mark its new location
  swap(theArray[pivotIndex], theArray[indexFromLeft]);
  pivotIndex = indexFromLeft;
  return pivotIndex;
}

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{

   if ((last - first + 1) < MIN_SIZE) {
      cout << "Calling insertionSort with size = " << last-first+1 << endl;
      insertionSort(theArray, first, last);
   } else {
      // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, first, last);
    
      // Sort subarrays S1 and S2
      cout << "Calling quickSort with left size = " << pivotIndex-first << " and right size = " << last-pivotIndex << endl;
      quickSort(theArray, first, pivotIndex - 1);
      quickSort(theArray, pivotIndex + 1, last);
   }  // end if
}  // end quickSort


