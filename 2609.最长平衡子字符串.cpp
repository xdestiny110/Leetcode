/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
#include <string>

class Solution {
public:
    int findTheLongestBalancedSubstring(std::string s) {
        int zero_cnt = 0;
        int one_cnt = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (one_cnt > 0) {
                    max_len = std::max(max_len, std::min(zero_cnt, one_cnt) * 2);
                    zero_cnt = 0;
                    one_cnt = 0;
                }
                zero_cnt++;
            } else {
                one_cnt++;
            }
        }
        max_len = std::max(max_len, std::min(zero_cnt, one_cnt) * 2);
        return max_len;
    }
};
// @lc code=end

