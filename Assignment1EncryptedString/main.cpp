/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 1
// Project Desc: EncryptedString class
// Course: COSC 2436 PF III Data Structures
// Date: 01/30/2021

#include <iostream>
#include "EncryptedString.h"
using namespace std;

int main() {

  // demonstrates default constructor functionality
  EncryptedString empty;
  cout << "EMPTY ENCRYPTED STRING: " << empty.getEncrypted() << "\n\n";

  // demonstrates parameter constructor & other class methods' functionality
  // NOTE: set() method called within parameter constructor
  EncryptedString message("Hello World!123");
  cout << "ENCRYPTED: " << message.getEncrypted() << endl;
  cout << "ORIGINAL: " << message.get() << endl;

}