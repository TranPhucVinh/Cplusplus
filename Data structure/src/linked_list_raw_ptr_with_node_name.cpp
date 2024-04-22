#include <iostream>
#include <cmath> 
#include <vector> 

using namespace std;
class LinkedList { 
    public:
        int value;
        LinkedList* next_node;
        void insert_next_node(LinkedList *next_node, int value);
        void display_link_list();
        
        // LinkedList* vector_to_linkedlist(vector<int> vec);
}; 

void LinkedList::display_link_list(){
    LinkedList *ptr = this;

    while(ptr != NULL)
	{        
		printf("(%d) ", ptr->value);
		ptr = ptr->next_node;
    }
	printf("\n");
}

void LinkedList::insert_next_node(LinkedList *next_node, int value){
    next_node->value = value;
    this->next_node = next_node;
}

int main() 
{ 
    LinkedList *node_0, *node_1, *node_2;

	node_0 = new LinkedList;
    node_1 = new LinkedList;
    node_2 = new LinkedList;

    node_0->value = 123;
    node_0->insert_next_node(node_1, 456);
    node_1->insert_next_node(node_2, 789);
    node_2->next_node = NULL;

    node_0->display_link_list();

    delete node_0;
    delete node_1;
    delete node_2;
    return 0; 
} 
