/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost, int runningCost) {
        std::vector<int> profits(customers.size(), 0);
        int rest_customers = 0;
        int profit = 0;
        int max_profit = 0;
        int max_profit_cnt = -1;
        for (int i = 0; i < customers.size(); ++i) {
            auto customer = std::min(rest_customers + customers[i], 4);
            profit += customer * boardingCost - runningCost;
            if (profit > max_profit) {
                max_profit = profit;
                max_profit_cnt = i + 1;
            }
            rest_customers = rest_customers + customers[i] - customer;
        }
        auto rotate_cnt = customers.size();
        while (rest_customers > 0) {
            auto customer = std::min(4, rest_customers);
            profit += customer * boardingCost - runningCost;
            rotate_cnt++;
            if (profit > max_profit) {
                max_profit = profit;
                max_profit_cnt = rotate_cnt;
            }
            rest_customers -= customer;
        }
        return max_profit_cnt;
    }
};
// @lc code=end

