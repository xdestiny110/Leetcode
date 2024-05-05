/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 */

// @lc code=start

#include <string>

class Solution {
public:
    std::string maximumBinaryString(std::string binary) {
        size_t prev_zero = binary.find_first_of('0');
        if (prev_zero == std::string::npos) {
            return binary;
        }
        size_t next_zero = binary.find_first_of('0', prev_zero + 1);
        while (next_zero != std::string::npos) {
            binary[prev_zero] = '1';
            binary[next_zero] = '1';
            binary[++prev_zero] = '0';
            next_zero = binary.find_first_of('0', next_zero + 1);
        }
        return binary;
    }
};
// @lc code=end

