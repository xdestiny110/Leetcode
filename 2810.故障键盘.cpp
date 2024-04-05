/*
 * @lc app=leetcode.cn id=2810 lang=cpp
 *
 * [2810] 故障键盘
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string finalString(std::string s) {
        std::string ret;
        ret.reserve(s.size());
        for (auto c : s) {
            if (c == 'i') {
                std::reverse(ret.begin(), ret.end());
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
};
// @lc code=end

