/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if(root != nullptr){
            DFS(root);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto ret = q.front()->val;
        q.pop();
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

private:
    std::queue<TreeNode*> q;

    void DFS(TreeNode* root){
        if(root->left != nullptr){
            DFS(root->left);
        }
        q.push(root);
        if(root->right != nullptr){
            DFS(root->right);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

