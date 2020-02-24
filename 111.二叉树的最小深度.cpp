/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <tuple>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        std::queue<std::tuple<TreeNode*, int>> q;
        q.push(std::make_tuple(root, 1));
        while(!q.empty()){
            auto [node, layer] = q.front();
            if(node->left == nullptr && node->right == nullptr){
                return std::get<1>(q.front());
            }
            if(node->left != nullptr){
                q.push(std::make_tuple(node->left, layer + 1));
            }
            if(node->right != nullptr){
                q.push(std::make_tuple(node->right, layer + 1));
            }
            q.pop();
        }
        return 0;
    }
};
// @lc code=end

