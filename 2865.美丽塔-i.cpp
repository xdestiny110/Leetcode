/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */

// @lc code=start
#include <vector>

class Solution {
public:
    long long maximumSumOfHeights(std::vector<int>& maxHeights) {
        long long max_total_height = 0;
        for (int max_height_idx = 0; max_height_idx < maxHeights.size(); ++max_height_idx) {
            int current_max_height = maxHeights[max_height_idx];
            long long total_height = current_max_height;
            for (int i = max_height_idx - 1; i >= 0; --i) {
                if (maxHeights[i] < current_max_height) {
                    current_max_height = maxHeights[i];
                }
                total_height += current_max_height;
            }
            current_max_height = maxHeights[max_height_idx];
            for (int i = max_height_idx + 1; i < maxHeights.size(); ++i) {
                if (maxHeights[i] < current_max_height) {
                    current_max_height = maxHeights[i];
                }
                total_height += current_max_height;
            }
            max_total_height = std::max(max_total_height, total_height);
        }
        return max_total_height;
    }
};
// @lc code=end

