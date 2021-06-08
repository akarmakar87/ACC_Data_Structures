/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 
// Project Desc:
// Course: COSC 2436 PF III Data Structures
// Date: 

#include <iostream>
#include "insertionSort.h"
#include "quickSort.h"
using namespace std;

int main() {
  //In your driver before the call to quickSort, display the size (number of elements in) the array to be sorted. The size would be last - first + 1.
  //In quickSort before the call to insertionSort, display the size of (number of elements in) the portion of the array that remains to be sorted. The size would be last - first + 1.
  //In the quicksort function before the recursive calls to quickSort on the two parts of the array, display the size of the first (left) part of the array and the size of the last (right) part. Here are my notes on doing these calculations

  string letArray[26] = {"Z","I","H","A","V","X","T","E","R","G","P","K","N","M","L","O","J","Y","U","Q","F","S","D","C","B","W"};
  cout << "Sort list of 26 items:" << endl;
  for (int i = 0; i < 26; i++) 
    cout << letArray[i] << " ";
  cout << endl;
  quickSort(letArray, 0, 25);
  for (int i = 0; i < 26; i++) 
    cout << letArray[i] << " ";
  cout << endl << endl;

  int numArray[25] = {31,69,57,22,15,6,66,60,12,38,77,73,98,90,97,60,34,30,61,31,96,68,14,7,40};
  cout << "Sort list of 25 items:" << endl;
  for (int i = 0; i < 25; i++) 
    cout << numArray[i] << " ";
  cout << endl;
  quickSort(numArray, 0, 24);
  for (int i = 0; i < 25; i++) 
    cout << numArray[i] << " ";
  cout << endl;
}