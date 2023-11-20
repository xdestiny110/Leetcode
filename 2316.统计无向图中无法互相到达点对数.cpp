/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    long long countPairs(int n, const std::vector<std::vector<int>>& edges) {
        if (edges.empty()) {
            
        }
        
        for (const auto& edge : edges) {
            graph_[edge[0]].insert(edge[1]);
            graph_[edge[1]].insert(edge[0]);
        }
        visited_.resize(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited_[i]) {
                graph_node_cnt_.push_back(dfs(i));
            }
        }

        long long result = n * 1LL * (n - 1) / 2;
        for (int i = 0; i < graph_node_cnt_.size(); ++i) {
            result -= graph_node_cnt_[i] * (graph_node_cnt_[i] - 1) / 2;
        }
        return result;
    }

private:
    std::vector<bool> visited_;
    std::unordered_map<int, std::unordered_set<int>> graph_;
    std::vector<long long> graph_node_cnt_;

    long long dfs(int idx) {
        long long count = 1;
        visited_[idx] = true;
        for (auto t : graph_[idx]) {
            if (!visited_[t]) {
                count += dfs(t);
            }
        }
        return count;
    }
};
// @lc code=end

