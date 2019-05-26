/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int n = nums[0];
        for(auto it = nums.begin()+1;it != nums.end();){
            if(*it == n)
                it = nums.erase(it);
            else{
                n = *it;
                it++;
            }
        }
        return nums.size();
    }
};

