/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start

#include <string>
#include <array>
#include <unordered_set>

class Solution {
public:
    int countPoints(std::string rings) {
        std::array<std::unordered_set<char>, 10> sticks;
        for (auto it = rings.begin(); it != rings.end(); ++it) {
            auto color = *it;
            it++;
            sticks[*it - '0'].insert(color);
        }
        return std::count_if(sticks.begin(), sticks.end(), [](const auto& s) {
            return s.size() >= 3;
        });
    }
};
// @lc code=end

