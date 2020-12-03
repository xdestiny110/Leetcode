/*
 * @lc app=leetcode.cn id=1503 lang=cpp
 *
 * [1503] 所有蚂蚁掉下来前的最后一刻
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        // 寻找最大值, 脑筋急转弯...
        auto leftMax = left.empty() ? 0 : *std::max_element(left.begin(), left.end());
        auto rightMax = right.empty() ? 0 : n - *std::min_element(right.begin(), right.end());
        return std::max(leftMax, rightMax);
    }
};
// @lc code=end

