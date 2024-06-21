Linked list with node name, implemented by raw pointer:
* Insert a new node
* Display linked list from the current node
* Convert vector to linked list
* Convert linked list to vector

**Program**: [Raw pointer with node name](linked_list_raw_ptr_with_node_name.cpp)

**Shared pointer for linked list**:
* Create and read all members of a linked list
* Convert a linked list to a vector

Program: [linked_list_shared_ptr_with_node_name.cpp](linked_list_shared_ptr_with_node_name.cpp) and [linked_list_shared_ptr_without_node_name.cpp](linked_list_shared_ptr_without_node_name.cpp)

**Unique pointer can't be used to traverse the linked list created by it**.

Reverse a linked list
* Use stack: Put all member into a stack, then start popping them out (as LIFO) so that the last member of the linked list is now the first one
* Use recurive: [linked_list_reverse_linked_list_by_recursive.cpp](linked_list_reverse_linked_list_by_recursive.cpp)
