#include <iostream>
using namespace std;

class Singleton {
    private:
        string _string;

        // static pointer which will points to the instance of this class
        static Singleton *single_obj_ptr;

    public:
        // constructor of Singleton class must be empty
        Singleton(){};

        static Singleton* get_instance(){
            // If there is no instance of class then we can create an instance.
            if (single_obj_ptr == NULL) 
            {
                single_obj_ptr = new Singleton(); 
                return single_obj_ptr; 
            }
            else
            {
                // single_obj_ptr != NULL means the class already have an instance. 
                // So, we are returning that instance and not creating new one.
                return single_obj_ptr;
            }
        }

        void set_string(string string_value){
            _string = string_value;
        }

        void display_string(){
            cout << _string << endl;
        }
};

Singleton* Singleton::single_obj_ptr = NULL; 

int main()
{
    Singleton *obj_1 = Singleton::get_instance(); 
    obj_1->set_string("String 1");
    obj_1->display_string();
    cout << "Address of obj_1: " << obj_1 << endl;

    Singleton *obj_2 = Singleton::get_instance(); 
    obj_2->set_string("String 2");
    obj_2->display_string();
    cout << "Address of obj_2: " << obj_2 << endl;
}