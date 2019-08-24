/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if(nums.size() <= 1){
            return true;
        }

        int maxReach = nums[0];
        for(int i = 1; i <= maxReach; i++){
            maxReach = std::max(nums[i]+i, maxReach);
            if(maxReach >= nums.size()-1)
                return true;
        }
        return false;
    }
};

