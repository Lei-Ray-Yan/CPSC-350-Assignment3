/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the FileReader class, which simply read and process the content of a given file to strings and vector.

*/



#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class FileReader{
public:
  string filePath;  //the current file path
  vector<string> fileContent; //content of the text file line-for-line
  int lineCount = 0;  //how many lines

  FileReader();
  ~FileReader();
  FileReader(string newFilePath);

  /*
    read the content of the line and store them into a string vector.
    return false if file not found.
  */
  bool readLineToVector();
  /*
    output the content of fileContent to the console.
    for testing and debugging only. 
  */
  void outputContentToConsole();

};


#endif










