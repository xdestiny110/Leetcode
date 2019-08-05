/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int jumpCnt = 1;
        int currentMaxReach = nums[0];
        int nextMaxReach = -1;
        for(int i = 1;i < nums.size()-1; i++){
            nextMaxReach = std::max(nextMaxReach, nums[i]+i);
            if(i == currentMaxReach){
                jumpCnt++;
                currentMaxReach = nextMaxReach;
                nextMaxReach = -1;
            }
        }
        return jumpCnt;
    }
};

