/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        DFS(root);
    }

private:
    void DFS(TreeNode* root){
        if(root->left != nullptr){
            DFS(root->left);
        }
        if(root->right != nullptr){
            DFS(root->right);
        }
        if(root->left != nullptr){
            auto t = root->right;
            root->right = root->left;
            auto rightNode = root->right;
            while(rightNode->right != nullptr) rightNode = rightNode->right;
            rightNode->right = t;
            root->left = nullptr;
        }        
    }
};
// @lc code=end

