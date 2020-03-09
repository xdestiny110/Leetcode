/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        std::queue<std::pair<int, TreeNode*>> q;
        q.push(std::make_pair(0, root));
        std::vector<int> result;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(result.size() <= node.first){
                result.emplace_back(node.second->val);
            }
            if(node.second->right != nullptr){
                q.push(std::make_pair(node.first + 1, node.second->right));
            }
            if(node.second->left != nullptr){
                q.push(std::make_pair(node.first + 1, node.second->left));
            }
        }
        return result;
    }
};
// @lc code=end

