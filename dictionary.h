#include <iostream>
#include <vector>
#include <algorithm>

class dict {
    protected:
    std::vector<std::string> keys;
    std::vector<std::string> vals;
    public:
    std::string pop(std::string key) {
        std::string val = vals[std::find(keys.begin(),keys.end(),key)-keys.begin()];
        keys.erase(std::find(keys.begin(),keys.end(),key));
        vals.erase(std::find(vals.begin(),vals.end(),val));
        return val;
    }
    std::string& operator[](std::string key) {
        if (std::find(keys.begin(),keys.end(),key) == keys.end()) {
            keys.push_back(key);
            vals.push_back("");
        }
        return vals[std::find(keys.begin(),keys.end(),key)-keys.begin()];
    }
    dict& operator+(dict d) {
        keys.insert(keys.end(),d.keys.begin(),d.keys.end());
        vals.insert(vals.end(),d.vals.begin(),d.vals.end());
        return *this;
    }
    std::vector<std::vector<std::string>> items() {
        std::vector<std::vector<std::string>> v;
        std::vector<std::string> s;
        for (int i = 0; i < keys.end()-keys.begin(); ++i) {
            s[0] = keys[i];
            s[1] = vals[i];
            v.push_back(s);
        }
        return v;
    }
    void clear() {
        keys = {};
        vals = {};
    }
    std::vector<std::string> popitem() {
        std::vector<std::string> item = {keys[keys.end()-keys.begin()-1],vals[vals.end()-vals.begin()-1]};
        keys.pop_back();
        vals.pop_back();
        return item;
    }
    std::vector<std::string> list_keys() {
        return keys;
    }
    std::vector<std::string> list_values() {
        return vals;
    }
    std::string& get_key_by_value(std::string val) {
        return keys[std::find(vals.begin(),vals.end(),val)-vals.begin()];
    }
};
