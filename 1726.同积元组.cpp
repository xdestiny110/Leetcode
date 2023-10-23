/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    int tupleSameProduct(const std::vector<int>& nums) const {
        if (nums.size() <= 3) return 0;
        std::unordered_map<int, int> product_cnt;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                product_cnt[nums[i] * nums[j]]++;
            }
        }

        int result = 0;
        for (const auto& [k, v] : product_cnt) {
            if (v > 1) {
                result += v * (v - 1) / 2 * 8;
            }
        }
        return result;
    }
};
// @lc code=end

