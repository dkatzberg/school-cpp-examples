/* Copyright: Daniel Katzberg
This solution is without templates and self coded headers.
This File writes an file to the HDD and read it.
*/
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  //Char Array with a size of 500
  char data[500];
  string fileName = "testFile.txt";

  //###############################
  //# WRITE INTO THE FILE EXAMPLE #
  //###############################

  //Open output file stream. The file will be created
  //ATTENTION: THIS WILL OVERWRITE EVERYTHING IN THE FILE!
  ofstream outputFile;
  outputFile.open(fileName);
  cout << "Enter some letters: ";

  //Read the enter letters and save them into the file
  cin.getline(data, 500);
  outputFile << data << endl;

  // Close the output filestream
  outputFile.close();

  //##############################
  //# READ FROM THE FILE EXAMPLE #
  //##############################

  // Open an input file stream
  ifstream inputFile;
  inputFile.open(fileName);
  cout << "Load / read from file: " << endl;

  //Write line by line to the display
  for (string line; getline(inputFile, line); ) {
    cout << line;
  }

  // Close the input file stream
  inputFile.close();

  return 0;
}
