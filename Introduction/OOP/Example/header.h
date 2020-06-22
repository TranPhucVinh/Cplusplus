#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class exampleClass
{
  public:
    static int staticVariable;
    int instanceVariable;
    void exampleClassConstructor();
    void addNumber(int intParameter);
  private:  
    int _intParameter;
};
#endif