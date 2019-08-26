/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> f;
        f.reserve(m);
        for(int i = 0;i < m; i++){
            f.emplace_back(n);
        }

        f[0][0] = 1;
        for(int r = 1; r < m; r++)
            f[r][0] = f[r-1][0];
        for(int c = 1; c < n; c++)
            f[0][c] = f[0][c-1];
        for(int r = 1; r < m; r++){
            for(int c = 1; c < n; c++){
                f[r][c] = f[r][c-1]+f[r-1][c];
            }
        }
        return f.back().back();
    }
};

