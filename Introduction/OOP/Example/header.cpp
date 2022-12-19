#include "header.h"
using namespace std;

/*
    Must not put storage class static here
    Calling static int exampleClass::static_var results in compilation error
*/
int exampleClass::static_var = 10;

void exampleClass::class_constructor(){
    cout << "Example class constructor" << endl;
}

void exampleClass::add_number(int int_param){
    _int_param = 10;
	instance_var = 11;
    int return_val = int_param + _int_param + static_var + instance_var;
    cout << "return value: " << return_val << endl;
}

/*
    Must not put storage class static here
    Calling static void exampleClass::read_static_var() results in compilation error
*/
void exampleClass::read_static_var(){
	/*
		Non-static variable instance_var can't be called inside this static function
		Non-static function add_number() can't be called inside this static function
	*/
	static_var = 190;
	cout << static_var << endl;
}

void exampleClass::call_private_function(){
    display_string();
}

void exampleClass::display_string(){
    cout << "Private function can only be called inside public function" << endl;
}
