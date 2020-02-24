/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

#include <algorithm>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return getTreeDepth(root, depth);
    }

private:
    bool getTreeDepth(TreeNode* root, int& depth ) const{
        if(root == nullptr){
            depth = 0;
            return true;
        }

        int leftDepth, rightDepth;
        auto flag = getTreeDepth(root->left, leftDepth);
        if(!flag)
            return false;
        flag &= getTreeDepth(root->right, rightDepth);
        depth = std::max(leftDepth, rightDepth) + 1;
        return  std::abs(leftDepth - rightDepth) <= 1 & flag;
    }
};
// @lc code=end

