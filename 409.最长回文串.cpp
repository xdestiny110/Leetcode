/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <string>
#include <cstdint>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, uint32_t> char_counts;
        for (auto c : s) {
            char_counts[c]++;
        }

        bool use_single = false;
        int result = 0;
        for (const auto& [_, cnt] : char_counts) {
            result += cnt / 2 * 2;
            if (!use_single && cnt % 2 != 0) {
                result++;
                use_single = true;
            }
        }
        return result;
    }
};
// @lc code=end

