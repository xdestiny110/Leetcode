/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
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

#include <deque>

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::deque<TreeNode*> q;
        find_target_history(target, original, q);
        q.pop_front();
        while (!q.empty()) {
            auto n = q.front();
            q.pop_front();
            cloned = (original->left == n) ? cloned->left : cloned->right;
            original = n;
        }
        return cloned;
    }

private:
    bool find_target_history(TreeNode* target, TreeNode* node, std::deque<TreeNode*>& history) const {
        history.push_back(node);
        if (node == target) {
            return true;
        }

        bool flag = node->left && find_target_history(target, node->left, history);
        if (!flag) {
            flag = node->right && find_target_history(target, node->right, history);
        }
        if (!flag) {
            history.pop_back();
        }
        return flag;
    }
};
// @lc code=end

