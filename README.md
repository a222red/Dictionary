# Dictionary
A recreation of Python's dict class in C++
## Usage
The classes `dict` and pair are templates:
```cpp
template<key_type, val_type>
class dict;
template<key_type, val_type>
class pair;
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
std::vector<pair<key_type, val_type>> items()
```
Return a vector containing every key-value pair in the dict

---

```cpp
void clear()
```
Remove all key-value pairs in the dict

---

```cpp
pair<key_type, val_type> pop_item()
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

---

```cpp
key_type& index_key(int i)
```
Return a reference to a key by its index

---

```cpp
val_type& index_value(int i)
```
Return a reference to a value by its index

---

```cpp
int len()
```
Return the amount of items in the dict
