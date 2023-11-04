/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts) {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        uint64_t max_w = std::max(verticalCuts[0], w - verticalCuts.back());
        uint64_t max_h = std::max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_h = std::max<uint64_t>(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            max_w = std::max<uint64_t>(max_w, verticalCuts[i] - verticalCuts[i - 1]);
        }
        constexpr uint64_t mod = 1e9 + 7;
        return ((max_w % mod) * (max_h % mod)) % mod;
    }
};
// @lc code=end

