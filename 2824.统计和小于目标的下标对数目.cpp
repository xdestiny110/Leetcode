/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] < target) {
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

