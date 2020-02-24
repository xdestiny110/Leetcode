/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <deque>

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return {};
        this->sum = sum;
        DFS(root, 0, {});
        return ret;
    }

private:
    std::vector<std::vector<int>> ret;
    int sum;
    void DFS(TreeNode* node, int currentSum, std::deque<int>&& r){
        if(node->left == nullptr && node->right == nullptr){
            if(node->val + currentSum == sum){
                ret.emplace_back(r.begin(), r.end());
                ret.back().emplace_back(node->val);
            }
            return;
        }

        if(node->left != nullptr){
            r.emplace_back(node->val);
            DFS(node->left, currentSum + node->val, std::move(r));
            r.pop_back();
        }

        if(node->right != nullptr){
            r.emplace_back(node->val);
            DFS(node->right, currentSum + node->val, std::move(r));
            r.pop_back();
        }
    }
};
// @lc code=end

