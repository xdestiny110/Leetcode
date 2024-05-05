/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start

#include <array>
#include <list>

class MyHashMap {
public:
    static constexpr size_t kCapcity = 997;

    MyHashMap() {

    }
    
    void put(int key, int value) {
        auto& bucket = arr_[((key % kCapcity) + kCapcity % kCapcity)];
        if (auto it = std::find_if(bucket.begin(), bucket.end(), [key](const auto& kv) {
            return kv.first == key;
        }); it != bucket.end()) {
            it->second = value;
        } else {
            bucket.emplace_back(key, value);
        }
    }
    
    int get(int key) {
        auto& bucket = arr_[((key % kCapcity) + kCapcity % kCapcity)];
        if (auto it = std::find_if(bucket.begin(), bucket.end(), [key](const auto& kv) {
            return kv.first == key;
        }); it != bucket.end()) {
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) {
        auto& bucket = arr_[((key % kCapcity) + kCapcity % kCapcity)];
        if (auto it = std::find_if(bucket.begin(), bucket.end(), [key](const auto& kv) {
            return kv.first == key;
        }); it != bucket.end()) {
            bucket.erase(it);
        }
    }

private:
    std::array<std::list<std::pair<int, int>>, kCapcity> arr_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

