/* Copyright: Daniel Katzberg
This solution shows the default loops in C/C++.
This solution is without any templates, self coded headers and function.
*/
#include <iostream>

using namespace std;

int main()
{
  int forLoopIMax = 5;
  int forLoopJMax = 10;
  int whileCounter = 0;

  cout << "-------------------------------------\n";

  /* The init, condition check and the re-init steps are in the 'for' line.*/
  for (int i = 0; i <= forLoopIMax; i++) {
    cout << "First Example: For Loop: i = ";
    cout << i;
    cout << "\n";
  }

  cout << "-------------------------------------\n";

  /* Simple example for combined for loops. */
  for (int i = 0; i <= forLoopIMax; i++) {
    for (int j = 0; j <= forLoopJMax; j++) {
      cout << "Second Example: For Loop: i = ";
      cout << i;
      cout << " and j = ";
      cout << j;
      cout << "\n";
    }
  }

  cout << "-------------------------------------\n";

  /* Endless for loop with break command.*/
  for (;;) {
    cout << "Third Example: Endless for loop with break command.\n";
    break; //Leave the loop
  }

  cout << "-------------------------------------\n";

  /* While Loops. Init is before the while loop. Condition check is in the
  'while' iteration line. The re-init step is in the loop. */
  while (whileCounter <= forLoopIMax) {
    cout << "Forth Example: For Loop: whileCounter = ";
    cout << whileCounter;
    cout << "\n";
    whileCounter += 1;
  }

  cout << "-------------------------------------\n";

  /* Do-While Loop: The first iteration happens guaranteed. */
  do {
    cout << "Fifth Example: For Loop: whileCounter = ";
    cout << whileCounter;
    cout << "\n";
    whileCounter += 1;
  } while (whileCounter <= forLoopIMax);

  cout << "-------------------------------------\n";

  /* Endless while loop with break command.*/
  while (true) {
    cout << "Sixth Example: Endless while loop with break command.\n";
    break; //Leave the loop
  }

  cout << "-------------------------------------\n";
}
