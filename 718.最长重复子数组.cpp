/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int result = 0;
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(), 0));
        for (size_t i = 0; i < nums1.size(); ++i) {
            dp[i][0] = (nums1[i] == nums2[0]) ? 1 : 0;
            result = std::max(result, dp[i][0]);
        }
        for (size_t i = 0; i < nums2.size(); ++i) {
            dp[0][i] = (nums1[0] == nums2[i]) ? 1 : 0;
            result = std::max(result, dp[0][i]);
        }

        for (size_t i = 1; i < nums1.size(); ++i) {
            for (size_t j = 1; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = std::max(result, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};
// @lc code=end

