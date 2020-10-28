/*
- Raymond Raymond
- 2297956
- lyan@chapman.edu
- CPSC-350-01
- Assignment 3

- this is the GenStack template class.
It can take multiple data types, and automaticly assign more spaces if full by dynamicly allocating 2D arrays.
In case of pop/ peek for empty, it will prompt the user to remaind them.

*/



#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;


template <typename GenType>
class GenStack{
public:
  int clusterTop; //the current sub array's index in the clusterArray;
  int clusterSize; //the size of current clusterArray;

  int top;  //the index of last stored element in the sub array. 
  int arraySize;  //the size of each sub arrays.

  GenType **clusterArray; // the clusterArray stores pointers to the sub arrays, which stores the actual datas.

  int num = 0; //for debugging

  GenStack();
  ~GenStack();
  GenStack(int maxSize);

  /*
    add a new element to the end.
    in case of full, it will automatically allocate more spaces in checkFull();
  */
  void push(GenType input);
  /*
    return and remove the last element.
    in case of empty, it will prompt a message to the console.
  */
  GenType pop();
  /*
    return but not removing the last element.
    in case of empty, it will prompt a message to the console.
  */
  GenType peek();

  /*
    check if the current allocated space is all used up,
    if so, this is where the extra allocating actually take place.
  */
  bool checkFull();
  /*
    check if is empty.
  */
  bool isEmpty();
  /*
    the implementation of the GenStack is based on 2D array.
    this method check if the "sub" array, which unlike the cluster array who stores pointer to sub arrays, is empty or not.
  */
  bool isSubEmpty();
  /*
    return the quantity of total stored elements.
  */
  int getSize();
  /*
    print all stored elements to the console.
    for testing and debugging only.
  */
  void printAll();

};




//constructor & destructor
template <typename GenType>
GenStack<GenType> :: GenStack(){
  arraySize = 128;
  clusterArray = new GenType*[arraySize];
  clusterArray[0] = new GenType[arraySize];

  clusterTop = 0;
  top = -1;
  clusterSize = 1;
}

template <typename GenType>
GenStack<GenType> :: ~GenStack(){
  for (int i=0; i<clusterSize; ++i){
    delete [] clusterArray[i];
  }
  delete clusterArray;
}

template <typename GenType>
GenStack<GenType> :: GenStack(int maxSize){ //the max size of sub array, not the cluster array
  arraySize = maxSize;
  clusterArray = new GenType*[arraySize];
  clusterArray[0] = new GenType[maxSize];

  clusterTop = 0;
  top = -1;
  clusterSize = 1;
}



//core functions
template <typename GenType>
void GenStack<GenType> :: push(GenType input){

  if(checkFull()){
    clusterTop += 1;
    top = 0;
  }else{
    top += 1;
  }

  clusterArray[clusterTop][top] = input;
}

template <typename GenType>
GenType GenStack<GenType> :: pop(){
  try{
    if(isEmpty()){
      throw "empty stack";
    }
  }
  catch(char const*){
    cout << "Stack is empty!" << endl;
  }


  int currTop = top;
  int currClusterTop = clusterTop;
  if(isSubEmpty()){
    clusterTop -= 1;
    top = arraySize - 1;
  }else{
    top -= 1;
  }

  return clusterArray[currClusterTop][currTop];
}

template <typename GenType>
GenType GenStack<GenType> :: peek(){
  try{
    if(isEmpty()){
      throw "empty stack";
    }
  }
  catch(char const*){
    cout << "Stack is empty!" << endl;
  }

  return clusterArray[clusterTop][top];
}



//utility funcitons
template <typename GenType>
bool GenStack<GenType> :: checkFull(){
  GenType *currArray = clusterArray[clusterTop];
  bool returnValue = false;

  if(top>=arraySize){
    returnValue = true;
    if((clusterTop+1)>=clusterSize){
      clusterSize += 1;
      GenType **newArray = new GenType *[clusterSize];

      for (int i=0; i<clusterSize; ++i){
        newArray[i] = new GenType[arraySize];
      }

      for(int i=0; i<(clusterSize-1); ++i){
        newArray[i] = clusterArray[i];
      }

      delete[] clusterArray;
      clusterArray = newArray;
    }
  }

  return returnValue;
}

template <typename GenType>
bool GenStack<GenType> :: isEmpty(){
  return (top < 0 && clusterTop <= 0);
}

template <typename GenType>
bool GenStack<GenType> :: isSubEmpty(){
  return (top < 0);
}

template <typename GenType>
int GenStack<GenType> :: getSize(){
  int clusterNum = (clusterSize<=0) ? 0 : clusterSize - 1;
  int totalSize = clusterNum*arraySize + top;

  return totalSize;
}

template <typename GenType>
void GenStack<GenType> :: printAll(){
  if(top<0 && clusterTop<=0){
    cout << "Stack is empty: nothing to print" << endl;
    return;
  }

  for(int i=0; i<clusterSize; ++i){
    int limit = arraySize;
    if(i == clusterTop){
      limit = top + 1;
    }
    for(int j=0; j<limit; ++j){
      cout << num++ << endl;
      cout << clusterArray[i][j] << endl;
    }
  }
}



#endif





















