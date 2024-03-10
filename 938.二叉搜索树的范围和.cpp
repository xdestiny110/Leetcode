/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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

#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        if (root) {
            dfs(root);
            auto low_it = std::lower_bound(sorted_.begin(), sorted_.end(), low);
            auto high_it = std::lower_bound(sorted_.begin(), sorted_.end(), high);
            for (auto it = low_it; it != high_it; ++it) {
                result += *it;
            }
            if (high_it != sorted_.end() && *high_it == high) {
                result += high;
            }
        }
        return result;
    }

private:
    std::vector<int> sorted_;
    void dfs(TreeNode* node) {
        if (node->left != nullptr)
            dfs(node->left);
        sorted_.push_back(node->val);
        if (node->right != nullptr)
            dfs(node->right);
    }
};
// @lc code=end

