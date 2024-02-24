/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <queue>
#include <numeric>

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::deque<std::pair<TreeNode*, uint32_t>> current_lv, next_lv;
        int current_lv_sum = 0;
        next_lv.push_back({root, root->val});
        for (;;) {
            if (current_lv.empty()) {
                current_lv_sum = std::accumulate(next_lv.begin(), next_lv.end(), 0, [](uint32_t sum, const std::pair<TreeNode*, uint32_t>& n) {
                    return sum + n.first->val;
                });
                std::swap(current_lv, next_lv);
            }
            if (current_lv.empty()) {
                break;
            }
            auto n = current_lv.front();
            current_lv.pop_front();
            n.first->val = current_lv_sum - n.second;
            uint32_t children_sum = n.first->left ? n.first->left->val : 0;
            children_sum = n.first->right ? children_sum + n.first->right->val : children_sum;
            if (n.first->left) {
                next_lv.push_back({n.first->left, children_sum});
            }
            if (n.first->right) {
                next_lv.push_back({n.first->right, children_sum});
            }
        }
        return root;
    }
};
// @lc code=end

