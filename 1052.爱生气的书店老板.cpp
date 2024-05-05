/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start

#include <vector>
#include <numeric>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        if (minutes >= customers.size()) {
            return std::accumulate(customers.begin(), customers.end(), 0); 
        }

        std::vector<int> prefix(customers.size(), 0);
        prefix[0] = customers[0];
        for (size_t i = 1; i < customers.size(); ++i) {
            prefix[i] = prefix[i - 1] + customers[i];
        }
        std::vector<int> prefix_in_minutes(customers.size(), 0);
        for (size_t i = 0; i < customers.size(); ++i) {
            prefix_in_minutes[i] = prefix[i] - (i >= minutes ? prefix[i - minutes] : 0);
        }

        std::vector<std::pair<int, int>> dp(customers.size());
        dp[0].first = customers[0];
        dp[0].second = grumpy[0] ? 0 : customers[0];
        for (size_t i = 1; i < customers.size(); ++i) {
            dp[i].first = std::max(dp[i - 1].first + (grumpy[i] ? 0 : customers[i]), (i < minutes ? prefix_in_minutes[i] : dp[i - minutes].second + prefix_in_minutes[i]));
            dp[i].second = dp[i - 1].second + (grumpy[i] ? 0 : customers[i]);
        }
        return dp.back().first;
    }
};
// @lc code=end

