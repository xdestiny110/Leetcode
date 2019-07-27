/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if(nums.empty())
            return std::vector<int>{-1, -1};
        return binarySearch(nums, target, 0, nums.size()-1);
    }
private:
    std::vector<int> binarySearch(const std::vector<int>& nums, int target, int left, int right){
        if(nums[left] == target)
            return findLR(nums, target, left);
        if(nums[right] == target)
            return findLR(nums, target, right);
        
        if(right - left <= 1)
            return std::vector<int>{-1, -1};
        int pos = (left+right)/2;
        if(nums[pos] > target)
            return binarySearch(nums, target, left, pos);
        return binarySearch(nums, target, pos, right);
    }

    std::vector<int> findLR(const std::vector<int>& nums, int target, int bound){
        int i = bound;
        while(i >= 0 && nums[i] == target){
            i--;
        }
        int start = i+1;

        i = bound;
        while (i < nums.size() && nums[i] == target){
            i++;
        }
        int end = i-1;
        return std::vector<int>{start, end};
    }
};

