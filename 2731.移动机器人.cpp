/*
 * @lc app=leetcode.cn id=2731 lang=cpp
 *
 * [2731] 移动机器人
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int sumDistance(std::vector<int>& nums, const string& s, int d) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] += (s[i] == 'R') ? d : -d;
        }
        std::sort(nums.begin(), nums.end());
        auto result = 0LL;
        constexpr int64_t mod = 1e9 + 7;
        for (int i = 1; i < nums.size(); ++i) {
            result += (1ll * nums[i] - nums[i - 1]) * i % mod * (nums.size() - i) % mod;
        }
        return result % mod;
    }
};
// @lc code=end
