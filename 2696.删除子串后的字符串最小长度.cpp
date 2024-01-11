/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 *
 * [2696] 删除子串后的字符串最小长度
 */

// @lc code=start

#include <string>

class Solution {
public:
    int minLength(std::string s) {
        bool has_del = true;
        while (has_del) {
            has_del = false;
            if (auto pos = s.find("AB"); pos != std::string::npos) {
                has_del = true;
                s.erase(pos, 2);
            }
            if (auto pos = s.find("CD"); pos != std::string::npos) {
                has_del = true;
                s.erase(pos, 2);
            }
        }
        return s.size();
    }
};
// @lc code=end

