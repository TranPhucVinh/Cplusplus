Use [nlohmann/json](https://github.com/nlohmann/json) library.

Install on Ubuntu 20.04

```sh
sudo apt-get install nlohmann-json3-dev
```

# Implementation

## Create and read a JSON object

Create by [initializer lists](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/Function%20and%20variables#initializer-list):

```c
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    json json_obj = {
        {"name","Username"},
        {"id",123}
    };

    std::string name = json_obj["name"];
    int id = json_obj["id"];

    std::cout << json_obj << std::endl;//Print out the whole JSON object
    std::cout << "name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;           
    return 0;
}
```
**Result**
```
{"id":123,"name":"Username"}
name: Username
ID: 123
```

Create by array type:

```cpp
json json_obj;

json_obj["name"] = "Hello, World !";
json_obj["id"] = 123;

for (auto& el : json_obj.items()) {
    std::cout << el.key() << " : " << el.value() << "\n";
}

//The JSON element can be print out normally with array like this:
// std::cout << "name: " << json_obj["name"] << std::endl;
// std::cout << "ID: " << json_obj["id"] << std::endl;           
```
## Read JSON element by key

Read JSON element by key with ``value()``. If that read key not existed, return the default value.

```cpp
json json_obj = {
    {"name","Username"},
    {"id",123}
};

std::string name = json_obj.value("name", "Default string");
int id = json_obj.value("id", 456);
int not_existed_id = json_obj.value("not_existed_id", 789);

std::cout << "name: " << name << std::endl;
std::cout << "ID: " << id << std::endl;           
std::cout << "Not existed JSON element will be printed out with default value:" << not_existed_id << std::endl;           
```
**Result**
```
name: Username
ID: 123
Not existed JSON element will be printed out with default value:789
```

Read the whole JSON from a file

```cpp
#include <fstream>

std::fstream fileStream("config.json");
json json_obj = json::parse(fileStream);
std::cout << json_obj << std::endl;//Print out the whole JSON object
```    

## Update JSON element

Using array key:

```cpp
json json_obj = {
    {"name","Username"},
    {"id",123}
};

std::cout << json_obj << std::endl;

json_obj["name"] = "New string value";
json_obj["id"] = 456;

std::cout << json_obj << std::endl;
```
**Result**
```
{"id":123,"name":"Username"}
{"id":456,"name":"New string value"}
```

Getting JSON value by array with key can't be used for operator (e.g ``+``, ``-``,...):

```cpp
json json_obj = {
    {"name","Username"},
    {"id",123}
};

int id = json_obj["id"] + 1;
```
**Result**: This will be error

```
main.cpp:14:31: note:   mismatched types ‘const std::_Expr<_Dom1, typename _Dom1::value_type>’ and ‘int’
   14 |     int id = json_obj["id"] + 1;
```

Getting JSON value by ``value()`` can be used for operator normally:

```cpp
//This work normally
json json_obj = {
    {"name","Username"},
    {"id",123}
};
int id = json_obj.value("id", 456) + 1;//id will be 124
```

# API

### items(), key() and value()

```cpp
iteration_proxy<iterator> items() noexcept;
iteration_proxy<const_iterator> items() const noexcept;
```

This function allows accessing iterator::key() and iterator::value() during range-based for loops. In these loops, a reference to the JSON values is returned, so there is no access to the underlying iterator.

### ValueType value()

```cpp
template<class ValueType>
ValueType value(const typename object_t::key_type& key, ValueType&& default_value) const;
```

Returns either a copy of an object's element at the specified key key or a given default value if no element with key key exists.

The function is basically equivalent to executing:

```cpp
try {
   return at(key);
} catch(out_of_range) {
   return default_value;
}
```
