/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
    using Pair = std::pair<int, int>;
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> num_count;
        for (auto num : nums) {
            num_count[num]++;
        }

        auto pair_cmp = [](const Pair& lhs, const Pair& rhs) {
            return lhs.second > rhs.second;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(pair_cmp)> q(pair_cmp);
        for (const auto& p : num_count) {
            q.push({p.first, p.second});
            while (q.size() > k) {
                q.pop();
            }
        }

        std::vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};
// @lc code=end

