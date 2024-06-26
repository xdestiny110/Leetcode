/*
 * @lc app=leetcode.cn id=2806 lang=cpp
 *
 * [2806] 取整购买后的账户余额
 */

// @lc code=start
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        auto base = purchaseAmount / 10;
        if (purchaseAmount % 10 >= 5) {
            base++;
        }
        return 100 - base * 10;
    }
};
// @lc code=end

