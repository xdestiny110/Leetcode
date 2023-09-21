/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int minCapability(std::vector<int>& nums, int k) {
        int left = *std::min_element(nums.begin(), nums.end());
        int right = *std::max_element(nums.begin(), nums.end());
        std::vector<int> dp;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            dp = std::vector<int>(nums.size() + 2, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                dp[i + 2] = dp[i + 1];
                if (nums[i] <= mid)
                    dp[i + 2] = max(dp[i + 2], dp[i] + 1);
            }

            if (dp[nums.size() + 1] >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

