/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
#include <regex>
#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::regex r(R"(\S+)");
        std::smatch m;
        std::string result = "";
        while(std::regex_search(s, m, r))
        {
            if(result != "") result = " " + result;
            result = m.str() + result;
            s = m.suffix();
        }
        return result;
    }
};
// @lc code=end

