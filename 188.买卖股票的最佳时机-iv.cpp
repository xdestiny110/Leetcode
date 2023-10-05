/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        // 天数/是否持股/交易数
        std::vector<std::vector<std::vector<int>>> profit(prices.size(), std::vector<std::vector<int>>(2, std::vector<int>(k + 1, 0)));
        for (int i = 0; i <= k; ++i) {
            profit[0][1][i] = -prices[0];
        }
        
        for (int i = 1; i < prices.size(); ++i) {
            profit[i][1][0] = std::max(profit[i - 1][1][0], -prices[i]);
            for (int j = 1; j <= k; ++j) {
                profit[i][0][j] = std::max(profit[i - 1][0][j], profit[i - 1][1][j - 1] + prices[i]);
                profit[i][1][j] = std::max(profit[i - 1][1][j], profit[i - 1][0][j] - prices[i]);
            }
        }

        return profit.back()[0].back();
    }
};
// @lc code=end

