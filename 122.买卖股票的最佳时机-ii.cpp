/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <vector>

// @lc code=start
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
// @lc code=end

