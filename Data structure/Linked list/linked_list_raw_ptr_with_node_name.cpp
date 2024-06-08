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
        
        LinkedList* vector_to_linkedlist(vector<int> vec);
        vector<int> linkedlist_to_vector();
}; 

/*
    Display the linked list, started from the current node
*/
void LinkedList::display_link_list(){
    LinkedList *ptr = this;

    while(ptr != NULL)
	{        
		cout << "(" << ptr->value << ") ";
		ptr = ptr->next_node;
    }
	cout << endl;
}

void LinkedList::insert_next_node(LinkedList *next_node, int value){
    next_node->value = value;
    this->next_node = next_node;
}

/*
    Convert vector to linked list
*/
LinkedList* vector_to_linkedlist(vector<int> vec){
    LinkedList *head = new LinkedList;
    LinkedList *current_node = head;

    for (int i = 0; i < vec.size(); i++){
        LinkedList *next_node = new LinkedList;
        current_node->value = vec[i];

        if (i != vec.size() -1){
            current_node->next_node = next_node;
            current_node = next_node;
        } else {
            current_node->next_node = NULL;
            delete next_node;
        }
    }
    return head;
}

/*
    Convert linked list to vector, started from the current node
*/
vector<int> LinkedList::linkedlist_to_vector(){
    vector<int> ll_vec;
    LinkedList *ptr = this;

    while(ptr != NULL)
	{        
        ll_vec.push_back(ptr->value);
		ptr = ptr->next_node;
    }

    for (int i = 0; i < ll_vec.size(); i++){
        cout << ll_vec[i] << " ";
    }
    cout << endl;

    return ll_vec;
}

int main() 
{ 
    // Create a linked list
    LinkedList *node_0, *node_1, *node_2;

	node_0 = new LinkedList;
    node_1 = new LinkedList;
    node_2 = new LinkedList;

    node_0->value = 123;
    node_0->insert_next_node(node_1, 456);
    node_1->insert_next_node(node_2, 789);
    node_2->next_node = NULL;

    node_0->display_link_list();

    // Convert the linked list, started from node_0, to vector
    node_0->linkedlist_to_vector();

    delete node_0;
    delete node_1;
    delete node_2;

    // Convert vector to a linked list
    vector<int> vec = {12, 34, 56};
    LinkedList* ll_node = vector_to_linkedlist(vec);
    ll_node->display_link_list();

    return 0; 
} 
