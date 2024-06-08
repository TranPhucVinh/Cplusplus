A container, in CPP, is a holder object that stores a collection of other objects (its elements). The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators.

**Sequence containers** implement data structures that can be accessed sequentially. 

There are 5 sequence containers implemented in STL:

* array: Static contiguous array (class template)
* vector: Dynamic contiguous array (class template)
* deque: Double-ended queue (class template)
* forward_list: Singly-linked list (class template)
* list: Doubly-linked list (class template)

**Container adapters** provide a different interface for sequential containers. 

There are 3 container adapter implemented in STL:
* stack: Adapts a container to provide stack (LIFO data structure) (class template).
* queue: Adapts a container to provide queue (FIFO data structure) (class template).
* priority_queue: Adapts a container to provide priority queue (class template). 

**Associative containers** implement sorted data structures that can be quickly searched (O(log n) complexity).

**Unordered associative** containers implement unsorted (hashed) data structures that can be quickly searched