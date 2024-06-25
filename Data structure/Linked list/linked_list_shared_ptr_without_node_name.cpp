#include <iostream>
#include <memory> 
#include <vector> 

using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {
        first_node = nullptr;
    }
    
    // If getting invalid index, return -1
    int get(int index) {
        if (index > get_size()-1) return -1; // Invalid index
        shared_ptr<MyLinkedList> ptr = first_node;
        int _index = 0;
        while(_index != index) {
            ptr = ptr->next_node;
            _index += 1;
        }
        
        return ptr->_value;
    }
    
    void addAtHead(int value) {
        shared_ptr<MyLinkedList> new_node = std::make_shared<MyLinkedList>();

        // When there is no first_node at list
        if (first_node == nullptr) {
            first_node = new_node;
            new_node->_value = value;
            first_node->next_node = nullptr;
        }
        else {
            // When there is already the first_node at list
            new_node->next_node = first_node->next_node;
            new_node->_value = first_node->_value;
            first_node->next_node = new_node;
            first_node->_value = value;
        }
    }
    
    void addAtTail(int val) {
        shared_ptr<MyLinkedList> ptr = first_node;
        int sz = 0;
        while(ptr != NULL) {        
            sz += 1;
            ptr = ptr->next_node;
        }
        addAtIndex(sz, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > get_size() - 1) return; // Invalid index
        
        shared_ptr<MyLinkedList> ptr = first_node;
        shared_ptr<MyLinkedList> new_node = std::make_shared<MyLinkedList>();

        if (index == 0) {
            addAtHead(val);
            return;
        }

        int _index = 0;

        while(_index != index - 1) {                
            ptr = ptr->next_node;
            _index += 1;
        }

        // When _index == index - 1
        new_node->next_node = ptr->next_node;
        new_node->_value = val;
        ptr->next_node = new_node;
        return;
    }
    
    void deleteAtIndex(int index) {
        if (index > get_size()-1) return; // Invalid index

        shared_ptr<MyLinkedList> ptr = first_node;
        shared_ptr<MyLinkedList> prev_node = std::make_shared<MyLinkedList>();
        int _index = 0;

        // Delete the first node
        if (index == 0) {      
            if (first_node->next_node == nullptr) first_node = nullptr;
            else  first_node = first_node->next_node;

            return;
        }

        int tmp_index = 0;

        while(ptr != NULL) {        
            if (tmp_index == index) {
                prev_node->next_node = ptr->next_node;
                return;
            }
            prev_node = ptr;  
            ptr = ptr->next_node;
            tmp_index++;
        }
        return;
    }

    void display_list() {
        shared_ptr<MyLinkedList> ptr = first_node;

        while(ptr != NULL) {        
            cout << ptr->_value << " ";
            ptr = ptr->next_node;
        }
        cout << endl;
    }

    int get_size() {
        int sz = 0;
        shared_ptr<MyLinkedList> ptr = first_node;

        while(ptr != NULL) {        
            sz += 1;
            ptr = ptr->next_node;
        }
        return sz;
    }
private:
    int _value;
    shared_ptr<MyLinkedList> next_node;
    shared_ptr<MyLinkedList> first_node;
};

int main() { 
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(3);
    // obj->addAtHead(2);
    // obj->addAtHead(12);

    // obj->addAtTail(3);
    // obj->addAtIndex(1,2);

    // cout << obj->get(1) << endl;
    // obj->addAtHead(1);
    // obj->addAtHead(5);

    // obj->display_list();

    obj->deleteAtIndex(0);
    cout << obj->get(0) << endl;
    obj->display_list();

    return 0; 
} 
