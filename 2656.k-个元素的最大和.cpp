/*
 * @lc app=leetcode.cn id=2656 lang=cpp
 *
 * [2656] K 个元素的最大和
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_num = *std::max_element(nums.begin(), nums.end());
        return (max_num + max_num + k - 1) * k / 2;
    }
};
// @lc code=end

