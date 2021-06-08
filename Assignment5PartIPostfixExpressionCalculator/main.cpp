/** @file main.cpp */
// Programmer: Asha Karmakar
// Project Number: 
// Project Desc:
// Course: COSC 2436 PF III Data Structures
// Date: 

#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>  
#include "ArrayStack.h"
using namespace std;

int evalPostfix(string pf_exp) {

  ArrayStack<int> stack;
  int value, num1, num2, result;

  for (char c:pf_exp){
    if (isdigit(c)){ // if operand, push to stack

      value = c - '0';
      stack.push(value);

    }else if (c != ' '){ // if operator, do operation

      try {
        num1 = stack.peek();
        stack.pop();
        num2 = stack.peek();
        stack.pop();

        switch(c) {
          case '+':
            result = num1 + num2; 
            break;
          case '-':
            result = num1 - num2; 
            break;
          case '*':
            result = num1 * num2; 
            break;
          case '/':
            result = num2 / num1; 
            break;
          default:
            result = -1;
            cout << "An invalid character was encountered." << endl;
            continue;
        } 

        stack.push(result);
      } catch (...) {
        cout << "Expression is malformed." << endl;
      }

    }
  }

  return result;
}

int main()
{
  string cont = "Y";
  string input;
  int answer;

  while (cont == "Y" || cont == "y") {
    input = "";
    cout << "Enter postfix expression: " << endl;
    getline(cin, input);
    answer = evalPostfix(input);
    if (answer != -1)
      cout << "The value of the expression is " << answer << endl;
    cout << "More expressions (Y or N)? ";
    getline(cin, cont);
  }

  return 0;

}  