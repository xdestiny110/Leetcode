/*
 * @lc app=leetcode.cn id=2651 lang=cpp
 *
 * [2651] 计算列车到站时间
 */

// @lc code=start
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
// @lc code=end

