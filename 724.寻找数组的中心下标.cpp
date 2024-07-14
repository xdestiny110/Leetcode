/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        std::vector<int> presum(nums.size(), 0);
        presum[0] = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }

        for (size_t center = 0; center < nums.size(); ++center) {
            if (presum.back() - presum[center] == (center == 0 ? 0 : presum[center - 1])) {
                return center;
            }
        }
        return -1;
    }
};
// @lc code=end

