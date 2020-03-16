/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start

#include <vector>
#include <algorithm>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        auto f1 = std::make_pair(0, nums[0]);
        auto f2 = std::make_pair(0, nums[1]);
        for(int i = 1; i < nums.size() - 1; ++i){
            auto ff = std::make_pair(std::max(f1.first, f1.second), nums[i] + f1.first);
            f1 = std::move(ff);

            ff.first = std::max(f2.first, f2.second);
            ff.second = nums[i+1] + f2.first;
            f2 = std::move(ff);
        }
        return std::max(std::max(f1.first, f1.second), std::max(f2.first, f2.second));
    }
};
// @lc code=end

