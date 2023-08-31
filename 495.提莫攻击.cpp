/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        auto result = 0;
        auto t_start = -1, t_end = -1;
        for (auto time : timeSeries) {
            if (time > t_end) {
                t_start = time;
                t_end = time + duration - 1;
                result += duration;
            } else {
                result -= t_end - t_start + 1;
                t_end = time + duration - 1;
                result += t_end - t_start + 1;
            }

        }
        return result;
    }
};
// @lc code=end

