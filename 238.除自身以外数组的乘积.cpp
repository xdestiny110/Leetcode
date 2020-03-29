/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start

#include <vector>

// 1 1 12 123
// 234 34 4 4

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> r1(nums.size());
        r1[0] = 1;
        for(int i = 1; i < r1.size(); ++i){
            r1[i] = nums[i-1] * r1[i-1];
        }
        r1[0] = nums[0];

        std::vector<int> r2(nums.size());
        r2.back() = 1;
        for(int i = r2.size() - 2; i >= 0; --i){
            r2[i] = r2[i+1] * nums[i+1];
        }
        r2.back() = nums.back();

        for(int i = 1; i < r1.size() - 1; ++i){
            r1[i] *= r2[i];
        }
        r1[0] = r2[0];
        return r1;
    }
};
// @lc code=end

