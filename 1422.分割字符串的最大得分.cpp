/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start

#include <string>
#include <set>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int one_cnt = std::count(s.begin(), s.end(), '1');

        int max_score = 0;
        int left_zero_cnt = 0;
        int left_one_cnt = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i - 1] == '0') {
                left_zero_cnt++;
            } else {
                left_one_cnt++;
            }
            max_score = std::max(max_score, left_zero_cnt + one_cnt - left_one_cnt);
        }
        return max_score;
    }
};

// @lc code=end

