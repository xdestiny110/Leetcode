/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        return binarySearch(nums, 0, nums.size()-1, target);
    }
private:
    int binarySearch(const std::vector<int>& nums, int left, int right, int target){
        if(right - left <= 1)
        {
            if(nums[left] == target)
                return left;
            else if(nums[right] == target)
                return right;
            else
                return -1;
        }

        int mid = (left+right)/2;
        if(nums[left] == target)
            return left;
        else if(nums[right] == target)
            return right;
        else if(nums[mid] == target)
            return mid;

        if(nums[mid] > nums[left]){
            if((target > nums[mid]) || (target < nums[left]))
                return binarySearch(nums, mid, right, target);
            else
                return binarySearch(nums, left, mid, target);
        }
        else{ // nums[mid] < nums[right]
            if((target > nums[left]) || (target < nums[mid]))
                return binarySearch(nums ,left, mid, target);
            else
                return binarySearch(nums, mid, right, target);
        }
        return -1;
    }
};
