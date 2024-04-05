/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 *
 * [2192] 有向无环图中一个节点的所有祖先
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::unordered_set<int>> froms, tos;
        for (auto edge : edges) {
            froms[edge[1]].insert(edge[0]);
            tos[edge[0]].insert(edge[1]);
        }
        std::unordered_map<int, std::unordered_set<int>> froms_copy(froms.begin(), froms.end());

        std::queue<int> proc_ids;
        for (int i = 0; i < n; ++i) {
            if (froms_copy[i].empty()) {
                proc_ids.push(i);
            }
        }

        std::vector<std::vector<int>> result(n);
        while (!proc_ids.empty()) {
            auto id = proc_ids.front();
            proc_ids.pop();
            for (int from : froms[id]) {
                result[id].push_back(from);
                result[id].insert(result[id].end(), result[from].begin(), result[from].end());
            }
            std::sort(result[id].begin(), result[id].end());
            result[id].erase(std::unique(result[id].begin(), result[id].end()), result[id].end());

            for (int to : tos[id]) {
                froms_copy[to].erase(id);
                if (froms_copy[to].empty()) {
                    proc_ids.push(to);
                }
            }
        }
        return result;
    }
};
// @lc code=end

