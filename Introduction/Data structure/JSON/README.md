Use [nlohmann/json](https://github.com/nlohmann/json) library.

Install on Ubuntu 20.04

```sh
sudo apt-get install nlohmann-json3-dev
```

# Implementations


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
