/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 2
// Project Desc: Rectangle Class with Interface
// Course: COSC 2436 PF III Data Structures
// Date: 02/07/2021

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
  Rectangle theRectangle;
	
  cout << "Initial state of the rectangle:" << endl;
  cout << "    length = " << theRectangle.getLength() << endl;
  cout << "    width  = " << theRectangle.getWidth() << endl;
  cout << "    area   = " << theRectangle.getArea() << endl << endl;
	
  theRectangle.set(3.0,5.0);
  cout << "Current state of the rectangle:" << endl;
  cout << "    length = " << theRectangle.getLength() << endl;
  cout << "    width  = " << theRectangle.getWidth() << endl;
  cout << "    area   = " << theRectangle.getArea() << endl << endl;
	
  return 0;
}