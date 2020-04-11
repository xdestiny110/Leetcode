/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r = 0;
        for(int i = 0; i < nums.size(); ++i){
            r ^= nums[i];
            r ^= i;
        }
        r ^= nums.size();
        return r;
    }
};
// @lc code=end

