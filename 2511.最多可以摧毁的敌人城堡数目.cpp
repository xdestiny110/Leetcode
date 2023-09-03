/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

// @lc code=start

#include <vector>
#include <optional>

class Solution {
public:
    int captureForts(std::vector<int>& forts) {
        int result = 0;
        std::optional<size_t> start_idx = std::nullopt;
        for (size_t idx = 0; idx < forts.size(); ++idx) {
            if (!start_idx.has_value()) {
                if (forts[idx] != 0) {
                    start_idx = idx;
                }
            } else {
                if (forts[idx] != 0) {
                    if (forts[idx] * forts[*start_idx] < 0) {
                        result = std::max<int>(result, idx - *start_idx - 1);
                    }
                    start_idx = idx;
                }
            }
        }
        return result;
    }
};
// @lc code=end

