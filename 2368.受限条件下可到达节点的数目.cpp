/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted) {
        std::unordered_set<int> r(restricted.begin(), restricted.end());
        for (const auto& e : edges) {
            if (!r.contains(e[0]) && !r.contains(e[1])) {
                edges_[e[0]].insert(e[1]);
                edges_[e[1]].insert(e[0]);
            }
        }
        dfs(0);
        return visited_.size();
    }

private:
    std::unordered_set<int> visited_;
    std::unordered_map<int, std::unordered_set<int>> edges_;
    void dfs(int node) {
        visited_.insert(node);
        for (auto n : edges_[node]) {
            if (!visited_.contains(n))
                dfs(n);
        }
    }
};
// @lc code=end

