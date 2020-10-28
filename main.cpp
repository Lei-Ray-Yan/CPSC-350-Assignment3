/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the main file of this program, which combines all the feature together, and ask for and process user inputs correspondingly.

*/



#include <iostream>
#include "GenStack.h"
#include "FileReader.h"
#include "DelimiterChecker.h"

using namespace std;

int main(int argc, char** argv){
  //check initial file path given
  if(argc < 2){
    cout << "Seems like you forgot to provide the file path :) " << endl;
    exit(1);
  }

  //prepare file path
  string filePath = argv[1];
  string userInput;

  while(true){
    //read file
    FileReader fileReader(filePath);
    fileReader.readLineToVector();
    vector<string> fileContent = fileReader.fileContent;

    //process delimiter checking
    DelimiterChecker *delimiterChecker = new DelimiterChecker();
    bool errorFound = delimiterChecker->findDelimiterError(fileContent);

    //check if error found, then process correspondingly
    if(errorFound){
      exit(2);
    }
    else{
      cout << "Delimiter checking finished. No issue found. " << endl;
      cout << "Process another file? " << endl;
      cout << "(Enter EXIT to exit, or the file path to process another file. )" << endl;
      cin >> userInput;
    }

    //check if actual input given
    if(userInput.length() > 0){
      filePath = userInput;
    }
    else{
      cout << "Invalid file path given. Continuing with previous file path. " << endl;
    }

    //check manual exit
    if(filePath == "EXIT" || filePath == "Exit" || filePath == "exit"){
      break;
    }
  }

  return 0;
}

























