/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start

#include <string>

class Solution {
public:
    std::string categorizeBox(int length, int width, int height, int mass) {
        bool is_heavy = mass >= 100;
        constexpr int threshold = 10'000;
        bool is_bulky = (length >= threshold || width >= threshold || height >= threshold || (width * 1ULL * height * length >= 1'000'000'000ULL));
        if (is_heavy) {
            return is_bulky ? "Both" : "Heavy";
        }
        return is_bulky ? "Bulky" : "Neither";
    }
};
// @lc code=end

