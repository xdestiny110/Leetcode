/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
 */

// @lc code=start
#include <array>
#include <optional>
#include <string>
#include <vector>

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        std::vector<int> travel_prefix(travel.begin(), travel.end());
        for (size_t idx = 1; idx < travel.size(); ++idx) {
            travel_prefix[idx] += travel_prefix[idx - 1];
        }

        constexpr std::array<char, 3> garbage_ch = {'M', 'P', 'G'};
        std::array<std::pair<std::optional<size_t>, size_t>, garbage_ch.size()> last_garbage_idx{};
        for (size_t jdx = 0; jdx < garbage_ch.size(); ++jdx) {
            char c = garbage_ch[jdx];
            for (size_t idx = 0; idx < garbage.size(); ++idx) {
                auto& garbage_str = garbage[idx];
                size_t cnt = std::count(garbage_str.begin(), garbage_str.end(), c);
                if (cnt > 0) {
                    last_garbage_idx[jdx].first = idx;
                    last_garbage_idx[jdx].second += cnt;
                }
            }
        }

        int cost_minutes = 0;
        for (auto lgi : last_garbage_idx) {
            if (lgi.first.has_value()) {
                cost_minutes += lgi.second;
                if (lgi.first > 0) {
                    cost_minutes += travel_prefix[*lgi.first - 1];
                }
            }
        }
        return cost_minutes;
    }
};
// @lc code=end

