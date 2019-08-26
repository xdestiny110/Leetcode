/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        std::vector<std::vector<unsigned long long>> f;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        f.reserve(m);
        for(int i = 0;i < m; i++){
            f.emplace_back(n,0);
        }

        f[0][0] = (obstacleGrid[0][0] != 1)?1:0;
        for(int r = 1; r < m; r++)
            f[r][0] = (obstacleGrid[r][0] != 1)?f[r-1][0]:0;
        for(int c = 1; c < n; c++)
            f[0][c] = (obstacleGrid[0][c] != 1)?f[0][c-1]:0;
        for(int r = 1; r < m; r++){
            for(int c = 1; c < n; c++){
                f[r][c] = (obstacleGrid[r][c] != 1)?f[r][c-1]+f[r-1][c]:0;
            }
        }
        return f.back().back();
    }
};

