/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    long long findTheArrayConcVal(std::vector<int>& nums) {
        long long result = 0;
        int head = 0, tail = nums.size() - 1;
        while (head < tail) {
            result += std::stoll(std::to_string(nums[head++]) + std::to_string(nums[tail--]));
        }
        if (head == tail) {
            result += nums[head];
        }
        return result;
    }
};
// @lc code=end

