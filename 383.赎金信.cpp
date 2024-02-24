/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start

#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
        std::unordered_map<char, int> m;
        for (auto c : magazine) {
            m[c]++;
        }
        for (auto c : ransomNote) {
            m[c]--;
            if (m[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

