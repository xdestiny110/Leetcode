/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start

class Solution {
public:
    int countDigits(int num) {
        auto origin_num = num;
        int result = 0;
        while (num > 0) {
            if (origin_num % (num % 10) == 0) {
                result++;
            }
            num /= 10;
        }
        return result;
    }
};
// @lc code=end

