/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <unordered_map>
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return result;
    }

private:
    int result = 0;
    std::array<int, 10> nums_cnt;
    int odd_cnt = 0;
    int even_cnt = 0;
    void dfs(TreeNode* node) {
        bool flag = nums_cnt[node->val] % 2 == 0;
        odd_cnt = flag ? odd_cnt + 1 : odd_cnt - 1;
        even_cnt = flag ? even_cnt - 1 : even_cnt + 1;
        nums_cnt[node->val]++;

        if (node->left == nullptr && node->right == nullptr) {
            if (odd_cnt <= 1) result++;
        }
        if (node->left != nullptr) {
            dfs(node->left);
        }
        if (node->right != nullptr) {
            dfs(node->right);
        }

        odd_cnt = flag ? odd_cnt - 1 : odd_cnt + 1;
        even_cnt = flag ? even_cnt + 1 : even_cnt - 1;
        nums_cnt[node->val]--;
    }

};
// @lc code=end

