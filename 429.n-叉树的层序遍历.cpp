/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        std::vector<std::vector<int>> result;
        std::queue<std::pair<Node*, int>> node_depth;
        node_depth.push({root, 1});
        while (!node_depth.empty()) {
            auto [node, depth] = node_depth.front();
            node_depth.pop();
            if (result.size() < depth) {
                result.push_back({});
            }
            result.back().push_back(node->val);
            for (auto child : node->children) {
                node_depth.push({child, depth + 1});
            }
        }
        return result;
    }
};
// @lc code=end

