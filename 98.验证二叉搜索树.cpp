/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

#include <utility>
#include <optional>
#include <algorithm>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return std::get<0>(checkBST(root));
    }

private:
    std::tuple<bool, std::optional<int>, std::optional<int>> checkBST(TreeNode* root){
        if(root == nullptr)
            return std::make_tuple(true, std::nullopt, std::nullopt);

        auto fLeft = checkBST(root->left);
        auto fRight = checkBST(root->right);

        auto flag = std::make_tuple<bool, std::optional<int>, std::optional<int>>(true, root->val, root->val);
        std::get<0>(flag) &= std::get<0>(fLeft) & std::get<0>(fRight);
        if(std::get<0>(flag)){
            auto leftMax = std::get<2>(fLeft);
            if(leftMax.has_value()){
                std::get<0>(flag) &= (root->val > leftMax.value());
            }
            auto rightMin = std::get<1>(fRight);
            if(rightMin.has_value()){
                std::get<0>(flag) &= (root->val < rightMin.value());
            }
        }

        if(std::get<0>(flag)){
            if(std::get<1>(fLeft).has_value())
                std::get<1>(flag) = std::get<1>(fLeft);
            else if(std::get<2>(fLeft).has_value())
                std::get<1>(flag) = std::get<2>(fLeft);

            if(std::get<2>(fRight).has_value())
                std::get<2>(flag) = std::get<2>(fRight);
            else if(std::get<2>(fRight).has_value())
                std::get<2>(flag) = std::get<1>(fRight);
        }
        return flag;
    }
};
// @lc code=end

