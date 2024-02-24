/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start

#include <map>
#include <string>

class Solution {
public:
    std::string repeatLimitedString(const std::string& s, int repeatLimit) {
        std::map<char, int, std::greater<>> m;
        for (auto c : s) {
            m[c]++;
        }

        std::string result;
        result.reserve(s.size());
        while (!m.empty()) {
            if (m.begin()->second > repeatLimit) {
                result.insert(result.end(), repeatLimit, m.begin()->first);
                m.begin()->second -= repeatLimit;
                if (m.size() >= 2) {
                    auto it = m.begin();
                    it++;
                    result.push_back(it->first);
                    it->second--;
                    if (it->second == 0) {
                        m.erase(it);
                    }
                } else {
                    break;
                }
            } else {
                result.insert(result.end(), m.begin()->second, m.begin()->first);
                m.erase(m.begin());
            }
        }
        return result;
    }
};
// @lc code=end

