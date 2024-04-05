/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    FindElements(TreeNode* root) {
        if (!root) return;
        root->val = 0;
        s_.insert(0);
        dfs(root);
    }
    
    bool find(int target) {
        return s_.contains(target);
    }

private:
    std::unordered_set<int> s_;
    void dfs(TreeNode* node) {
        if (node->left != nullptr) {
            node->left->val = 2 * node->val + 1;
            s_.insert(node->left->val);
            dfs(node->left);
        }
        if (node->right != nullptr) {
            node->right->val = 2 * node->val + 2;
            s_.insert(node->right->val);
            dfs(node->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

