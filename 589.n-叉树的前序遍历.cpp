/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>

class Solution {
public:
    std::vector<int> preorder(Node* root) {
        if (!root) return {};
        dfs(root);
        return result_;
    }

private:
    std::vector<int> result_;
    void dfs(Node* node) {
        result_.push_back(node->val);
        for (auto n : node->children) {
            dfs(n);
        }
    }
};
// @lc code=end

