/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <vector>
#include <array>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
        std::array<int, 1001> from_to{};
        for (const auto& trip : trips) {
            for (int i = trip[1]; i < trip[2]; ++i) {
                from_to[i] += trip[0];
                if (from_to[i] > capacity) return false;
            }
        }
        return true;
    }
};
// @lc code=end

