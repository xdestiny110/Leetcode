/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
#include <stack>

class Solution {
public:
    int goodNodes(TreeNode* root) {
        std::stack<int> s;
        dfs(root, s);
        return result;
    }

private:
    int result = 0;

    void dfs(TreeNode* node, std::stack<int>& s) {
        if (s.empty() || node->val >= s.top()) {
            result++;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }
        s.push((s.empty() || node->val >= s.top()) ? node->val : s.top());
        if (node->left != nullptr) {
            dfs(node->left, s);
        }
        if (node->right != nullptr) {
            dfs(node->right, s);
        }
        s.pop();
    }
};
// @lc code=end

