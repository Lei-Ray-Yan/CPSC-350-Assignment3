/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the DelimiterChecker class, which handles the actual comparison and checking of the syntax (delimiter syntax) for the given text,
and prompt corresponding error message to the user.

*/



#ifndef DELIMITERCHECKER_H
#define DELIMITERCHECKER_H

#include <iostream>
#include <vector>
#include "GenStack.h"

using namespace std;


class DelimiterChecker{
public:
  DelimiterChecker();
  ~DelimiterChecker();

  /*
    checks delimiter syntax from the given content (string vector),
    returns true if an error found.
  */
  bool findDelimiterError(vector<string> content);
  /*
    handles specific messages that will be prompt to the user at each situation.
  */
  void errorMessage(int type, int lineCount, char wrongChar);
};


#endif
















