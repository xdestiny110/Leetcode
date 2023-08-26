/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start

#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, uint32_t> char_counts;
        std::array<std::unordered_set<char>, 500001> count_chars;
        for (auto c : s) {
            auto it = char_counts.find(c);
            if (it == char_counts.end()) {
                count_chars[1].insert(c);
                char_counts[c] = 1;
            } else {
                count_chars[it->second].erase(c);
                char_counts[c]++;
                count_chars[char_counts[c]].insert(c);
            }
        }

        std::string result;
        for (int i = count_chars.size() - 1; i >= 0; --i) {
            for (auto c : count_chars[i]) {
                result.insert(result.size(), i, c);
            }
        }
        return result;
    }
};
// @lc code=end

