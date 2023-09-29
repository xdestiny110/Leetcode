/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <unordered_map>
#include <list>

struct Node {
    int key_;
    int value_;
    int use_count_;
};

class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_use_count_(0) {

    }
    
    int get(int key) {
        if (k_it.contains(key)) {
            auto n = *k_it[key];
            count_nodes[n.use_count_].erase(k_it[key]);
            if (count_nodes[n.use_count_].empty()) {
                count_nodes.erase(n.use_count_);
                if (min_use_count_ == n.use_count_) {
                    min_use_count_++;
                }
            }
            n.use_count_++;
            count_nodes[n.use_count_].push_front(n);
            k_it[key] = count_nodes[n.use_count_].begin();
            return n.value_;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (k_it.contains(key)) {
            auto n = *k_it[key];
            count_nodes[n.use_count_].erase(k_it[key]);
            if (count_nodes[n.use_count_].empty()) {
                count_nodes.erase(n.use_count_);
                if (min_use_count_ == n.use_count_) {
                    min_use_count_++;
                }
            }
            n.use_count_++;
            n.value_ = value;
            count_nodes[n.use_count_].push_front(n);
            k_it[key] = count_nodes[n.use_count_].begin();
        } else {
            if (k_it.size() == capacity_) {
                auto n = count_nodes[min_use_count_].back();
                count_nodes[min_use_count_].pop_back();
                k_it.erase(n.key_);
            }
            count_nodes[1].push_front(Node{
                .key_ = key,
                .value_ = value,
                .use_count_ = 1,
            });
            k_it[key] = count_nodes[1].begin();
            min_use_count_ = 1;
        }
    }

private:
    int capacity_;
    std::unordered_map<int, std::list<Node>> count_nodes;
    std::unordered_map<int, decltype(count_nodes)::mapped_type::iterator> k_it;
    int min_use_count_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

