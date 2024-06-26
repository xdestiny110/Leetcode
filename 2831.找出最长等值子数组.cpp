/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */

// @lc code=start

#include <unordered_map>
#include <vector>

class Solution {
public:
    int longestEqualSubarray(const std::vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> num_indices;
        for (int idx = 0; idx < nums.size(); ++idx) {
            num_indices[nums[idx]].push_back(idx);
        }

        int max_length = 1;
        for (const auto& [_, v] : num_indices) {
            if (v.size() == 1) continue;
            int left = 0, right = 1;
            while (right < v.size()) {
                if (left == right) {
                    right++;
                    continue;
                }
                if (v[right] - v[left] - 1 - (right - left - 1) <= k) {
                    max_length = std::max(max_length, right - left + 1);
                    right++;
                } else {
                    left++;
                }
            }
        }
        return max_length;
    }
};
// @lc code=end

