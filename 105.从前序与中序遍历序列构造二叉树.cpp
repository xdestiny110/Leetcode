/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty()){
            return nullptr;
        }

        auto* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1){
            return root;
        }

        auto it = std::find(inorder.begin(), inorder.end(), preorder[0]);
        TreeNode* leftRoot = nullptr;
        TreeNode* rightRoot = nullptr;
        if(it != inorder.end()){
            std::vector<int> leftTreeInorder(inorder.begin(), it);
            std::vector<int> leftTreePreorder(preorder.begin() + 1, preorder.begin() + 1 + leftTreeInorder.size());
            leftRoot = buildTree(leftTreePreorder, leftTreeInorder);

            std::vector<int> rightTreeInorder(it + 1, inorder.end());
            std::vector<int> rightTreePreorder(preorder.begin() + 1 + leftTreeInorder.size(), preorder.end());
            rightRoot = buildTree(rightTreePreorder, rightTreeInorder);
        }
        
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }
};
// @lc code=end

