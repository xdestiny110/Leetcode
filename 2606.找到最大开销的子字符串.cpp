/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 *
 * [2606] 找到最大开销的子字符串
 */

// @lc code=start

#include <unordered_map>
#include <string>
#include <vector>

class Solution {
public:
    int maximumCostSubstring(std::string s, std::string chars, std::vector<int>& vals) {
        std::unordered_map<char, int> char_val;
        for (size_t i = 0; i < vals.size(); ++i) {
            char_val[chars[i]] = vals[i];
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!char_val.contains(c)) {
                char_val[c] = c - 'a' + 1;
            }
        }
        
        std::vector<int> dp(s.size(), 0);
        dp[0] = char_val[s[0]];
        for (size_t i = 1; i < s.size(); ++i) {
            dp[i] = std::max(dp[i - 1] + char_val[s[i]], char_val[s[i]]);
        }
        return std::max(*std::max_element(dp.begin(), dp.end()), 0);
        
    }
};
// @lc code=end

