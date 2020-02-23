/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildTree(nums.cbegin(), nums.cend());
    }
private:
    TreeNode* buildTree(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) const{
        if(start == end)
            return nullptr;
        
        auto c = start + std::distance(start, end) / 2;
        auto* root = new TreeNode(*c);
        root->left = buildTree(start, c);
        root->right = buildTree(c+1, end);
        return root;
    }
};
// @lc code=end

