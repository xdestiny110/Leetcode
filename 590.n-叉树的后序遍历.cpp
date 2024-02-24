/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    std::vector<int> postorder(Node* root) {
        if (root) {
            dfs(root);
        }
        return result_;
    }

private:
    std::vector<int> result_;
    void dfs(Node* node) {
        for (auto* n : node->children) {
            dfs(n);
        }
        result_.push_back(node->val);
    }
};
// @lc code=end

