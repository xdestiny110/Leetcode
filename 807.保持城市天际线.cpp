/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        auto n = grid.size();
        std::vector<std::pair<int, int>> grid_max(n, std::make_pair(0, 0));
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col < n; ++col) {
                grid_max[row].first = grid_max[row].first < grid[row][col] ? grid[row][col] : grid_max[row].first;
                grid_max[col].second = grid_max[col].second < grid[row][col] ? grid[row][col] : grid_max[col].second;
            }
        }

        int result = 0;
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col < n; ++col) {
                result += std::min(grid_max[row].first, grid_max[col].second) - grid[row][col];
            }
        }
        return result;
    }
};
// @lc code=end

