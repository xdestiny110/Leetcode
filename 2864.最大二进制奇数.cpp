/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 *
 * [2864] 最大二进制奇数
 */

// @lc code=start
#include <string>

class Solution {
public:
    string maximumOddBinaryNumber(std::string s) {
        auto cnt = std::count(s.begin(), s.end(), '1');
        std::fill(s.begin(), s.end(), '0');
        s.back() = '1';
        cnt--;
        std::fill(s.begin(), s.begin() + cnt, '1');
        return s;        
    }
};
// @lc code=end

