/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    std::vector<TreeNode*> generateTrees(int n) {
        this->n = n;
        return BFS(1, n);
    }

private:
    int n;
    std::vector<TreeNode*> BFS(int left, int right){
        std::vector<TreeNode*> ret;
        for(int i = left;i <= right; i++){
            std::vector<TreeNode*> leftTree;
            leftTree = BFS(left, i - 1);
            if(leftTree.empty())
                leftTree.emplace_back(nullptr);
            std::vector<TreeNode*> rightTree;
            rightTree = BFS(i + 1, right);
            if(rightTree.empty())
                rightTree.emplace_back(nullptr);

            for(const auto& it : leftTree){
                for(const auto& jt : rightTree){
                    auto* r = new TreeNode(i);
                    r->left = it;
                    r->right = jt;
                    ret.push_back(r);
                }
            }
        }
    
        return ret;
    }
};
// @lc code=end

