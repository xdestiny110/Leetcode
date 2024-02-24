/*
 * @lc app=leetcode.cn id=2744 lang=cpp
 *
 * [2744] 最大字符串配对数目
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <ranges>

class Solution {
public:
    int maximumNumberOfStringPairs(std::vector<std::string>& words) {
        std::unordered_map<std::string, size_t> m;
        for (const auto& word : words) {
            auto w = word;
            std::reverse(w.begin(), w.end());
            if (m.contains(w)) {
                m[w]++;
            } else {
                m[word]++;
            }
        }
        auto r = m | std::views::filter([](const auto& p) {
            return p.second > 1;
        });
        return std::distance(r.begin(), r.end());
    }
};
// @lc code=end

