/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 *
 * [2915] 和为目标值的最长子序列的长度
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    int lengthOfLongestSubsequence(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(target + 1, -1));
        if (nums[0] <= target)
            dp[0][nums[0]] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (j - nums[i] < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (j == nums[i])
                {
                    dp[i][j] = std::max(dp[i - 1][j], 1);
                }
                else if (dp[i - 1][j - nums[i]] > 0)
                {
                    dp[i][j] = std::max(dp[i - 1][j - nums[i]] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
