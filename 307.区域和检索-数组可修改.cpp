/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

#include <vector>

class NumArray {
public:
    NumArray(std::vector<int>& nums) : nums_(std::move(nums)), line_tree_(nums_.size() * 4) {
        build_tree(0, 0, nums_.size() - 1);
    }
    
    void update(int index, int val) {
        nums_[index] = val;
        update_tree(index, 0);
    }
    
    int sumRange(int left, int right) {
        return sum_tree(0, left, right);
    }

private:
    struct Node {
        int left;
        int right;
        int sum;
    };
    std::vector<int> nums_;
    std::vector<Node> line_tree_;

    // node_idx: 线段树节点，即层序遍历二叉树的序号
    // left/right: 对应nums_的左右闭区间下标
    void build_tree(int node_idx, int left, int right) {
        line_tree_[node_idx].left = left;
        line_tree_[node_idx].right = right;
        if (left == right) {
            line_tree_[node_idx].sum = nums_[left];
            return;
        }
        auto mid = (left + right) / 2;
        build_tree(node_idx * 2 + 1, left, mid);
        build_tree(node_idx * 2 + 2, mid + 1, right);
        line_tree_[node_idx].sum = line_tree_[node_idx * 2 + 1].sum + line_tree_[node_idx * 2 + 2].sum;
    }

    void update_tree(int nums_idx, int node_idx) {
        auto& node = line_tree_[node_idx];
        if (node.left == node.right) {
            node.sum = nums_[nums_idx];
            return;
        }
        const auto& node_left = line_tree_[node_idx * 2 + 1];
        const auto& node_right = line_tree_[node_idx * 2 + 2];
        if (node_left.right >= nums_idx) {
            update_tree(nums_idx, node_idx * 2 + 1);
        } else {
            update_tree(nums_idx, node_idx * 2 + 2);
        }
        node.sum = node_left.sum + node_right.sum;
    }

    int sum_tree(int node_idx, int left, int right) {
        if (left == right) {
            return nums_[left];
        }
        const auto& node = line_tree_[node_idx];
        if (node.left == left && node.right == right) {
            return node.sum;
        }
        const auto& node_left = line_tree_[node_idx * 2 + 1];
        const auto& node_right = line_tree_[node_idx * 2 + 2];
        int result = 0;
        if (node_left.right >= left) {
            result += sum_tree(node_idx * 2 + 1, left, std::min(node_left.right, right));
        }
        if (node_right.left <= right) {
            result += sum_tree(node_idx * 2 + 2, std::max(node_right.left, left), right);
        }
        return result;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

