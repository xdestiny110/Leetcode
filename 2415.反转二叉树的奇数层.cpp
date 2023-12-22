/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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

#include <queue>

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) return root;
        std::queue<TreeNode*> current_layers;
        std::vector<TreeNode*> next_layers;
        current_layers.push(root);
        bool is_odd_layer = true;
        while (!current_layers.empty()) {
            while (!current_layers.empty()) {
                auto* node = current_layers.front();
                current_layers.pop();
                if (node->left != nullptr) {
                    next_layers.push_back(node->left);
                    next_layers.push_back(node->right);
                }
            }
            if (!next_layers.empty()) {
                if (is_odd_layer) {
                    for (auto it = next_layers.begin(), jt = next_layers.end() - 1; it < jt; ++it, --jt) {
                        std::swap((*it)->val, (*jt)->val);
                    }
                }
                is_odd_layer = !is_odd_layer;
                for (auto it = next_layers.begin(); it != next_layers.end(); ++it) {
                    current_layers.push(*it);
                }
                next_layers.clear();
            }            
        }
        return root;
    }
};
// @lc code=end

