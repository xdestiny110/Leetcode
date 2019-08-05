/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <vector>


class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ret = calcWater(height, 0, height.size()-1);
        // while (left < right)
        // {
        //     if(calcWater(height, ))
        // }
        
    }

private:
    int calcWater(const std::vector<int>& height, int left, int right){
        int width = right-left-1;
        return std::min(height[left], height[right]);
    }

    std::vector<int>& t;
};

