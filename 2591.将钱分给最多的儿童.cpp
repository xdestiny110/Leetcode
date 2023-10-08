/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start

#include <algorithm>

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) return -1;
        int result = std::min(money / 7, children);
        money -= 7 * result;
        if ((money == 3 && children - result == 1) || (money > 0 && children == result)) {
            return std::max(result - 1, 0);
        }
        return result;
    }
};
// @lc code=end

