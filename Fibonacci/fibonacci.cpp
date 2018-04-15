/* Copyright: Daniel Katzberg
This solution is without templates, self coded headers and functions.
Every non Fibonacci Number will be replaced by -1
*/
#include <iostream>

using namespace std;

int main()
{
    int lines, columns;
    int lastFibonacci, secondLastFibonacci;
    int nextFibonacci = -1; //Ignore this number for the first init runs
    bool tableOutput = true;

    //Read number of lines and columns
    cout << "How many lines for the Fibonacci numbers? ";
    cin >> lines;

    cout << "How many columns for the Fibonacci numbers? ";
    cin >> columns;

    cout << "Enter '1' for table output and '0' for list output: ";
    cin >> tableOutput;

    int tableArray[lines][columns];

    //Init -> Write all numbers into the table array
    for (int l = 0; l < lines; l++) {
      for (int c = 0; c < columns; c++) {
        tableArray[l][c] = (l * columns) + c;
      }
    }

    //Check Fibonacci Numbers : Init
    for (int l = 0; l < lines; l++) {
      for (int c = 0; c < columns; c++) {

        //All Numbers until 3 are Fibonacci

        //Init -> First non Fibonacci
        if (tableArray[l][c] == 4) {
          tableArray[l][c] = -1;
          lastFibonacci = 3;
          secondLastFibonacci = 2;
          nextFibonacci = lastFibonacci + secondLastFibonacci;
        }

        //Replacement for non Fibonacci numbers
        if (tableArray[l][c] > 4 && tableArray[l][c] < nextFibonacci ) {
          tableArray[l][c] = -1;
        }

        //Find the next Fibonacci Number
        if (tableArray[l][c] > 4 && tableArray[l][c] == nextFibonacci ) {
          secondLastFibonacci = lastFibonacci;
          lastFibonacci = tableArray[l][c];
          nextFibonacci = lastFibonacci + secondLastFibonacci;
        }
      }
    }

    //Print Table Output
    if (tableOutput) {
      for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
          if (tableArray[l][c] != -1) {
            cout << tableArray[l][c];
          } else {
            cout << "--";
          }
          cout << " ";
        }
        cout << "\n";
      }
    //List output
    } else {
      for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
          if (tableArray[l][c] != -1) {
            cout << tableArray[l][c];
            cout << " ";
          }
        }
      }
    }

    return 0;
}
