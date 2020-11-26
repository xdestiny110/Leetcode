/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int idx = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                idx = std::min(idx, i);
                continue;
            }
            if(idx < nums.size()){
                std::swap(nums[i], nums[idx]);
                idx++;
            }
        }
    }
};
// @lc code=end

