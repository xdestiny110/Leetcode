/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
class Solution {
public:
    int rob(TreeNode* root) {
        auto t = robImpl(root);
        return std::max(t.first, t.second);
    }

private:
    std::pair<int, int> robImpl(TreeNode* node) const {
        if (node == nullptr) {
            return {0, 0};
        }
        std::pair<int, int> result = {node->val, 0};
        auto t = robImpl(node->left);
        result.first += t.second;
        result.second += std::max(t.first, t.second);
        t = robImpl(node->right);
        result.first += t.second;
        result.second += std::max(t.first, t.second);
        return result;
    }
};
// @lc code=end

