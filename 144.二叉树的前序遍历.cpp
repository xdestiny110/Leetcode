/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        std::vector<int> v;
        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto* t = s.top();
            s.pop();
            v.emplace_back(t->val);
            if(t->right != nullptr){
                s.push(t->right);
            }
            if(t->left != nullptr){
                s.push(t->left);
            }
        }
        return v;
    }
};
// @lc code=end

