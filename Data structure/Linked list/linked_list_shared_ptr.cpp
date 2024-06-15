#include <iostream>
#include <memory> 
#include <vector> 

using namespace std;

class LinkedList { 
    public:
        int value;
        shared_ptr<LinkedList> next_node;
        void insert_next_node(shared_ptr<LinkedList> next_node, int value){
            next_node->value = value;
            this->next_node = next_node;
        }
}; 

void display_link_list(shared_ptr<LinkedList> first_node){
    shared_ptr<LinkedList> ptr = first_node;

    while(ptr != NULL)
	{        
		printf("(%d) ", ptr->value);
		ptr = ptr->next_node;
    }
	cout << endl;
}

vector<int> linked_list_to_vector(shared_ptr<LinkedList> first_node){
	vector<int> ll_vector;
	shared_ptr<LinkedList> ptr = first_node;

    while(ptr != NULL)
	{        
		ll_vector.push_back(ptr->value);
		ptr = ptr->next_node;
    }

    for (int i = 0; i < ll_vector.size(); i++){
		cout << ll_vector[i] << " ";
    }
	cout << endl;

	return ll_vector;
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
	linked_list_to_vector(node_0);
    return 0; 
} 