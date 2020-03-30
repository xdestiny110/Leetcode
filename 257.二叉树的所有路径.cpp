/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};
        DFS(root, std::to_string(root->val));
        return ret;
    }

private:
    std::vector<std::string> ret;

    void DFS(TreeNode* node, std::string&& r){
        if(node->left == nullptr && node->right == nullptr){
            ret.emplace_back(r);
        }

        auto oldSize = r.size();
        if(node->left != nullptr){
            r += "->";
            r += std::to_string(node->left->val);
            DFS(node->left, std::move(r));
            r.erase(oldSize);
        }

        if(node->right != nullptr){
            r += "->";
            r += std::to_string(node->right->val);
            DFS(node->right, std::move(r));
            r.erase(oldSize);
        }
    }
};
// @lc code=end

