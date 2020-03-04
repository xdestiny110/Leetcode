/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

#include <stack>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        std::vector<int> v;
        std::stack<TreeNode*> s;
        std::unordered_set<long> r;
        s.push(root);
        while(!s.empty()){
            auto* t = s.top();
            if(r.find(reinterpret_cast<long>(t)) != r.end()){
                v.emplace_back(t->val);
                s.pop();
                continue;
            }
            if(t->right != nullptr){
                s.push(t->right);
            }
            if(t->left != nullptr){
                s.push(t->left);
            }
            r.insert(reinterpret_cast<long>(t));
        }
        return v;
    }
};
// @lc code=end

