
# Template with class as type

```cpp
#include <iostream>
#include <typeinfo>

using namespace std;
template <typename class_type>
void call_object_method(class_type object){
    object.display_string();
    object.display_number();
}

class classTest{
	public:
		void display_string(){
			cout << "Hello World \n";
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest object;
    call_object_method<classTest>(object);
}
```
# Template as class method
```cpp
class classTest{
	public:
        template <typename dummy_type>
        dummy_type add_function(dummy_type a, dummy_type b);
};

int main(){
	classTest object;
    printf("%d\n", object.add_function<int>(1, 2));//3
    printf("%.2f\n", object.add_function<float>(1.2, 3.4));//4.6

}

template <typename dummy_type>
dummy_type classTest::add_function(dummy_type a, dummy_type b){
    std::cout << "dummy_type is " << typeid(dummy_type).name() << std::endl;
    return a + b;
}
```
