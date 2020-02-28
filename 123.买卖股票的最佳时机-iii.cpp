/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        std::vector<int> states(4, std::numeric_limits<int>::min());
        states[0] = -prices[0];
        for(int i = 1; i < prices.size(); ++i){
            states[0] = std::max(states[0], -prices[i]);
            states[1] = std::max(states[1], prices[i] + states[0]);
            states[2] = std::max(states[2], states[1] - prices[i]);
            states[3] = std::max(states[3], prices[i] + states[2]);
        }
        return std::max(states[3], 0);
    }
};
// @lc code=end

