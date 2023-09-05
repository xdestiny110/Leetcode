/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start

#include <vector>
#include <set>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        if (nums.empty()) { return 0; }
        if (nums.size() == 1) { return 1; }
        int head = 0, tail = 1;
        std::multiset<int> record;
        record.insert(nums[head]);
        record.insert(nums[tail]);
        int result = 1;
        while (tail < nums.size()) {
            if (std::abs(*record.begin() - *record.rbegin()) > limit) {
                if (auto it = record.find(nums[head]); it != record.end()) {
                    record.erase(it);
                }                
                head++;
            } else {
                result = std::max(tail - head + 1, result);
                tail++;
                if (tail >= nums.size()) {
                    break;
                }
                record.insert(nums[tail]);
            }
        }
        return result;
    }
};
// @lc code=end

