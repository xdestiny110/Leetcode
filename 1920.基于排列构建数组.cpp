/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};
// @lc code=end

