/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 *
 * [1402] 做菜顺序
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) const {
        std::sort(satisfaction.begin(), satisfaction.end(), std::greater<int>());
        int result = std::max(0, satisfaction[0]);
        int last_result = satisfaction[0];
        int presum = satisfaction[0];
        for (int i = 1; i < satisfaction.size(); ++i) {
            presum += satisfaction[i];
            last_result += presum;
            result = std::max(result, last_result);
        }
        return result;
    }
};
// @lc code=end

