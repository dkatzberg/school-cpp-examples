/* Copyright: Daniel Katzberg
This solution shows a solution for the sieve of Erastosthenes in C/C++.
This solution is without any templates, self coded headers and function.
*/
#include <iostream>

using namespace std;

int main()
{

  int sieveLimit;

  //Read the max number until the sieve should find prime numbers
  cout << "Enter a limit for finding prime numbers until this limit: ";
  cin >> sieveLimit;

  bool sieveArray[sieveLimit + 1];

  //install all numbers until the sieve limit
  for (int i = 2; i <= sieveLimit; i++) {
    sieveArray[i] = true;
  }

  //Sqrt from SieveLimit is the max Number for iteration of the sieve
  //The Opposite is to take the quadrate of i for looking if its over the
  //SieveLimit
  for (int i = 2; i*i <= sieveLimit; i++ ) {
    //The Value is true, if it is a prime number
    if (sieveArray[i]) {
      //Set Multiples of a found prime number i to false (no prime number)
      for (int noPrimeCounter = i * 2; noPrimeCounter <= sieveLimit;
        noPrimeCounter += i) {
          sieveArray[noPrimeCounter] = false;
      }
    }
  }

  //Output the prime numbers
  for (int i = 2; i <= sieveLimit; i++) {
    if (sieveArray[i]) {
      cout << i << " ";
    }
  }
}
