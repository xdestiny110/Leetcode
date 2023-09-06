/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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

#include <unordered_map>
#include <queue>
#include <iterator>

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return nullptr;
        auto depthest_nodes = find_depthest_node(root);
        if (depthest_nodes.size() == 1) {
            return depthest_nodes.back();
        }
        auto parent_nodes = find_nearest_parent_node(find_parents(depthest_nodes[0]), find_parents(depthest_nodes[1]));
        for (int i = 2; i < depthest_nodes.size(); ++i) {
            parent_nodes = find_nearest_parent_node(parent_nodes, find_parents(depthest_nodes[i]));
        }
        return parent_nodes.back();
    }

private:
    std::unordered_map<TreeNode*, TreeNode*> node_parent;

    std::vector<TreeNode*> find_depthest_node(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        node_parent[root] = nullptr;
        std::vector<TreeNode*> result;

        int max_depth = 0;
        while (!q.empty()) {
            auto [node, depth] = q.front();
            if (node->left == nullptr && node->right == nullptr) {
                if (depth == max_depth)
                    result.push_back(node);
            } else {
                result.clear();
                max_depth = depth + 1;
                if (node->left != nullptr) {
                    result.clear();
                    q.push({node->left, depth + 1});
                    node_parent[node->left] = node;
                }
                if (node->right != nullptr) {
                    result.clear();
                    q.push({node->right, depth + 1});
                    node_parent[node->right] = node;
                }
            }
            q.pop();
        }
        return result;
    }

    std::vector<TreeNode*> find_parents(TreeNode* node) const {
        std::vector<TreeNode*> parents;
        while (node != nullptr) {
            parents.push_back(node);
            node = node_parent.at(node);
        }
        std::reverse(parents.begin(), parents.end());
        return parents;
    }

    std::vector<TreeNode*> find_nearest_parent_node(const std::vector<TreeNode*>& parents1, const std::vector<TreeNode*>& parents2) const {
        int idx = std::min(parents1.size() - 1, parents2.size() - 1);
        while (parents1[idx] != parents2[idx]) {
            idx--;
        }
        std::vector<TreeNode*> result;
        std::copy(parents1.begin(), parents1.begin() + idx + 1, std::back_inserter(result));
        return result;
    }

};
// @lc code=end

