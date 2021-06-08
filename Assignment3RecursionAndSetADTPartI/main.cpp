/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 3
// Project Desc: Recursion & Set ADT
// Course: COSC 2436 PF III Data Structures
// Date: 02/13/2021

#include <iostream>
using namespace std;

int maxArray(const int anArray[], int first, int last) {
  int mid = first + (last - first) / 2;
  if (last == first){
    return anArray[first];
  }else{
    int leftHalf = maxArray(anArray,first,mid);
    int rightHalf = maxArray(anArray,mid+1,last);
    return (leftHalf > rightHalf) ? leftHalf : rightHalf;
  }
}

int main() {
  int sampleArray[] = {1,1,1,2,3,1,1,19,6,2};
  int size = 10;

  cout << "sampleArray elements: ";
  for (int i: sampleArray) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Maximum value in sampleArray: " << maxArray(sampleArray,0,size-1) << endl;
}


