/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 *
 * [2828] 判别首字母缩略词
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    bool isAcronym(std::vector<std::string>& words, std::string s) {
        if (words.size() != s.size()) return false;
        for (int i = 0; i < words.size(); ++i) {
            if (s[i] != words[i].front()) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

