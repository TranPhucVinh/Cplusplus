#include "header.h"
using namespace std;

int exampleClass::staticVariable = 10;

void exampleClass::exampleClassConstructor(){
    cout << "Example class constructor" << endl;
}

void exampleClass::addNumber(int intParameter){
    _intParameter = 10;
    int returnInt = intParameter + _intParameter + staticVariable;
    cout << "returnInt: " << returnInt << endl;
}