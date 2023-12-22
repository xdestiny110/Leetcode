/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int minimumMountainRemovals(const std::vector<int>& nums) {
        std::vector<int> up(nums.size(), 1);
        for(int i = 1; i < nums.size() - 1; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    up[i] = std::max(up[j] + 1, up[i]);
                }
            }
        }

        std::vector<int> down(nums.size(), 1);
        for(int i = nums.size() - 2; i > 0; --i){
            for(int j = nums.size() - 1; j > i; --j){
                if(nums[i] > nums[j]){
                    down[i] = std::max(down[j] + 1, down[i]);
                }
            }
        }

        int maxLen = 0;
        for(int i = 1; i < nums.size() - 1; ++i){
            if (up[i] == 1 || down[i] == 1) continue;
            maxLen = std::max(maxLen, up[i] + down[i] - 1);
        }
        return nums.size() - maxLen;
    }
};
// @lc code=end

