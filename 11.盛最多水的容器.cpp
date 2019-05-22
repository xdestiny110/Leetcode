/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0, right = height.size()-1;
        while(left < right){
            maxWater = (maxWater < (right-left)*std::min(height[left], height[right]))?(right-left)*std::min(height[left], height[right]):maxWater;
            if(height[left] < height[right]){
                for(int i = 1; i <= right-left; i++){
                    if(height[left+i] >= height[left]){
                        left = left+i;
                        break;
                    }
                }
            }
            else{
                for(int i = 1; i <= right-left; i++){
                    if(height[right-i] >= height[right]){
                        right = right-i;
                        break;
                    }
                }
            }
        }
        return maxWater;
    }
};

