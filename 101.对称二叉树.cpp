/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return (root == nullptr) || checkSymmetric(root->left, root->right);
    }
private:
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr)){
            return false;
        }
        if(left == nullptr && right == nullptr)
            return true;

        return (left->val == right->val) && checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
};
// @lc code=end

