/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 *
 * [2462] 雇佣 K 位工人的总代价
 */

// @lc code=start

#include <queue>
#include <vector>

struct Worker {
    int cost_;
    size_t idx_;

    auto operator<=>(const Worker&) const = default;
};

class Solution {
public:
    long long totalCost(const std::vector<int>& costs, int k, int candidates) {
        std::priority_queue<Worker, std::vector<Worker>, std::greater<>> fronts, backs;
        for (size_t i = 0; i < candidates && i < costs.size(); ++i) {
            fronts.push({costs[i], i});
            backs.push({costs[costs.size() - i - 1], costs.size() - i - 1});
        }
        size_t fronts_idx = candidates;
        int backs_idx = costs.size() - candidates - 1;
        std::deque<bool> selected(costs.size(), false);

        long long cost_result = 0;
        for (int i = 0; i < k; ++i) {
            auto select_worker = (fronts.top().cost_ > backs.top().cost_) ? backs.top() : fronts.top(); 
            cost_result += select_worker.cost_;
            selected[select_worker.idx_] = true;
            if (fronts.top() == select_worker) {
                fronts.pop();
                for (size_t j = fronts_idx; j < costs.size(); ++j) {
                    if (!selected[j]) {
                        fronts.push({costs[j], j});
                        fronts_idx = j + 1;
                        break;
                    }
                }
            }
            if (backs.top() == select_worker) {
                backs.pop();
                for (int j = backs_idx; j >= 0; --j) {
                    if (!selected[j]) {
                        backs.push({costs[j], (size_t)j});
                        backs_idx = j - 1;
                        break;
                    }
                }
            }
        }
        return cost_result;
    }
};
// @lc code=end

