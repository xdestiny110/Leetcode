/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 *
 * [2639] 查询网格图中每一列的宽度
 */

// @lc code=start

#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) {
        std::vector<int> result;
        size_t rows = grid.size();
        size_t cols = grid[0].size();
        for (size_t c = 0; c < cols; ++c) {
            result.push_back(std::to_string(grid[0][c]).size());
            for (size_t r = 1; r < rows; ++r) {
                result.back() = std::max<int>(result.back(), std::to_string(grid[r][c]).size());
            }
        }
        return result;
    }
};
// @lc code=end

