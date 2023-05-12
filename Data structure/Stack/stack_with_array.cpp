#include <iostream>

#define STACK_SIZE 8

class Stack{
    private:
        int 	*stack_arr;
        int     _stack_size;
        int 	top;
    public:
        Stack(int stack_size){
            stack_arr = new int[stack_size];
            top = -1;
        }
        ~Stack(){
            delete(stack_arr);
        }
        int pop(){
            int data;
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
        void push(int data){
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
    Stack stack(STACK_SIZE);

	// push items into the stack 
	stack.push(3);
	stack.push(5);
	stack.push(9);
	stack.push(1);
	stack.push(12);
	stack.push(15);

    // print stack data 
    while(!stack.is_empty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    if (stack.is_empty()) std::cout << "Stack is empty\n";
    else std::cout << "Stack isn't empty\n";

   	return 0;
}