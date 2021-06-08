/** @file EncryptedString.h */
#ifndef _ENCRYPTED_STRING
#define _ENCRYPTED_STRING

#include <iostream>
#include<string>
using namespace std;

class EncryptedString
{
  private:
    string encrypted_string;
  public:
    EncryptedString();
    EncryptedString(string str);
    void set(string str);
    string get();
    string getEncrypted();
}; 

#endif