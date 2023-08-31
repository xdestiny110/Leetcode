/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
#include <vector>
#include <optional>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int result_chars_idx = 0;

        int last_char_cnt = 1;
        char last_char = chars[0];
        result_chars_idx = 0;
        for (int i = 1; i < chars.size(); ++i) {
            if (last_char == chars[i]) {
                last_char_cnt++;
            } else {
                chars[result_chars_idx++] = last_char;
                if (last_char_cnt > 1) {
                    auto s = std::to_string(last_char_cnt);
                    for (auto c : s) {
                        chars[result_chars_idx++] = c;
                    }
                }
                last_char = chars[i];
                last_char_cnt = 1;
            }
        }
        chars[result_chars_idx++] = last_char;
        if (last_char_cnt > 1) {
            auto s = std::to_string(last_char_cnt);
            for (auto c : s) {
                chars[result_chars_idx++] = c;
            }
        }

        return result_chars_idx;
    }
};
// @lc code=end

