/*
 * @lc app=leetcode.cn id=2697 lang=cpp
 *
 * [2697] 字典序最小回文串
 */

// @lc code=start

#include <string>

class Solution {
public:
    std::string makeSmallestPalindrome(std::string s) {
        for (auto it = s.begin(), jt = s.end() - 1; it < jt; ++it, --jt) {
            *it = *jt = std::min(*it, *jt);
        }
        return s;
    }
};
// @lc code=end

