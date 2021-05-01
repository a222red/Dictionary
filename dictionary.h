#ifndef PY_DICT
#define PY_DICT

#include <vector>
#include <algorithm>

template<typename key_type, typename val_type>
class pair {
  public:
  key_type key;
  val_type val;
};

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
    dict& operator+(dict<key_type,val_type> d) {
        keys.insert(keys.end(),d.keys.begin(),d.keys.end());
        vals.insert(vals.end(),d.vals.begin(),d.vals.end());
        return *this;
    }
    std::vector<pair<key_type, val_type>> items() {
        std::vector<pair<key_type, val_type>> v;
        pair<key_type, val_type> s;
        for (int i = 0; i < keys.end()-keys.begin(); ++i) {
            s.key = keys[i];
            s.val = vals[i];
            v.push_back(s);
        }
        return v;
    }
    void clear() {
        keys = {};
        vals = {};
    }
    pair<key_type, val_type> pop_item() {
        pair<key_type, val_type> item;
        item.key = keys[keys.end()-keys.begin()-1];
        item.val = vals[vals.end()-vals.begin()-1];
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
    key_type& index_key(int i) {
        return keys[i];
    }
    val_type& index_value(int i) {
        return vals[i];
    }
    int len() {
        return keys.end()-keys.begin();
    }
};

#endif
