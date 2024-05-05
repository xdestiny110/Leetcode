/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start

#include <array>
#include <list>
#include <vector>

class MyHashSet {
public:
    static constexpr size_t capcity = 997;

    MyHashSet() {

    }
    
    void add(int key) {
        if (!contains(key))
            arr_[((key % capcity) + capcity) % capcity].push_back(key);
    }
    
    void remove(int key) {
        auto& bucket = arr_[((key % capcity) + capcity) % capcity];
        if (auto it = std::find(bucket.begin(), bucket.end(), key); it != bucket.end()) {
            bucket.erase(it);
        }
    }
    
    bool contains(int key) {
        const auto& bucket = arr_[((key % capcity) + capcity) % capcity];
        return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
    }

private:
    std::array<std::list<int>, capcity> arr_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

