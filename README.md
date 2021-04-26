# Dictionary
A recreation of Python's dict class in C++
## Usage
Usage is similar to Python:
```cpp
dict d;
d["foo"] = "bar"
```
## Methods
```cpp
std::string pop(std::string key)
```
Remove an item from from the dict and return its value
---
```cpp
std::vector<std::vector<std::string>> items()
```
Return a vector containing every key-value pair in the dict
---
```cpp
void clear()
```
Remove all key-value pairs in the dict
---
```cpp
std::vector<std::string> popitem()
```
Remove the most recently added key-value pair andd return it as a vector
---
```cpp
std::vector<std::string> list_keys()
```
Return a vector containing all keys in the dict
---
```cpp
std::vector<std::string> list_values()
```
Return a vector containing all values in the dict
---
```cpp
std::string& get_key_by_value(std::string val)
```
Return a reference to a key by its value
