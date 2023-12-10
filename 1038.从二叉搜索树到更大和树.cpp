/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr) return root;
        dfs(root);
        return root;
    }

private:
    int current_sum_ = 0;

    void dfs(TreeNode* node) {
        if (node->right != nullptr) {
            dfs(node->right);
        }
        node->val += current_sum_;
        current_sum_ = node->val;
        if (node->left != nullptr) {
            dfs(node->left);
        }
    }

};
// @lc code=end

