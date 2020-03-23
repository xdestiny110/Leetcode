/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while(n > 0){
            if(n & 0x1) cnt++;
            if(cnt > 1) return false;
            n >>= 1;
        }
        return cnt > 0;
    }
};
// @lc code=end

