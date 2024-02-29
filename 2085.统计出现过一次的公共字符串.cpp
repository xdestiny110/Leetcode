/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <ranges>

class Solution {
public:
    int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::unordered_map<std::string, std::pair<int, int>> m;
        for (const auto& w : words1) {
            m[w].first++;
        }
        for (const auto& w : words2) {
            m[w].second++;
        }

        return std::count_if(m.begin(), m.end(), [](const auto& e) {
            return e.second.first == 1 && e.second.second == 1;
        });
    }
};
// @lc code=end

