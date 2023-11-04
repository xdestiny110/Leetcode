/*
 * @lc app=leetcode.cn id=2919 lang=cpp
 *
 * [2919] 使数组变美的最小增量运算数
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    long long minIncrementOperations(std::vector<int> &nums, int k)
    {
        std::vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i] = std::max(0, k - nums[i]);
        }
        std::vector<std::array<long long, 4>> f(nums.size() - 2);
        f[0][0] = dp[0];
        f[0][1] = dp[1];
        f[0][2] = dp[2];
        for (int i = 1; i < nums.size() - 2; ++i)
        {
            f[i][0] = std::min(std::min(f[i - 1][1], f[i - 1][2] + dp[i]), f[i - 1][0] + dp[i]);
            f[i][1] = std::min(std::min(f[i - 1][2], f[i - 1][0] + dp[i + 1]), f[i - 1][0] + dp[i + 1]);
            f[i][2] = dp[i + 2] + std::min(std::min(f[i - 1][0], f[i - 1][1]), f[i - 1][2]);
        }
        return std::min(std::min(f.back()[0], f.back()[1]), f.back()[2]);
    }
};
// @lc code=end
