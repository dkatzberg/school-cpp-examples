/* Copyright: Daniel Katzberg
This solution shows the default loops in C/C++.
This solution is without any templates, self coded headers and function.
*/
#include <iostream>

using namespace std;

int main() {

  //Just an int value.
  int number = 42;

  //Headline
  cout << "Address\t\t Value" << endl;

  //Print Address of the int value and the int value of the number
  cout << &number << "\t " << number << endl ;

  //Create a new pointer with the adress of the integer
  //Think about it just a moment. What does this mean?
  //Answer: The pointer reference to an address and points to a depending value in a second step.
  int *pointerNumber = &number;

  //The pointer has the address of the variable number. BUT The pointer itself has a own address,
  //because it is an variable and need an own address.
  cout << pointerNumber << "\t " << &pointerNumber << endl;

  //It is possible to get the value of number with the pointerNumber Pointer with dereferencing
  //For dereferencing you need the * before the pointerNumber Pointer.
  cout << &pointerNumber << "\t " << *pointerNumber << endl;

  //Question: What is the output of cout number line?
  //*pointerNumber = 123;
  //cout << &number << "\t " << number;

  return 0;
}
