/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<uint64_t> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; ++t) {
            for (auto num : nums) {
                if (num > t) {
                    break;
                }
                dp[t] += dp[t - num];
            }
        }
        return dp.back();
    }
};
// @lc code=end

