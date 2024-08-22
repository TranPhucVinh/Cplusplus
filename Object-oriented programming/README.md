[Fundamental concepts](Documents/Fundamental%20concepts.md) include:
* [Definition of class](Documents/Fundamental%20concepts.md#what-is-class-), [define variable and function for a class](Documents/Fundamental%20concepts.md#define-variable-and-function-for-a-class-use-class-object-as-a-pointer), [types of variables in class](Documents/Fundamental%20concepts.md#types-of-class-variables); [struct](Documents/Fundamental%20concepts.md#struct)
* [Method of class](Documents/Method%20of%20class.md): [Private method](), [non-static member methods]() and [static member methods]()
* [Encapsulation](#encapsulation)
* [Constructor and destructor](Constructor%20and%20destructor): Constructor overloading, default keyword
* [this pointer](Documents/this%20pointer.md)
* [Inheritance](Documents/Inheritance): [Basic inheritance example as polymorphism](Inheritance/README.md#basic-inheritance-example), [generalization](Inheritance/README.md#generalization), [protect method](Inheritance/README.md#protect-method), [Header files with class and public method](Inheritance#header-files-with-class-and-public-method), [multilevel inheritance]() and [multiple inheritance]()
* [Virtual function](Documents/Inheritance/Virtual%20function.md): [When to use virtual function ?](Inheritance/Virtual%20function.md#when-to-use-virtual-function-), [virtual function definition](Virtual%20function.md#virtual-function-definition) and [implementation](Inheritance/Virtual%20function.md#implementation), [override keyword](Documents/Inheritance/Virtual%20function.md#override-keyword), [virtual destructor](Inheritance/Virtual%20function.md#virtual-destructor), [pure virtual function and abstract class](Inheritance/Virtual%20function.md#pure-virtual-function-and-abstract-class)
* [Binding](#binding): [Early binding]() and [late binding]()
* [const](Documents/const.md): [const function](Documents/const.md#const-function), [const object](Documents/const.md#const-object) and [mutable](Documents/const.md#mutable)
* [Operator overloading](Documents/Operator%20overloading.md)
* [friend](friend.md): [friend class](Documents/friend.md#friend-class), [friend function](friend.md#friend-function): Use [a global function](friend.md#use-a-global-function-as-a-friend-method-to-change-public-and-private-member-of-an-object) and [a class method](friend.md#use-a-class-method-as-a-friend-method-to-change-public-and-private-member-of-an-object) as a friend method to change public and private member of an object.

**Simple class exmaple**: Build a class which includes:
* Constructor ``class_constructor()``
* Public function ``add_number(int int_param)`` to add the passed parameter ``int_param`` with ``_int_param ``, a private variable

* [example_header.h](src/example_header.h)
* [example_header.cpp](src/example_header.cpp)
* [example_main.cpp](src/example_main.cpp)

# Encapsulation
Encapsulation is defined as the wrapping up of data and information in a single unit. 

We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class. 

The function which we are making inside the class must use only member variables, only then it is called encapsulation.

Encapsulation will help increasing the security of data.

# Binding

Binding refers to the process of converting identifiers (such as variable and performance names) into addresses. Binding is done for each variable and functions. For functions, it means that matching the call with the right function definition by the compiler. It takes place either at compile time or at runtime.

**Early binding (compile-time time polymorphism)**: In early binding, compiler (or linker) directly associate an address to the function call. C++ uses early binding by default. 

**Late binding (run time polymorphism)**: In late binding, the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition. This can be achieved by declaring a [virtual function]().

# Singleton

A **singleton class** is a class which can have only one object or instance at a time. In other words, **we can instantiate only one instance of the singleton class**. The new variable also points to the initial instance created if we attempt to instantiate the Singleton class after the first time.

**Program**: [singleton.cpp](src/singleton.cpp)

# Class for communication protocol message
* [Parse a communication protocol message by reinterpret_cast a class object](src/parse_protocol_msg_by_reinterpret_cast.cpp)
