/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        dfs(0, nums, 0, target);
        return result;
    }

private:
    int result = 0;

    void dfs(size_t idx, const std::vector<int>& nums, int current_sum, int target) {
        if (idx >= nums.size()) {
            if (target == current_sum) {
                result++;
            }
            return;
        }
        for (int i = 0; i <= 1; ++i) {
            if (i == 0) {
                dfs(idx + 1, nums, current_sum + nums[idx], target);
            } else {
                dfs(idx + 1, nums, current_sum - nums[idx], target);
            }
        }
    }
};
// @lc code=end

