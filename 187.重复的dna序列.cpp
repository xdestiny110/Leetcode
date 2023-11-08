/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        if (s.size() < 10) return {};
        std::unordered_map<std::string, int> dnas;
        for (int i = 0; i <= s.size() - 10; ++i) {
            dnas[s.substr(i, 10)]++;
        }
        std::vector<std::string> result;
        for (const auto& [dna, cnt] : dnas) {
            if (cnt > 1) {
                result.push_back(dna);
            }
        }
        return result;
    }
};
// @lc code=end

