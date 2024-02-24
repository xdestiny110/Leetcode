/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> closestNodes(TreeNode* root, std::vector<int>& queries) {
        if (root) warmup(root);
        std::vector<std::vector<int>> result(queries.size(), std::vector<int>(2, -1));
        for (int i = 0; i < queries.size(); ++i) {
            auto it = std::lower_bound(sorted_node.begin(), sorted_node.end(), queries[i]);
            if (it != sorted_node.end()) {
                result[i][1] = *it;
                if (*it == queries[i]) {
                    result[i][0] = *it;
                    continue;
                }
            }
            if (it != sorted_node.begin()) {
                it--;
                result[i][0] = *it;
            }
        }
        return result;
    }

private:
    std::vector<int> sorted_node;
    void warmup(TreeNode* node) {
        if (node->left) {
            warmup(node->left);
        }
        sorted_node.push_back(node->val);
        if (node->right) {
            warmup(node->right);
        }
    }
};
// @lc code=end

