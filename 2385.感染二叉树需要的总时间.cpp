/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
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

#include <unordered_set>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        calculate_parent(root);

        std::unordered_set<int> visited_node;
        std::queue<int> q, q_next;
        q.push(start);
        int time = 0;
        while (!q.empty()) {
            std::swap(q, q_next);
            while (!q_next.empty()) {
                auto node_idx = q_next.front();
                q_next.pop();
                visited_node.insert(node_idx);
                auto* node = node_map_[node_idx];
                if (node->left && !visited_node.contains(node->left->val)) {
                    q.push(node->left->val);
                }
                if (node->right && !visited_node.contains(node->right->val)) {
                    q.push(node->right->val);
                }
                if (node_parent_.contains(node->val) && !visited_node.contains(node_parent_[node->val])) {
                    q.push(node_parent_[node->val]);
                }
            }
            time++;
        }
        return time - 1;        
    }

private:
    std::unordered_map<int, int> node_parent_;
    std::unordered_map<int, TreeNode*> node_map_;

    void calculate_parent(TreeNode* node) {
        node_map_[node->val] = node;
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }
        if (node->left) {
            calculate_parent(node->left);
            node_parent_[node->left->val] = node->val;
        }
        if (node->right) {
            calculate_parent(node->right);
            node_parent_[node->right->val] = node->val;
        }
    }
};
// @lc code=end

