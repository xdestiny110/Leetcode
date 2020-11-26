/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val > key){
            auto r = deleteNode(root->left, key);
            root->left = r;
        }
        if(root->val < key){
            auto r = deleteNode(root->right, key);
            root->right = r;
        }            
        if(root->val == key){
            if(root->right != nullptr){
                // 找到右子树最小值
                auto t = root->right;
                while(t->left != nullptr) t = t->left;
                root->val = t->val;
                auto r = deleteNode(root->right, t->val);
                root->right = r;
            }
            else if(root->left != nullptr){
                root->val = root->left->val;
                auto r = deleteNode(root->left, root->left->val);
                root->left = r;
            }
            else if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }
            return root;
        }
        return root;
    }
};
// @lc code=end

