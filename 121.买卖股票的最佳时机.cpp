/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty()) return 0;
        int minB = prices[0];
        int maxL = 0;
        for(int i = 1; i < prices.size(); i++){
            minB = std::min(prices[i], minB);
            maxL = std::max(prices[i] - minB, maxL);
        }
        return maxL;
    }
};
// @lc code=end

