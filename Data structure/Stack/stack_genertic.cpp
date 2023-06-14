#include <iostream>

#define STACK_SIZE 8

template<class T> class Stack{
    private:
        T 	    *stack_arr;
        int 	top;
        int     _stack_size;
    public:
        Stack(int stack_size){
            stack_arr = new T[stack_size];
            _stack_size = stack_size;
            top = -1;
        }
        ~Stack(){
            delete(stack_arr);
        }
        T pop(){
            T data;
            if(!is_empty()) {
                data = stack_arr[top];
                stack_arr[top] = 0;// Reset value of stack_arr[top]
                top = top - 1;   
                return data;
            } else {
                std::cout << "Could not retrieve data, stack is empty\n";
                return 0;
            }
        }
        void push(T data){
            if(!is_full()) {
                top += 1;   
                stack_arr[top] = data;
            } else std::cout << "Could not insert data, stack is full\n";
        }
        int is_empty(){
            if(top == -1) return 1;
            else return 0;
        }
        int is_full(){
            if(top == _stack_size) return 1;
            else return 0;
        }
};

int main() {
    Stack<int> int_stack(STACK_SIZE);
    Stack<float> float_stack(STACK_SIZE);

	// push items into the int stack 
	int_stack.push(3);
	int_stack.push(5);
	int_stack.push(9);
	int_stack.push(1);
	int_stack.push(12);
	int_stack.push(15);

    // print stack data 
    while(!int_stack.is_empty()) {
        std::cout << int_stack.pop() << " ";
    }
    std::cout << std::endl;

    if (int_stack.is_empty()) std::cout << "Stack is empty\n";
    else std::cout << "Stack isn't empty\n";

	// push items into the float stack 
	float_stack.push(1.2);
	float_stack.push(2.3);
	float_stack.push(3.4);
	float_stack.push(4.5);

    // print stack data 
    while(!float_stack.is_empty()) {
        std::cout << float_stack.pop() << " ";
    }
    std::cout << std::endl;

    if (float_stack.is_empty()) std::cout << "Stack is empty\n";
    else std::cout << "Stack isn't empty\n";

   	return 0;
}