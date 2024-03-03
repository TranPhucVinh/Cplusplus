[Fundamental concepts](Fundamental%20concepts.md) include:
* [Definition of class](Fundamental%20concepts.md#what-is-class-), [define variable and function for a class](Fundamental%20concepts.md#define-variable-and-function-for-a-class), [types of variables in class](Fundamental%20concepts.md#types-of-class-variables)
* [Method of class](Method%20of%20class.md): [Private method](), [non-static member methods]() and [static member methods]()
* [Encapsulation](#encapsulation)
* [Constructor and destructor](Constructor%20and%20destructor): Constructor overloading, default keyword
* [this pointer](Documents/this%20pointer.md)
* [Inheritance](Inheritance): [Basic inheritance example as polymorphism](Inheritance/README.md#basic-inheritance-example), [generalization](Inheritance/README.md#generalization), [protect method](Inheritance/README.md#protect-method), [Header files with class and public method](Inheritance#header-files-with-class-and-public-method), [multilevel inheritance]() and [multiple inheritance]()
* [Virtual function](Inheritance/Virtual%20function.md): [When to use virtual function ?](Inheritance/Virtual%20function.md#when-to-use-virtual-function-), [virtual function definition](Virtual%20function.md#virtual-function-definition) and [implementation](Inheritance/Virtual%20function.md#implementation), [override keyword](Inheritance/Virtual%20function.md#override-keyword), [virtual destructor](Inheritance/Virtual%20function.md#virtual-destructor), [pure virtual function and abstract class](Inheritance/Virtual%20function.md#pure-virtual-function-and-abstract-class)
* [Binding](#binding): [Early binding]() and [late binding]()
* [const](const.md): [const function](const.md#const-function), [const object](const.md#const-object) and [mutable](const.md#mutable)
* [friend](friend.md): [friend class](friend.md#friend-class), [friend function](friend.md#friend-function): Use [a global function](friend.md#use-a-global-function-as-a-friend-method-to-change-public-and-private-member-of-an-object) and [a class method](friend.md#use-a-class-method-as-a-friend-method-to-change-public-and-private-member-of-an-object) as a friend method to change public and private member of an object.

[Example](Example)

# Encapsulation
Encapsulation is defined as the wrapping up of data and information in a single unit. 

We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class. 

The function which we are making inside the class must use only member variables, only then it is called encapsulation.

Encapsulation will help increasing the security of data.

# Binding

Binding refers to the process of converting identifiers (such as variable and performance names) into addresses. Binding is done for each variable and functions. For functions, it means that matching the call with the right function definition by the compiler. It takes place either at compile time or at runtime.

**Early binding (compile-time time polymorphism)**: In early binding, compiler (or linker) directly associate an address to the function call. C++ uses early binding by default. 

**Late binding (run time polymorphism)**: In late binding, the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition. This can be achieved by declaring a [virtual function]().

# [Singleton](Singleton.md)
