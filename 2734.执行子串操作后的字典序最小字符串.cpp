/*
 * @lc app=leetcode.cn id=2734 lang=cpp
 *
 * [2734] 执行子串操作后的字典序最小字符串
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string smallestString(std::string s) {
        auto start_it = std::find_if(s.begin(), s.end(), [](char c) {
            return c != 'a';
        });
        if (start_it == s.end()) {
            s.back() = 'z';
            return s;
        }
        auto end_it = std::find_if(start_it, s.end(), [](char c) {
            return c == 'a';
        });
        for (auto it = start_it; it != end_it; ++it) {
            *it -= 1;
        }
        return s;
    }
};
// @lc code=end

