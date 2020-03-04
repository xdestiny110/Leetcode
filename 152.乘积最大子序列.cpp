/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        std::vector<int> numsMax(nums.size());
        std::vector<int> numsMin(nums.size());

        numsMax[0] = nums[0];
        numsMin[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            numsMax[i] = std::max(std::max(nums[i], nums[i] * numsMax[i-1]), nums[i] * numsMin[i-1]);
            numsMin[i] = std::min(std::min(nums[i], nums[i] * numsMax[i-1]), nums[i] * numsMin[i-1]);
        }
        return *(std::max_element(numsMax.begin(), numsMax.end()));
    }
};
// @lc code=end

