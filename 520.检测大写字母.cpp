/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
public:
    bool detectCapitalUse(std::string word) {
        return (word.size() == 1) || std::all_of(word.begin() + 1, word.end(), [](char ch){
            return ch >= 'a' && ch <= 'z';
        }) || std::all_of(word.begin(), word.end(), [](char ch) {
            return ch >= 'A' && ch <= 'Z';
        });
    }
};
// @lc code=end

