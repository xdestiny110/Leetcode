/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        std::vector<int> f(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i])
                    f[i] = std::max(f[i], f[j] + 1);
            }
        }
        return *std::max_element(f.begin(), f.end());
    }
};
// @lc code=end

