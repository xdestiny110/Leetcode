/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int cnt = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            auto* n = q.front();
            q.pop();
            cnt++;
            if(n->left != nullptr) q.push(n->left);
            if(n->right != nullptr) q.push(n->right);
        }
        
        return cnt;
    }
};
// @lc code=end

