/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 *
 * [2859] 计算 K 置位下标对应元素的和
 */

// @lc code=start
#include <vector>
#include <bitset>

class Solution {
public:
    int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            std::bitset<32> b(i);
            if (b.count() == k) {
                result += nums[i];
            }
        }
        return result;
    }
};
// @lc code=end

