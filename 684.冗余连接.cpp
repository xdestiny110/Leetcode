/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::unordered_set<int>> edge_list;
        for (const auto& edge : edges) {
            edge_list[edge[0]].insert(edge[1]);
            edge_list[edge[1]].insert(edge[0]);
        }

        for (auto it = edges.rbegin(); it != edges.rend(); ++it) {
            edge_list[(*it)[0]].erase((*it)[1]);
            edge_list[(*it)[1]].erase((*it)[0]);
            std::unordered_set<int> visited;
            if (is_connect(edge_list, (*it)[0], (*it)[1], visited)) {
                return *it;
            }
        }
        return {};
    }

private:
    bool is_connect(const std::unordered_map<int, std::unordered_set<int>>& edge_list, int node, int target, std::unordered_set<int>& visited) const {
        for (const auto& link_node : edge_list.at(node)) {
            if (link_node == target) {
                return true;
            }
            if (visited.find(link_node) != visited.end()) {
                continue;
            }
            visited.insert(link_node);
            if (is_connect(edge_list, link_node, target, visited)) {
                return true;
            }
        }
        return false;
    }

};
// @lc code=end

