/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n > 1){
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
// @lc code=end

