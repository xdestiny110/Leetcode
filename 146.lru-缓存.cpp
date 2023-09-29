/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {

    }
    
    int get(int key) {
        if (p_.contains(key)) {
            auto v = p_[key]->second;
            update(key, v);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (p_.contains(key)) {
            update(key, value);
        } else {
            while (p_.size() >= capacity_) {
                p_.erase(cache_.front().first);
                cache_.pop_front();
            }
            update(key, value);
        }
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> cache_;
    std::unordered_map<int, decltype(cache_)::iterator> p_;

    void update(int key, int value) {
        if (p_.contains(key)) cache_.erase(p_[key]);
        cache_.push_back({key, value});
        p_[key] = cache_.end();
        std::advance(p_[key], -1);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

