/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 *
 * [2760] 最长奇偶子数组
 */

// @lc code=start

#include <vector>
#include <optional>

class Solution {
public:
    int longestAlternatingSubarray(const std::vector<int>& nums, int threshold) const {
        std::optional<size_t> l = std::nullopt;
        int max_len = 0;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (l.has_value()) {
                if (nums[i] > threshold || nums[i] % 2 == nums[i - 1] % 2) {
                    max_len = std::max<int>(max_len, i - *l);
                    l = std::nullopt;
                }
            }
            if (!l.has_value()) {
                if (nums[i] <= threshold && nums[i] % 2 == 0) {
                    l = i;
                }
            }
        }
        if (l.has_value())
            max_len = std::max<int>(max_len, nums.size() - *l);
        return max_len;
    }
};
// @lc code=end

