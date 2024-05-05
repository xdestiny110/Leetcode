/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start

#include <algorithm>
#include <vector>

class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr_.resize(length, std::vector<std::pair<size_t, int>>(1, {0, 0}));
    }
    
    void set(int index, int val) {
        auto it = std::lower_bound(arr_[index].begin(), arr_[index].end(), snap_id_, [](const std::pair<int, size_t>& a, size_t v) {
            return a.first < v;
        });
        if (it == arr_[index].end()) {
            arr_[index].emplace_back(snap_id_, val);
        } else {
            it->second = val;
        }
    }
    
    int snap() {
        snap_id_++;
        return snap_id_ - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = std::lower_bound(arr_[index].begin(), arr_[index].end(), snap_id, [](const std::pair<int, size_t>& a, size_t v) {
            return a.first < v;
        });
        if (it == arr_[index].end() || it->first != snap_id) {
            it = std::prev(it);
        }
        return it->second;
    }

private:
    std::vector<std::vector<std::pair<size_t, int>>> arr_;
    size_t snap_id_ = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

