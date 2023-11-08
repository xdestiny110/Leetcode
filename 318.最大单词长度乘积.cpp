/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        std::vector<std::unordered_set<char>> word_chars(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (auto c : words[i]) {
                word_chars[i].insert(c);
            }
        }

        int max_len = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                bool overlap = false;
                for (auto c : word_chars[i]) {
                    if (word_chars[j].contains(c)) {
                        overlap = true;
                        break;
                    }
                }
                if (!overlap) {
                    max_len = std::max<int>(max_len, words[i].size() * words[j].size());
                }
            }
        }
        return max_len;
    }
};
// @lc code=end

