/* Copyright: Daniel Katzberg
This solution shows the default loops in C/C++.
This solution is without any templates, self coded headers and function.
*/
#include <iostream>

using namespace std;

/* This is the first basic example of an array. It demonstrate the difference
    between an address and a value of a point in difference to an standard
    int variable.
*/
void basicExample() {
  //Just an int value.
  int number = 42;

  //Headline
  cout << "Address\t\t Value" << endl;

  //Print Address of the int value and the int value of the number
  cout << &number << "\t " << number << endl ;

  //Create a new pointer with the adress of the integer
  //Think about it just a moment. What does this mean?
  //Answer: The pointer reference to an address and points to a depending value
  //in a second step.
  int *pointerNumber = &number;

  //The pointer has the address of the variable number. BUT The pointer itself
  //has a own address, because it is an variable and need an own address.
  cout << pointerNumber << "\t " << &pointerNumber << endl;

  //It is possible to get the value of number with the pointerNumber Pointer
  //with dereferencing
  //For dereferencing you need the * before the pointerNumber Pointer.
  cout << &pointerNumber << "\t " << *pointerNumber << endl;

  //Question: What is the output of cout number line?
  //*pointerNumber = 123;
  //cout << &number << "\t " << number;
}

//This is an example, where an array is used as a pointer, because an array is
//a pointer.
void arrayExample() {
  //It is just an array with seven non sorted random numbers.
  int myPersonalNumbers[7] = {12,56,98,2,76,6,42};

  //The known standard way to get the address and the value of an array.
  cout << "Address \t Number" << endl;
  for (int i = 0; i < 7 ; i++) {
    cout << &myPersonalNumbers[i] << " \t " << myPersonalNumbers[i] << endl;
  }

  //An array is a pointer, if you use no index.
  //The second call of the array with the '*' and the '+ 0' is a dereference
  //for the index 0
  cout << endl;
  cout << "Address \t Number" << endl;
  //The pointer reference is to the first array index, if it is written
  //without any index
  cout << myPersonalNumbers << " \t " << *myPersonalNumbers  << endl;
  //The call for the forth entry with index 3 in the array.
  //cout << (myPersonalNumbers + 3) << " \t " << *(myPersonalNumbers + 3)  << endl;
}

int main() {

  //First Pointer example.
  //basicExample();

  //Pointer with array example.
  arrayExample();

  return 0;
}
