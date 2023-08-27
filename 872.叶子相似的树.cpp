/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        tree_iter(root1, leaf1);
        tree_iter(root2, leaf2);
        if (leaf1.size() != leaf2.size())
            return false;
        for (size_t i = 0; i < leaf1.size(); ++i) {
            if (leaf1[i] != leaf2[i])
                return false;
        }
        return true;
    }

private:
    std::vector<int> leaf1, leaf2;

    void tree_iter(TreeNode* node, std::vector<int>& leafs) {
        if (node->left == nullptr && node->right == nullptr) {
            leafs.push_back(node->val);
            return;
        }

        if (node->left != nullptr) {
            tree_iter(node->left, leafs);
        }
        if (node->right != nullptr) {
            tree_iter(node->right, leafs);
        }
    }
};
// @lc code=end

