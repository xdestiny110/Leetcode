/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        reverseNode(root);
        return root;
    }

private:
    void reverseNode(TreeNode* node) const{
        if(node->left != nullptr){
            reverseNode(node->left);
        }
        if(node->right != nullptr){
            reverseNode(node->right);
        }
        std::swap(node->left, node->right);
    }
};
// @lc code=end

