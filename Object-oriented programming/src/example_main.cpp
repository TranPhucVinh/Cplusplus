#include "header.h"

int main(){
	exampleClass object, *obj_ptr;
    object.add_number(13);
	object.read_static_var();
	object.call_private_function();
    object.call_object_method(object);//Call function with the same object

    exampleClass new_object;
    object.call_object_method(new_object);//Call function with the new object

    obj_ptr = &object;// Class object as pointer
    obj_ptr->add_number(1);
}
