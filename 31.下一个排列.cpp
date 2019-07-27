/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
        int k = -1;
        for(int i = 0; i < nums.size()-1;i++){
            if(nums[i] < nums[i+1])
                k = i;
        }
        if(k < 0){
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int l = -1;
        for(int i = k+1;i < nums.size();i++){
            if(nums[k] < nums[i])
                l = i;
        }
        std::swap(nums[k], nums[l]);
        std::reverse(nums.begin()+k+1, nums.end());
    }
};

