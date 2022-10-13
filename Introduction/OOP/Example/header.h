#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class exampleClass
{
  	public:
		static int 	static_var;
		static void read_static_var();
		int 		instance_var;
		void 		class_constructor();
		void 		add_number(int int_param);
  	private:  
    	int 		_int_param;
};
#endif
