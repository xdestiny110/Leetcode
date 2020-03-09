/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <bitset>
#include <cmath>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> b;
        int cnt = 31;
        while(n > 0){
            if(n % 2){
                b[cnt] = 1;
            }
            cnt--;
            n /= 2;
        }

        uint32_t ret = 0;
        for(int i = 0; i < 32; ++i){
            if(b[i]) ret += std::pow(2, i);
        }
        return ret;
    }
};
// @lc code=end

