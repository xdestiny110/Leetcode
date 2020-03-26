/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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

#include <deque>
#include <algorithm>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        r1.push_back(root);
        DFS(root, p, q);
        return ret;
    }

private:
    std::deque<TreeNode*> r1, r2;
    bool flag = false;
    TreeNode* ret = nullptr;
    
    void DFS(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == p || node == q){
            if(!flag){
                flag = true;
                r2.resize(r1.size());
                std::copy(r1.begin(), r1.end(), r2.begin());
            }
            else{
                for(int i = 0; i < std::min(r1.size(), r2.size()); ++i){
                    if(r1[i] != r2[i]){
                        ret = r1[i-1];
                        break;
                    }
                }
                if(ret == nullptr) ret = (r1.size() > r2.size())?r2.back():r1.back();
                return;
            }
        }

        if(node->left != nullptr){
            pushNode(node->left);
            DFS(node->left, p, q);
            popNode();
        }

        if(ret != nullptr){
            return;
        }

        if(node->right != nullptr){
            pushNode(node->right);
            DFS(node->right, p, q);
            popNode();
        }
    }

    void pushNode(TreeNode* n){
        if(flag)
            r2.push_back(n);
        else
            r1.push_back(n);
    }

    void popNode(){
        if(flag)
            r2.pop_back();
        else
            r1.pop_back();
    }
};
// @lc code=end

