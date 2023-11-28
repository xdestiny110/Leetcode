/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 *
 * [2304] 网格中的最小路径代价
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost) {
        std::vector<std::vector<int>> dp(grid.size());
        dp[0].resize(grid[0].size(), 0);
        for (int i = 0; i < grid[0].size(); ++i) {
            dp[0][i] = grid[0][i];
        }

        for (int r = 1; r < grid.size(); ++r) {
            dp[r].resize(grid[r].size(), 0);
            for (int c = 0; c < grid[r].size(); ++c) {
                int min_cost = std::numeric_limits<int>::max();
                for (int k = 0; k < grid[r - 1].size(); ++k) {
                    auto last_node_idx = grid[r - 1][k];
                    min_cost = std::min(min_cost, dp[r - 1][k] + moveCost[last_node_idx][c]);
                }
                dp[r][c] = min_cost + grid[r][c];
            }
        }
        return *std::min_element(dp.back().begin(), dp.back().end());
    }
};
// @lc code=end

