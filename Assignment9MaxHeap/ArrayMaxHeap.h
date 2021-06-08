//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 Listing 17-2.
 @file ArrayMaxHeap.h */ 
 
#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_

#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
   static const int ROOT_INDEX = 0;        // Helps with readability
   static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
   ItemType *items;                        // Array of heap items
   int itemCount;                          // Current count of heap items
   int maxItems;                           // Maximum capacity of the heap
   
   // ---------------------------------------------------------------------
   // Most of the private utility methods use an array index as a parameter
   // and in calculations. This should be safe, even though the array is an
   // implementation detail, since the methods are private.
   // ---------------------------------------------------------------------
   
   // Returns the array index of the left child (if it exists).
   int getLeftChildIndex(const int nodeIndex) const;
   
   // Returns the array index of the right child (if it exists).
   int getRightChildIndex(int nodeIndex) const;
   
   // Returns the array index of the parent node.
   int getParentIndex(int nodeIndex) const;
   
   // Tests whether this node is a leaf.
   bool isLeaf(int nodeIndex) const;
   
   // Converts a semiheap to a heap.
   void heapRebuild(int subTreeRootIndex);
   
   // Creates a heap from an unordered array.
   void heapCreate();
     
public:
   ArrayMaxHeap();
   ArrayMaxHeap(const ItemType someArray[], const int arraySize);
   virtual ~ArrayMaxHeap();
   
   // HeapInterface Public Methods:
   bool isEmpty() const;
   int getNumberOfNodes() const;
   int getHeight() const;
   ItemType peekTop() const throw(PrecondViolatedExcep);
   bool add(const ItemType& newData);
   bool remove();
   void clear();
}; // end ArrayMaxHeap

/** Array-based implementation of the ADT heap.
 @file ArrayMaxHeap.cpp */ 
 
#include <cmath> // for log2
#include <iostream>
#include <algorithm>  // for swap
#include "PrecondViolatedExcep.h"

//******************************************************************
// 
// Private methods start here
//
//******************************************************************

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

// Add implementation for getRightChildIndex
// See page 519 in the Carrano textbook
template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 2;
}

// Add implementation for getParentIndex
//See page 519 in the Carrano textbook
template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
   return (nodeIndex-1) / 2;
}

// Add implementation for isLeaf
// Hint: In a complete binary tree, if a node has one child, it must be the left child
//       If the index where the left child should be is larger than the index of the
//       last node in the complete binary tree (itemCount - 1), the node has no children (is a leaf).
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
   return getLeftChildIndex(nodeIndex) > (itemCount-1);
}

// Add implementation for heapRebuild
// See page 521 in the Carrano textbook
// Notes: 1. The pseudocode shows 3 paraemters. This method should only have one parameter - 
//           the index of the root node of a subtree of the heap. The other 2 parameters 
//           shown in the pseudocode are data members of the heap object - the items array 
//           and itemCount.
//        2. There is a typographical error in line 10 of the pseudocoe. It should read:
//
//           leftChildIndex = 2 * nodeIndex + 1
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
   if (!isLeaf(subTreeRootIndex)){
      int leftChildIndex = 2 * subTreeRootIndex + 1;

      if (getRightChildIndex(subTreeRootIndex) < itemCount) {
         int rightChildIndex = leftChildIndex + 1;
         if (items[rightChildIndex] > items[leftChildIndex]){
            leftChildIndex = rightChildIndex;
         }
      }

      if (items[subTreeRootIndex] < items[leftChildIndex]){
         std::swap(items[subTreeRootIndex],items[leftChildIndex]);
         heapRebuild(leftChildIndex);
      }
   }
}

// Add implementation for heapCreate
// See page 527 in the Carrano textbook
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
   for (int index = itemCount / 2; index >= 0; index--){
      heapRebuild(index);
   }
}


//******************************************************************
// 
// Public methods start here
//
//******************************************************************

// Add implementation for the default constructor.
// Hint: Your code needs to:
//       1. Initialize itemCount to zzero (no nodes in heap)
//       2. Initialize maxItems to DEFAULT_CAPACITY
//       3. Dynamically allocate an array of DEFAULT_CAPACITY itmes
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
   items = new ItemType[DEFAULT_CAPACITY];
}


template<class ItemType>
ArrayMaxHeap<ItemType>::
ArrayMaxHeap(const ItemType someArray[], const int arraySize):
             itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = new ItemType[2 * arraySize];

   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{  
   delete [] items;
}  // end destructor

// Add implememtation for isEmpty
// Hint: An empty heap contains 0 items (nodes)
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
   return (itemCount == 0);
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

// Add implementation for genNumberOfNodes method
// Hint: the number of nodes is stored in a data member
template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
   return itemCount;
} 

// Add implementation for clear
// Hint: This method just sets the number of nodes to zero.
template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
   itemCount = 0;
} 

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

// Add implementation for add method
// See page 523 in the Carrano textbook.
// Note: 1. There is an error in the pseudocode in the textbook. Before adding the new item to the heap,
//          you must check that there is room for it in the array.
//          If not, the operation fails (method should return false).    
template<class ItemType>
bool ArrayMaxHeap<ItemType>:: add(const ItemType& newData)
{  
   if (itemCount != DEFAULT_CAPACITY) {
      items[itemCount] = newData;
      int newDataIndex = itemCount;
      bool inPlace = false;
      int parentIndex;
      while ((newDataIndex >= 0) && !inPlace){
         
         parentIndex = (newDataIndex-1) / 2;
         if (items[newDataIndex] <= items[parentIndex]){
            inPlace = true;
         }else{
            std::swap(items[newDataIndex],items[parentIndex]);
            newDataIndex = parentIndex;
         }
      }
      itemCount++;
   }else{
      return false;
   }
}

// Add implementation for remove method
// See page 522 in the Carrano textbook.
// Hint: The textbook includes  most of the pseudocode for this method. But you cannot remove an item
//       from an empty heap. If the remove is successful, you must return true. Otherwise, return false.
template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{ 
   if (!isEmpty()){
      items[0] = items[itemCount-1];
      itemCount--;
      heapRebuild(0);
      return true;
   }else{
      return false;
   }
}

#endif
