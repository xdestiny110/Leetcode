/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        size_t edge_len = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    // up
                    if (i == 0 || grid[i-1][j] == 0) {
                        edge_len++;
                    }
                    // left
                    if (j == 0 || grid[i][j-1] == 0) {
                        edge_len++;
                    }
                    // down
                    if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
                        edge_len++;
                    }
                    // right
                    if (j == grid[0].size() - 1 || grid[i][j+1] == 0) {
                        edge_len++;
                    }
                }
            }
        }
        return edge_len;
    }
};
// @lc code=end

