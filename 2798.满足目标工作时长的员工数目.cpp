/*
 * @lc app=leetcode.cn id=2798 lang=cpp
 *
 * [2798] 满足目标工作时长的员工数目
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {
        return std::count_if(hours.begin(), hours.end(), [target](int h) {
            return h >= target;
        });
    }
};
// @lc code=end

