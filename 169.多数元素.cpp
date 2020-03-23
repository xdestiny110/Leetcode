/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        auto ret = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != ret){
                cnt--;
                if(cnt < 0){
                    cnt = 1;
                    ret = nums[i];
                }
            }
            else{
                cnt++;
            }
        }
        return ret;
    }
};
// @lc code=end

