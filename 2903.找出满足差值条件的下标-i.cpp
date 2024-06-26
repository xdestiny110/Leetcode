/*
 * @lc app=leetcode.cn id=2903 lang=cpp
 *
 * [2903] 找出满足差值条件的下标 I
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> findIndices(const std::vector<int>& nums, int indexDifference, int valueDifference) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (std::abs(i - j) >= indexDifference && std::abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

