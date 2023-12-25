/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
#include <string>
#include <optional>
#include <string_view>

class Solution {
public:
    std::string entityParser(const std::string& text) {
        std::string result;
        result.reserve(text.size());
        int i = 0;
        while (i < text.size()) {
            if (text[i] == '&') {
                auto last_i = i;
                i++;
                while (last_i >= 0) {
                    for (;i < text.size() && text[i] != ';' && text[i] != '&'; ++i);
                    if (i == text.size() || text[i] == '&') {
                        result.append(text.begin() + last_i, text.begin() + i);
                        if (i == text.size()) {
                            return result;
                        } else {
                            last_i = i;
                            i++;
                            continue;
                        }
                    }
                    break;
                }
                std::string_view sv(text.begin() + last_i, text.begin() + i + 1);
                if (sv == "&quot;") {
                    result.push_back('"');
                } else if (sv == "&apos;") {
                    result.push_back('\'');
                } else if (sv == "&amp;") {
                    result.push_back('&');
                } else if (sv == "&gt;") {
                    result.push_back('>');
                } else if (sv == "&lt;") {
                    result.push_back('<');
                } else if (sv == "&frasl;") {
                    result.push_back('/');
                } else {
                    result.append(sv);
                }
            } else {
                result.push_back(text[i]);
            }
            ++i;
        }
        return result;
    }
};
// @lc code=end

