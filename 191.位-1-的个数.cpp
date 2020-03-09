/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0){
            if(n % 2) cnt++;
            n /= 2;
        }
        return cnt;
    }
};
// @lc code=end

