/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the .cpp file for the FileReader class. 

*/



#include "FileReader.h"

using namespace std;


FileReader :: FileReader(){
  filePath = "";
}

FileReader :: ~FileReader(){
  //do nothing;
}

FileReader :: FileReader(string newFilePath){
  filePath = newFilePath;
}



bool FileReader :: readLineToVector(){
  ifstream inFile;

  inFile.open(filePath);
  if(!inFile.is_open()){
    cout << "Error: file not found by given file path. " << endl;
    return false;
  }

  string currLine;
  while(getline(inFile, currLine)){
    fileContent.push_back(currLine);
  }

  return true;
}



void FileReader :: outputContentToConsole(){
  for(int i=0; i<fileContent.size(); ++i){
    cout << fileContent[i] << endl;
  }
}










