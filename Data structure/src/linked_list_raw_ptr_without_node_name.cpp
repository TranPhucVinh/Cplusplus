#include <iostream>
#include <cmath> 

using namespace std;
class LinkedList { 
    public:
        int value;
        LinkedList* next_node;
        void insert_next_node(int value){
            LinkedList* next_node = new LinkedList;
            next_node->value = value;
            this->next_node = next_node;
        }
        void display_link_list(){
            LinkedList *ptr = first_node;
            while(ptr != NULL)
            {        
                printf("(%d) ", ptr->value);
                ptr = ptr->next_node;
            }
            printf("\n");
        }
        LinkedList(){
            first_node = new LinkedList;
        }   
    private:
        LinkedList *first_node;
}; 

// Also add clear
int main() 
{ 
    LinkedList ll;// Linked list object
    ll.insert_next_node(123);
    ll.insert_next_node(456);
    ll.insert_next_node(789);
	ll.display_link_list();
    return 0; 
} 