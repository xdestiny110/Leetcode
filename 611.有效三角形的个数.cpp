/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int result = 0;
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) continue;
            for (size_t j = i + 1; j < nums.size() - 1; ++j) {
                auto it = std::lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]);
                auto jt = nums.begin();
                std::advance(jt, j);;
                result += std::distance(jt, it) - 1;
            }
        }
        return result;
    }
};
// @lc code=end

