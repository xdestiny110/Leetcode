/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::unordered_map<int, std::unordered_map<int, bool>> graph;
        for (const auto& conn : connections) {
            graph[conn[0]][conn[1]] = false;
            graph[conn[1]][conn[0]] = true;
        }

        int result = 0;
        std::queue<int> dfs_nodes;
        dfs_nodes.push(0);
        std::unordered_set<int> visited_nodes;
        while (!dfs_nodes.empty()) {
            auto current_node = dfs_nodes.front();
            dfs_nodes.pop();
            visited_nodes.insert(current_node);
            const auto& conns = graph[current_node];
            for (auto [conn_node, dir] : conns) {
                if (!visited_nodes.contains(conn_node) && !dir) {
                    result++;
                }
                if (!visited_nodes.contains(conn_node)) {
                    dfs_nodes.push(conn_node);
                }
            }
        }
        return result;
    }
};
// @lc code=end

