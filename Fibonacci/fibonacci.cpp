/* Copyright: Daniel Katzberg
This solution is without templates, self coded headers and functions.
This solution handles the correct start of the fibonacci numbers:
0 1 1 2 3 5 ...
*/
#include <iostream>

using namespace std;

int main()
{
    int lines, columns;
    unsigned long long int lastFibonacci = 0;
    unsigned long long int secondLastFibonacci = 0;
    unsigned long long int nextFibonacci = 0;
    bool tableOutput = true;

    //Read number of lines and columns
    cout << "How many lines for the Fibonacci numbers? ";
    cin >> lines;

    cout << "How many columns for the Fibonacci numbers? ";
    cin >> columns;

    cout << "Enter '1' for table output and '0' for list output: ";
    cin >> tableOutput;

    int tableArray[lines][columns];

    //Check Fibonacci Numbers : Init
    for (int l = 0; l < lines; l++) {
      for (int c = 0; c < columns; c++) {

        //The two if blocks are needet for the second 1 in the Fibonacci Order
        //0 1 1 2 3 ...
        //You have to set the last Fibonacci Number, because the nextFibonacci is the Default variable
        if (lastFibonacci == 1 && nextFibonacci == 1) {
          tableArray[l][c] = nextFibonacci;
          lastFibonacci = 2;
          nextFibonacci = 1;
          continue;
        }
        if (lastFibonacci == 2 && nextFibonacci == 1) {
          tableArray[l][c] = lastFibonacci;
          secondLastFibonacci = 0;
          lastFibonacci = 1;
        }

        //Set the Fibonacci Number
        tableArray[l][c] = nextFibonacci;

        //Set the next Fibonacci number
        secondLastFibonacci = lastFibonacci;
        if (lastFibonacci == 0) {
          lastFibonacci += 1;
        } else {
          lastFibonacci = nextFibonacci;
        }
        nextFibonacci = lastFibonacci + secondLastFibonacci;
      }
    }

    //Print Table Output
    if (tableOutput) {
      for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
          cout << tableArray[l][c] << " ";
        }
        cout << "\n";
      }
    //List output
    } else {
      for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
          cout << tableArray[l][c] << " ";
        }
      }
    }

    return 0;
}
