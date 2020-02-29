/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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

#include <string>

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        DFS(root, "");
        return sum;
    }

private:
    unsigned long long sum = 0;
    void DFS(TreeNode* root, std::string&& s){

        s.insert(s.end(), root->val + '0');
        if(root->left != nullptr){
            DFS(root->left, std::move(s));
        }
        if(root->right != nullptr){
            DFS(root->right, std::move(s));
        }
        if(root->left == nullptr && root->right == nullptr){
            sum += std::stoull(s);
        }
        s.erase(s.end() - 1);
    }
};
// @lc code=end

