/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string capitalizeTitle(std::string title) {
        size_t last_p = 0;
        auto p = title.find(' ');
        while (p < title.size()) {
            capitalize_substr(title, last_p, p);
            p++;
            last_p = p;
            p = title.find(' ', p);
        }
        capitalize_substr(title, last_p, title.size());
        return title;
    }

private:
    void capitalize_substr(std::string& title, size_t s, size_t e) const {
        if (e - s > 2) {
            title[s] = std::toupper(title[s]);
            s++;
        }
        for (auto i = s; i < e; ++i) {
            title[i] = std::tolower(title[i]);
        }
    }
};
// @lc code=end

