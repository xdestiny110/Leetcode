/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
// 将对应的数字移动到下标对应的位置，并判断是否相等。如果相等则肯定是重复数据

#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        std::vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i != nums[i] - 1) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
// @lc code=end

