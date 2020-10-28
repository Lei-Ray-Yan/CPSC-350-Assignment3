/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the .cpp file for the DelimiterChecker object, which defines the detail for the .h file. 

*/



#include "DelimiterChecker.h"

using namespace std;


DelimiterChecker :: DelimiterChecker(){
  //do nothing;
}

DelimiterChecker :: ~DelimiterChecker(){
  //do nothing;
}



bool DelimiterChecker :: findDelimiterError(vector<string> content){
  GenStack<char> *delimiters = new GenStack<char>();

  for(int i=0; i<content.size(); ++i){
    string currLine = content[i];
    int lineCount = i+1;

    for(int j=0; j<currLine.length(); ++j){
      //record detected front delimiters to stack
      if(currLine[j] == '(' || currLine[j] == '{' || currLine[j] == '['){
        delimiters->push(currLine[j]);
      }

      //detected back delimiters, try to pair up with recorded front delimiters
      if(currLine[j] == ')' || currLine[j] == '}' || currLine[j] == ']'){
        //if stack empty, means no corresponding front, thus error.
        if(delimiters->top == -1){
          switch(currLine[j]){
            case ')':
              errorMessage(1, lineCount, '\0');
              break;
            case '}':
              errorMessage(2, lineCount, '\0');
              break;
            case ']':
              errorMessage(3, lineCount, '\0');
              break;
          }
          return true;
        }
        //check corresponding
        else{
          char lastRecorded = delimiters->pop();
          bool errorFound = false;

          switch(lastRecorded){
            case '(':
              if(currLine[j] != ')'){
                errorMessage(11, lineCount, currLine[j]);
                errorFound = true;
              }
              break;
            case '{':
              if(currLine[j] != '}'){
                errorMessage(12, lineCount, currLine[j]);
                errorFound = true;
              }
              break;
            case '[':
              if(currLine[j] != ']'){
                errorMessage(13, lineCount, currLine[j]);
                errorFound = true;
              }
              break;
          }

          if(errorFound){
            return true;
          }

          continue;
        }
      }
    }
  }

  //after the for loop, check if stack still has stored delimiters.
  if(delimiters->top > -1){
    char lastRecorded = delimiters->pop();

    switch(lastRecorded){
      case '(':
        errorMessage(21, -1, '\0');
        break;
      case '{':
        errorMessage(22, -1, '\0');
        break;
      case '[':
        errorMessage(23, -1, '\0');
        break;
    }

    return true;
  }

  return false;
}

void DelimiterChecker :: errorMessage(int type, int lineCount, char wrongChar){
  if(type <20){
    cout << "Line " << lineCount << ": ";
  }
  else{
    cout << "Reached end of file: missing ";
  }

  string message = "";
  if(wrongChar == '\0'){
    message = "none";
  }else{
    message += wrongChar;
  }

  switch(type){
    case 1: //missing front (
      cout << "Expected ( before ). " << endl;
      break;
    case 2: //missing front {
      cout << "Expected { before }. " << endl;
      break;
    case 3: //missing front [
      cout << "Expected [ before ]. " << endl;
      break;

    case 11:  //missing back )
      cout << "Expected ) and found " << message << ". " << endl;
      break;
    case 12:  //missing back }
      cout << "Expected } and found " << message << ". " << endl;
      break;
    case 13:  //missing back ]
      cout << "Expected ] and found " << message << ". " << endl;
      break;

    case 21:  //reached end missing )
      cout << ")" << endl;
      break;
    case 22:  //reached end missing }
      cout << "}" << endl;
      break;
    case 23:  //reached end missing ]
      cout << "]" << endl;
      break;

  }
}












