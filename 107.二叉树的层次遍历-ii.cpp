/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if(root == nullptr)
            return ret;

        std::queue<std::pair<int, TreeNode*>> q;
        q.push(std::make_pair(0, root));
        while(!q.empty()){
            auto& top = q.front();
            if(top.second->left != nullptr){
                q.push(std::make_pair(top.first + 1, top.second->left));
            }
            if(top.second->right != nullptr){
                q.push(std::make_pair(top.first + 1, top.second->right));
            }

            if(top.first >= ret.size()){
                ret.emplace_back();
            }
            ret.back().emplace_back(top.second->val);
            q.pop();
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

