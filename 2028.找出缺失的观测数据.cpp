/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start

#include <numeric>
#include <vector>

class Solution {
public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        auto sum = (rolls.size() + n) * mean;
        auto current_sum = std::accumulate(rolls.begin(), rolls.end(), 0);
        if (sum < current_sum + n || sum > current_sum + 6 * n) {
            return {};
        }
        std::vector<int> result(n);
        auto remain_sum = sum - current_sum;
        for (size_t i = 0; i < n; ++i) {
            result[i] = remain_sum / (n - i);
            remain_sum -= result[i];
        }
        return remain_sum == 0 ? result : std::vector<int>{};
    }
};
// @lc code=end

