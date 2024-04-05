/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
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
#include <deque>

class Solution {
public:
    std::vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        auto root = new TreeNode();
        if (n == 1) return { root };
        dfs(n - 1, { root }, root);
        return binary_tree_;
    }

private:
    std::vector<TreeNode*> binary_tree_;

    void dfs(int n, std::deque<TreeNode*> nodes, TreeNode* root) {
        if (n == 0) {
            binary_tree_.push_back(deep_copy(root));
            return;
        }
        while (!nodes.empty()) {
            auto* node = nodes.front();
            nodes.pop_front();
            node->left = new TreeNode();
            node->right = new TreeNode();
            nodes.push_back(node->left);
            nodes.push_back(node->right);
            dfs(n - 2, nodes, root);
            nodes.pop_back();
            nodes.pop_back();
            delete node->left;
            node->left = nullptr;
            delete node->right;
            node->right = nullptr;
        }
    }

    TreeNode* deep_copy(TreeNode* node) const {
        auto* n = new TreeNode();
        if (node->left) {
            n->left = deep_copy(node->left);
        }
        if (node->right) {
            n->right = deep_copy(node->right);
        }
        return n;
    }

};
// @lc code=end

