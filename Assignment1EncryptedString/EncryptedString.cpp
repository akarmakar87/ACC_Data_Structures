/** @file EncryptedString.cpp */
#include <string>
#include "EncryptedString.h"
using namespace std;

EncryptedString::EncryptedString() {
  encrypted_string = "";
}

EncryptedString::EncryptedString(string str){
  set(str);
}

void EncryptedString::set(string str) {
  for (char c:str) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
      encrypted_string += (c - 1);
    else if (c == ' ')
      encrypted_string += " ";
  }
}

string EncryptedString::get() {
  string decrypted_string = "";
  for (char c:encrypted_string) {
      if (c == ' ')
        decrypted_string += " ";
      else
        decrypted_string += (c + 1);
  }
  return decrypted_string;
} 

string EncryptedString::getEncrypted(){
  return encrypted_string;
}

