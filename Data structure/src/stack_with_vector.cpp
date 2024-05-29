#include <iostream>
#include <vector>

using namespace std;

class Stack{
    private:
        vector<int> _stack_vec;
        int 	    _top;

    public:
        Stack(){        
            _top = -1;
        }
        int pop(){
            if(!is_empty()) {
                int data = _stack_vec[_top];
                _top = _top - 1;
                _stack_vec.pop_back();
                return data;
            } else {
                std::cout << "Could not retrieve data, stack is empty\n";
                return 0;
            }
        }
        void push(int data){
            _top += 1;   
            _stack_vec.push_back(data);
        }

        int is_empty(){
            return !_stack_vec.size();
        }
};

int main() {
    Stack stack;

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
