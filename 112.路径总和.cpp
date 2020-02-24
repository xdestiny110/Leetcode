/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

#include <queue>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        std::queue<std::pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.push(std::make_pair(root, 0));
        }
        while(!q.empty()){
            auto [node, val] = q.front();
            if(node->left == nullptr && node->right == nullptr && val + node->val == sum){
                return true;
            }
            if(node->left != nullptr){
                q.push(std::make_pair(node->left, val + node->val));
            }
            if(node->right != nullptr){
                q.push(std::make_pair(node->right, val + node->val));
            }
            q.pop();
        }

        return false;
    }
};
// @lc code=end

