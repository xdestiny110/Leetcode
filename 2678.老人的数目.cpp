/*
 * @lc app=leetcode.cn id=2678 lang=cpp
 *
 * [2678] 老人的数目
 */

// @lc code=start
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

class Solution {
public:
    int countSeniors(std::vector<std::string>& details) {
        return std::count_if(details.begin(), details.end(), [](const std::string& detail) {
            return std::stoi(detail.substr(11, 2)) > 60;
        });        
    }
};
// @lc code=end

