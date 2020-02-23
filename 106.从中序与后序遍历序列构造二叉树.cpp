/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <algorithm>

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode* buildTree(std::vector<int>::const_iterator inorderStart, std::vector<int>::const_iterator inorderEnd, std::vector<int>::const_iterator postorderStart, std::vector<int>::const_iterator postorderEnd) const{
        if(std::distance(inorderStart, inorderEnd) == 0)
            return nullptr;

        auto* root = new TreeNode(*(postorderEnd - 1));
        if(std::distance(inorderStart, inorderEnd) == 1)
            return root;

        auto it = std::find(inorderStart, inorderEnd, *(postorderEnd-1));
        auto* leftRoot = buildTree(inorderStart, it, postorderStart, postorderStart + std::distance(inorderStart, it));
        auto* rightRoot = buildTree(it + 1, inorderEnd, postorderStart + std::distance(inorderStart, it), postorderEnd - 1);
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }
};
// @lc code=end

