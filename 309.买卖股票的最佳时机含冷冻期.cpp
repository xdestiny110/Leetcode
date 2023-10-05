/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        // 天数/是否持有/是否冷冻
        std::vector<std::array<std::array<int, 2>, 2>> profit;
        profit.resize(prices.size());
        profit[0][0][0] = 0;
        profit[0][0][1] = 0;
        profit[0][1][0] = -prices[0];
        profit[0][1][1] = -prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            profit[i][0][0] = std::max(profit[i - 1][0][0], profit[i - 1][0][1]);
            profit[i][0][1] = std::max(profit[i - 1][1][0] + prices[i], profit[i - 1][1][1] + prices[i]);
            profit[i][1][0] = std::max(std::max(profit[i - 1][0][0] - prices[i], profit[i - 1][1][0]), profit[i - 1][1][1]);
            profit[i][1][1] = profit[i][1][0];
        }
        return std::max(profit.back()[0][0], profit.back()[0][1]);
    }
};
// @lc code=end

