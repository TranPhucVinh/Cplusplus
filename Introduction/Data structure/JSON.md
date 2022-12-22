Use [nlohmann/json](https://github.com/nlohmann/json) library.

Install on Ubuntu 20.04

```sh
sudo apt-get install nlohmann-json3-dev
```

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

## API

### items(), key() and value()

```cpp
iteration_proxy<iterator> items() noexcept;
iteration_proxy<const_iterator> items() const noexcept;
```

This function allows accessing iterator::key() and iterator::value() during range-based for loops. In these loops, a reference to the JSON values is returned, so there is no access to the underlying iterator.
