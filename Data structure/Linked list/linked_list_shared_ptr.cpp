#include <iostream>
#include <memory> 

using namespace std;
class LinkedList { 
    public:
        int value;
        std::shared_ptr<LinkedList> next_node;
        void insert_next_node(std::shared_ptr<LinkedList> next_node, int value){
            next_node->value = value;
            this->next_node = next_node;
        }
}; 

void display_link_list(std::shared_ptr<LinkedList> first_node){
    std::shared_ptr<LinkedList> ptr = first_node;

    while(ptr != NULL)
	{        
		printf("(%d) ", ptr->value);
		ptr = ptr->next_node;
    }
	printf("\n");
}

int main() 
{ 
    std::shared_ptr<LinkedList> node_0 = std::make_shared<LinkedList>();
    std::shared_ptr<LinkedList> node_1 = std::make_shared<LinkedList>();
    std::shared_ptr<LinkedList> node_2 = std::make_shared<LinkedList>();

    node_0->value = 1;
    node_0->insert_next_node(node_1, 2);
    node_1->insert_next_node(node_2, 3);
    node_2->next_node = NULL;

    display_link_list(node_0);
    return 0; 
} 