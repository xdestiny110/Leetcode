/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> f(nums.size());
        f[0] = nums[0];
        for(int i = 1;i < nums.size(); i++){
            f[i] = std::max(nums[i], f[i-1]+nums[i]);
        }
        return *std::max_element(f.begin(), f.end());
    }
};

