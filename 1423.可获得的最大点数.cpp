/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
#include <vector>
#include <numeric>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        std::vector<int> presum(cardPoints.size(), 0);
        presum[0] = cardPoints[0];
        for (int i = 1; i < cardPoints.size(); ++i) {
            presum[i] = cardPoints[i] + presum[i - 1];
        }

        auto left_card_num = cardPoints.size() - k;
        if (left_card_num == 0) return presum.back();
        auto result = std::numeric_limits<int>::max();
        for (int left_idx = 0; left_idx <= k; ++left_idx) {
            auto right_idx = left_idx + left_card_num - 1;
            result = std::min(result, presum[right_idx] - ((left_idx > 0) ? presum[left_idx - 1] : 0));
        }
        return presum.back() - result;
    }
};
// @lc code=end

