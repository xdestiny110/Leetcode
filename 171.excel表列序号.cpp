/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
#include <string>

class Solution {
public:
    int titleToNumber(std::string s) {
        long plus = 1;
        long sum = 0;
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            sum += (*it - 'A' + 1) * plus;
            plus*=26;
        }
        return sum;
    }
};
// @lc code=end

