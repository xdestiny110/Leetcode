/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        auto circles = time / (n - 1);
        if (circles % 2) {
            return n - time % (n - 1);
        }
        return time % (n - 1) + 1;
    }
};
// @lc code=end

