#include <vector>
#include <algorithm>
#include <utility>

template<typename key_type, typename val_type>
class dict {
    protected:
    std::vector<key_type> keys;
    std::vector<val_type> vals;
    public:
    val_type pop(key_type key) {
        key_type val = vals[std::find(keys.begin(),keys.end(),key)-keys.begin()];
        keys.erase(std::find(keys.begin(),keys.end(),key));
        vals.erase(std::find(vals.begin(),vals.end(),val));
        return val;
    }
    val_type& operator[](key_type key) {
        if (std::find(keys.begin(),keys.end(),key) == keys.end()) {
            keys.push_back(key);
            vals.push_back(val_type());
        }
        return vals[std::find(keys.begin(),keys.end(),key)-keys.begin()];
    }
    dict& operator+(dict d) {
        keys.insert(keys.end(),d.keys.begin(),d.keys.end());
        vals.insert(vals.end(),d.vals.begin(),d.vals.end());
        return *this;
    }
    std::vector<std::pair<key_type, val_type>> items() {
        std::vector<std::pair<key_type, val_type>> v;
        std::pair<key_type, val_type> s;
        for (int i = 0; i < keys.end()-keys.begin(); ++i) {
            s.first = keys[i];
            s.second = vals[i];
            v.push_back(s);
        }
        return v;
    }
    void clear() {
        keys = {};
        vals = {};
    }
    std::pair<key_type, val_type> popitem() {
        std::pair<key_type, val_type> item;
        item.first = keys[keys.end()-keys.begin()-1];
        item.second = vals[vals.end()-vals.begin()-1];
        keys.pop_back();
        vals.pop_back();
        return item;
    }
    std::vector<key_type> list_keys() {
        return keys;
    }
    std::vector<val_type> list_values() {
        return vals;
    }
    key_type& get_key_by_value(key_type val) {
        return keys[std::find(vals.begin(),vals.end(),val)-vals.begin()];
    }
};
