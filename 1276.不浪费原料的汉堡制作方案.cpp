/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        auto x = tomatoSlices / 2 - cheeseSlices;
        auto y = 2 * cheeseSlices - tomatoSlices / 2;
        if (tomatoSlices % 2 != 0 || x < 0 || y < 0) {
            return {};
        }
        return {x, y};
    }
};
// @lc code=end

