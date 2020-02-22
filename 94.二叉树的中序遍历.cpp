/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return ret;
        DFS(root);
        return ret;
    }
private:
    std::vector<int> ret;
    void DFS(TreeNode* node){
        if(node->left != nullptr)
            DFS(node->left);
        ret.emplace_back(node->val);
        if(node->right != nullptr)
            DFS(node->right);
    }
};
// @lc code=end

