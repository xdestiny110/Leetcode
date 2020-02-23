/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return ret;
    }

private:
    std::vector<std::vector<int>> ret;
    void DFS(TreeNode* node, int layer){
        if(node == nullptr)
            return;
        if(ret.size() <= layer){
            ret.emplace_back();
        }
        ret[layer].emplace_back(node->val);

        DFS(node->left, layer + 1);
        DFS(node->right, layer + 1);
    }
};
// @lc code=end

