/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子序列
 */

// @lc code=start
#include <vector>
#include <optional>

class Solution {
public:
    int alternatingSubarray(std::vector<int>& nums) {
        int max_length = -1;
        std::optional<int> predict_num = std::nullopt;
        int length = -1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (predict_num.has_value() && *predict_num == nums[i]) {
                length++;
                predict_num = nums[i - 1];
            } else if (nums[i] - nums[i - 1] == 1) {
                length = 2;
                predict_num = nums[i - 1];
            } else {
                predict_num = std::nullopt;
                length = -1;
            }
            max_length = std::max(max_length, length);
        }
        return max_length;
    }
};
// @lc code=end

