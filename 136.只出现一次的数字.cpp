/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ret = 0;
        for(const auto& it : nums){
            ret ^= it;
        }
        return ret;
    }
};
// @lc code=end

