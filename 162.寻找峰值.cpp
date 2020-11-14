/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return binarySearch(0, nums.size() - 1, nums);
    }

private:
    int binarySearch(int left, int right, const std::vector<int>& nums){
        auto mid = (left + right) / 2;
        if((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) || (mid != 0 && mid != nums.size() - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])){
            return mid;
        }

        if(mid == 0) 
            return binarySearch(mid + 1, right, nums);
        else if (mid == nums.size() - 1)
            return binarySearch(left, mid - 1, nums);
        return (nums[mid - 1] > nums[mid + 1]) ? binarySearch(left, mid - 1, nums) : binarySearch(mid + 1, right, nums);
    }
};

// @lc code=end

