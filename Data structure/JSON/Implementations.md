# Create and read a JSON object

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

Create by ``["field_name"]`` and read by ``for`` loop:

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
# Read JSON element

## Read all key and value using for loop:

Like impmenented above on [create operation]():

```cpp
for (auto& el : json_obj.items()) {
        std::cout << el.key() << " : " << el.value() << "\n";
}
```

## value()

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

## Get JSON element's type

Use this comparison method (``==``) as a way to get JSON element's type

```cpp
json json_obj = {
    {"name","Username"},
    {"id",123}
};

std::cout << (json_obj["name"].type() == json::value_t::string) << std::endl;//1
std::cout << (json_obj["id"].type() == json::value_t::number_integer) << std::endl;//1
```
``type()`` can't be gotten by ``cout``. This will cause error

```cpp
std::cout << json_obj["name"].type() << std::endl;
```

**Error**

```
‘std::ostream’ {aka ‘std::basic_ostream<char>’} is not derived from ‘const std::valarray<_Tp>’
```

## Read array as JSON element

Must use array type read:

```cpp
json json_obj = {
        {"array", {1, 2, 3, 4}}
};


int val = json_obj["array"][0];
std::cout << "val: " << val << std::endl;//1
```

``value()`` can't be used to read as it has operator-overloading error:

```cpp
//This will cause error
int val = json_obj.value("array", 123)[0];
```
**Error**
```
error: invalid types ‘int[int]’ for array subscript
```

## Read the whole JSON from a file

```cpp
#include <fstream>

std::fstream fileStream("config.json");
json json_obj = json::parse(fileStream);
std::cout << json_obj << std::endl;//Print out the whole JSON object
```    
# Update JSON element

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