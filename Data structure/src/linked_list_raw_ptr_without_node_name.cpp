#include <iostream>
#include <cmath> 

using namespace std;
class LinkedList { 
    public:
        int value;
        LinkedList* next_node;
        void insert_node(int value){
            LinkedList* node = new LinkedList;
            if (!first_node){
                first_node = node;
                first_node->value = value;
            }
            else {
                node->value = value;
                this->next_node = node;
            }
        }
        void display_link_list(){
            LinkedList *ptr = first_node;
            while(ptr != NULL)
            {        
                cout << "(" << ptr->value << ") ";
                ptr = ptr->next_node;
            }
            cout << endl;
        }
        LinkedList(){
            first_node = nullptr;
        }   
    private:
        LinkedList *first_node;
}; 

// Also add clear
int main() 
{ 
    LinkedList ll;// Linked list object
    ll.insert_node(123);
    ll.insert_node(456);
    ll.insert_node(789);
	ll.display_link_list();
    return 0; 
} 