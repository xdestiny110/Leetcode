/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include <numeric>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double max_sum = sum * 1.0 / k;
        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i - k] + nums[i];
            max_sum = std::max(max_sum, sum * 1.0 / k);
        }
        return max_sum;
    }
};
// @lc code=end

