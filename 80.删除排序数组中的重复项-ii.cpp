/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include <vector>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty())
            return 0;
        int cnt = 1;
        int head = 1;
        int lastNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != lastNum){
                lastNum = nums[i];
                cnt = 1;
                nums[head++] = nums[i];
            }
            else{
                if(cnt >= 2){
                    continue;
                }
                else{
                    cnt++;
                    nums[head++] = nums[i];
                }
            }
        }
        return head;
    }
};
// @lc code=end

