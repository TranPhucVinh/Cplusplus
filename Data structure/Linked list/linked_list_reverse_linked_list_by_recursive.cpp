#include <iostream>
#include <cmath> 

using namespace std;
class LinkedList { 
    public:
        int value;
        LinkedList* next_node;
        void insert_node(int value){
            LinkedList* node = new LinkedList;
            node->value = value;
            node->next_node = nullptr;

            // This init the first node and set the current node to the first node for later step
            // to add a new node to the linked list
            if (!_first_node){
                _first_node = node;
                _current_node = node;
            }
            else {
                _current_node->next_node = node;
                _current_node = _current_node->next_node;
            }
        }
        // Reverse the linked list then update the first node
        void reverse_linked_list(){
            _reverse(nullptr, _first_node);
        }
        void display_linked_list(){
            LinkedList *ptr = _first_node;
            while(ptr != NULL)
            {        
                cout << "(" << ptr->value << ") ";
                ptr = ptr->next_node;
            }
            cout << endl;
        }
        LinkedList(){
            _first_node = nullptr;
            _current_node = nullptr;
        }   
        ~LinkedList(){
            LinkedList *_current = _first_node;
            while(_current != NULL)
            {        
                LinkedList *_next = _current->next_node;
                delete _current;
                _current = _next;
            }
        }   

    private:
        LinkedList *_first_node, *_current_node;
        void _reverse(LinkedList* prev, LinkedList* current) {
            if (current == nullptr) {
                // Reached the end of the list, set the first node to the last node
                _first_node = prev;
                return;
            }

            LinkedList* next = current->next_node;
            current->next_node = prev;

            // Recursively move to the next node
            _reverse(current, next);
        }
}; 

int main() 
{ 
    LinkedList ll;// Linked list object
    ll.insert_node(123);
    ll.insert_node(456);
    ll.insert_node(789);
	ll.display_linked_list();

    ll.reverse_linked_list();
    ll.display_linked_list();
    return 0; 
} 