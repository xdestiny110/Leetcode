/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
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

#include <queue>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<>> q;
        std::queue<TreeNode*> current_layer, next_layer;
        if (!root) return -1;
        current_layer.push(root);
        long long sum = 0;
        while (!current_layer.empty()) {
            auto node = current_layer.front();
            current_layer.pop();
            if (node->left) next_layer.push(node->left);
            if (node->right) next_layer.push(node->right);
            sum += node->val;
            if (current_layer.empty()) {
                q.push(sum);
                if (q.size() > k) {
                    q.pop();
                }
                sum = 0;
                std::swap(current_layer, next_layer);
            }
        }
        return q.size() == k ? q.top() : -1;
    }
};
// @lc code=end

