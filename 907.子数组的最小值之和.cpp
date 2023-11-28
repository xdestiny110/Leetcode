/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        arr_ = std::move(arr);
        seg_tree_.resize(arr_.size() * 4);
        build_seg_tree(0, 0, arr_.size() - 1);

        int result = 0;
        constexpr int mod = 1e9 + 7;
        for (int left = 0; left < arr_.size(); ++left) {
            for (int right = left; right < arr_.size(); ++right) {
                result = (result % mod + find_min(0, left, right) % mod) % mod;
            }
        }
        return result;
    }

private:
    struct Node {
        size_t left_;
        size_t right_;
        int min_;
    };

    std::vector<int> arr_;
    std::vector<Node> seg_tree_;

    void build_seg_tree(size_t seg_tree_idx, size_t left, size_t right) {
        if (left == right) {
            seg_tree_[seg_tree_idx] = Node {
                .left_ = left,
                .right_ = right,
                .min_ = arr_[left],
            };  
            return;
        }

        auto mid = (left + right) / 2;
        build_seg_tree(seg_tree_idx * 2 + 1, left, mid);
        build_seg_tree(seg_tree_idx * 2 + 2, mid + 1, right);
        seg_tree_[seg_tree_idx] = Node {
            .left_ = left,
            .right_ = right,
            .min_ = std::min(seg_tree_[seg_tree_idx * 2 + 1].min_, seg_tree_[seg_tree_idx * 2 + 2].min_),
        };
    }

    int find_min(size_t seg_tree_idx, size_t left, size_t right) const {
        if (seg_tree_[seg_tree_idx].left_ == left && seg_tree_[seg_tree_idx].right_ == right) {
            return seg_tree_[seg_tree_idx].min_;
        }
        int result_left = std::numeric_limits<int>::max();
        int result_right = std::numeric_limits<int>::max();
        if (seg_tree_[seg_tree_idx * 2 + 1].right_ >= left) {
            result_left = find_min(seg_tree_idx * 2 + 1, left, std::min(seg_tree_[seg_tree_idx * 2 + 1].right_, right));
        }
        if (seg_tree_[seg_tree_idx * 2 + 2].left_ <= right) {
            result_right = find_min(seg_tree_idx * 2 + 2, std::max(left, seg_tree_[seg_tree_idx * 2 + 2].left_), right);
        }
        return std::min(result_left, result_right);
    }
};
// @lc code=end

