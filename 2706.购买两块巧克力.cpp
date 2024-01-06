/*
 * @lc app=leetcode.cn id=2706 lang=cpp
 *
 * [2706] 购买两块巧克力
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        return (prices[0] + prices[1] > money) ? money : money - prices[0] - prices[1];
    }
};
// @lc code=end

