/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        // 天数/是否持股
        std::vector<std::array<int, 2>> profit;
        profit.resize(prices.size());
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit[i][0] = std::max(profit[i - 1][0], profit[i - 1][1] + prices[i] - fee);
            profit[i][1] = std::max(profit[i - 1][0] - prices[i], profit[i - 1][1]);
        }
        return profit.back()[0];
    }
};
// @lc code=end

