/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;

        const int m = grid.size();
        const int n = grid[0].size();
        std::vector<std::vector<int>> f;
        for(int i = 0;i < m; i++)
            f.emplace_back(n, 0);
        
        f[0][0] = grid[0][0];
        for(int r = 1; r < m; r++)
            f[r][0] = grid[r][0] + f[r-1][0];
        for(int c = 1; c < n; c++)
            f[0][c] = grid[0][c] + f[0][c-1];

        for(int r = 1; r < m; r++){
            for(int c = 1; c < n; c++){
                f[r][c] = grid[r][c]+std::min(f[r-1][c], f[r][c-1]);
            }
        }

        return f.back().back();
    }
};

