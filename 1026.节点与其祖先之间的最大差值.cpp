/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
#include <stack>

struct MaxStack {
    std::stack<int> s_;
    std::stack<int> max_;
    std::stack<int> min_;
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        MaxStack parents;
        dfs(root, parents);
        return result_;
    }

private:
    int result_ = 0;
    void dfs(TreeNode* node, MaxStack& parents) {
        parents.s_.push(node->val);
        parents.max_.push((parents.max_.empty() || parents.max_.top() < node->val) ? node->val : parents.max_.top());
        parents.min_.push((parents.min_.empty() || parents.min_.top() > node->val) ? node->val : parents.min_.top());
        result_ = std::max(std::abs(parents.max_.top() - parents.min_.top()), result_);

        if (node->left) {
            dfs(node->left, parents);
        }
        
        if (node->right) {
            dfs(node->right, parents);
        }
        parents.s_.pop();
        parents.max_.pop();
        parents.min_.pop();
    }
};
// @lc code=end

