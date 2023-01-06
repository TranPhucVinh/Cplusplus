#include "header.h"

main(){
	exampleClass object;
	object.class_constructor();
    object.add_number(13);
	object.read_static_var();
	object.call_private_function();
    object.call_object_method(object);

    exampleClass object_1;
    object.call_object_method(object_1);
}
