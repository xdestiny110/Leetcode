/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        std::vector<int> record(3, 0);
        for(const auto& it : nums)
            record[it]++;

        for(int i = 0; i < nums.size(); i++){
            if(i+1 <= record[0])
                nums[i] = 0;
            else if(i+1 <= record[0]+record[1])
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

