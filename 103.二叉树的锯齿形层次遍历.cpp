/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};

        std::vector<std::vector<TreeNode*>> nodes;
        nodes.emplace_back();
        nodes.front().emplace_back(root);
        std::vector<std::vector<int>> ret;

        for(int i = 0; i < nodes.size(); i++){
            ret.emplace_back();
            for(int j = 0;j < nodes[i].size(); j++){
                if(i % 2 == 0){
                    ret.back().emplace_back(nodes[i][j]->val);
                }
                if(nodes.size() <= i + 1 && ((nodes[i][j]->left != nullptr) || (nodes[i][j]->right != nullptr)))
                    nodes.emplace_back();
                if(nodes[i][j]->left != nullptr)
                    nodes[i+1].emplace_back(nodes[i][j]->left);
                if(nodes[i][j]->right != nullptr)
                    nodes[i+1].emplace_back(nodes[i][j]->right);
            }
            if(i % 2 != 0){
                for(int j = nodes[i].size()-1; j >= 0; j--){
                    ret.back().emplace_back(nodes[i][j]->val);
                }
            }
        }
        
        return ret;
    }    
};
// @lc code=end

