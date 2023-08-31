/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <string>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        for (size_t i = 1; i <= s.size() / 2; ++i) {
            if (s.size() % i != 0) continue;
            auto tmp = s.substr(0, i);
            bool flag = true;
            for (size_t j = i; j < s.size(); j += i) {
                if (s.substr(j, i) != tmp) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

