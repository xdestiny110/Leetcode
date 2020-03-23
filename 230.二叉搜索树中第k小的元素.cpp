/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return DFS(k, root);
    }

private:
    int DFS(int& layer, TreeNode* node) const{
        if(node->left != nullptr){
            auto r = DFS(layer, node->left);
            if(layer == 0) return r;
        }
        layer--;
        if(layer == 0) return node->val;
        if(node->right != nullptr){
            auto r = DFS(layer, node->right);
            if(layer == 0) return r;
        }
        return 0;
    }
};
// @lc code=end

