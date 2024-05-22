/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */

// @lc code=start
#include <optional>
#include <queue>
#include <vector>

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        // 耗时最长工作所需周数
        long long longest = *max_element(milestones.begin(), milestones.end());
        // 其余工作共计所需周数
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
        if (longest > rest + 1){
            // 此时无法完成所耗时最长的工作
            return rest * 2 + 1;
        }
        return longest + rest;
    }
};
// @lc code=end

