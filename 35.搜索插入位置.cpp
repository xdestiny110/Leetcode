/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(nums.empty() || nums[0] >= target)
            return 0;
        if(nums.back() == target)
            return nums.size()-1;
        if(nums.back() < target)
            return nums.size();
        return binarySearch(nums, target, 0, nums.size());
    }
private:
    int binarySearch(const std::vector<int>& nums, int target, int left, int right){
        if(right-left <= 1)
            return right;
        int mid = (left+right)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            return binarySearch(nums, target, left, mid);
        return binarySearch(nums, target, mid, right);
    }
};

