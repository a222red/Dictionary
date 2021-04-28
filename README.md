# Dictionary
A recreation of Python's dict class in C++
## Usage
The class `dict` is a template:
```cpp
template<key_type, val_type>
class dict
```
Usage is similar to Python:
```cpp
dict<string,string> d;
d["foo"] = "bar";
```
## Methods
```cpp
val_type pop(key_type key)
```
Remove an item from from the dict and return its value

---

```cpp
std::vector<std::pair<key_type, val_type>> items()
```
Return a vector containing every key-value pair in the dict

---

```cpp
void clear()
```
Remove all key-value pairs in the dict

---

```cpp
std::pair<key_type, val_type> pop_item()
```
Remove the most recently added key-value pair andd return it as a vector

---

```cpp
std::vector<key_type> list_keys()
```
Return a vector containing all keys in the dict

---

```cpp
std::vector<val_type> list_values()
```
Return a vector containing all values in the dict

---

```cpp
key_type& get_key_by_value(val_type val)
```
Return a reference to a key by its value
