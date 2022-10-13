#include "header.h"
using namespace std;

int exampleClass::static_var = 10;

void exampleClass::class_constructor(){
    cout << "Example class constructor" << endl;
}

void exampleClass::add_number(int int_param){
    _int_param = 10;
    int return_val = int_param + _int_param + static_var;
    cout << "return value: " << return_val << endl;
}
