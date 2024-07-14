/*
 * @lc app=leetcode.cn id=2710 lang=cpp
 *
 * [2710] 移除字符串中的尾随零
 */

// @lc code=start

#include <string>

class Solution {
public:
    std::string removeTrailingZeros(std::string num) {
        auto pos = num.find_last_not_of('0');
        if (pos == std::string::npos) {
            return "0";
        }
        if (pos == num.size() - 1) {
            return num;
        }
        return num.erase(pos + 1);
    }
};
// @lc code=end

