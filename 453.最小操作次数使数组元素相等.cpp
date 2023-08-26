/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        auto min_num = *std::min_element(nums.begin(), nums.end());
        int counts = 0;
        for (auto n : nums) {
            counts += n - min_num;
        }
        return counts;
    }
};
// @lc code=end

