/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        auto it = std::lower_bound(nums.begin(), nums.end(), 0);
        size_t neg_cnt = std::distance(nums.begin(), it);
        auto jt = std::upper_bound(nums.begin(), nums.end(), 0);
        size_t pos_cnt = std::distance(jt, nums.end());
        return std::max(neg_cnt, pos_cnt);
    }
};
// @lc code=end

