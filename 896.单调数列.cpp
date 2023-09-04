/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start

#include <vector>
#include <optional>

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        if (nums.size() <= 2) return true;
        std::optional<bool> is_inc = std::nullopt;
        for (int i = 1; i < nums.size(); ++i) {
            if (!is_inc.has_value()) {
                if (nums[i] > nums[i - 1]) {
                    is_inc = true;
                } else if (nums[i] < nums[i - 1]) {
                    is_inc = false;
                }
            } else {
                if ((*is_inc && nums[i] < nums[i - 1]) || (!*is_inc && nums[i] > nums[i - 1])) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

