Linked list with node name, implemented by raw pointer:
* Insert a new node
* Display linked list from the current node
* Convert vector to linked list
* Convert linked list to vector

**Program**: [Raw pointer with node name](linked_list_raw_ptr_with_node_name.cpp)

Create and read all members of a linked list by **shared pointer**: [Shared pointer](linked_list_shared_ptr.cpp). Unique pointer can't be used to traverse the linked list created by it.

Reverse a linked list
* Use stack: Put all member into a stack, then start popping them out (as LIFO) so that the last member of the linked list is now the first one
* Use recurive: [linked_list_reverse_linked_list_by_recursive.cpp](linked_list_reverse_linked_list_by_recursive.cpp)