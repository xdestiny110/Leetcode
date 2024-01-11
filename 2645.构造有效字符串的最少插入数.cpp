/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 *
 * [2645] 构造有效字符串的最少插入数
 */

// @lc code=start

#include <string>
#include <optional>

class Solution {
public:
    int addMinimum(std::string word) {
        std::optional<char> last_char = std::nullopt;
        int result = 0;
        for (auto w : word) {
            if (w == 'c') {
                result += w - last_char.value_or(w - 3) - 1;
                last_char = std::nullopt;
            } else {
                if (last_char.has_value()) {
                    if (*last_char == w) {
                        result += 2;
                    } else if (*last_char == 'b' && w == 'a') {
                        result += 1;
                    }
                } else {
                    result += w - 'a';
                }
                last_char = w;
            }
        }
        result += 'c' - last_char.value_or('c');
        return result;        
    }
};
// @lc code=end

