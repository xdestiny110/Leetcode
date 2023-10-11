/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
#include <string>
#include <algorithm>

class Solution {
public:
    int splitNum(int num) {
        auto num_str = std::to_string(num);
        std::sort(num_str.begin(), num_str.end());
        int num1 = 0, num2 = 0;
        for (auto ch : num_str) {
            num1 = num1 * 10 + ch - '0';
            std::swap(num1, num2);
        }
        return num1 + num2;
    }
};
// @lc code=end

