/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == '1'){
                    ret++;
                    DFS(grid, r, c);
                }
            }
        }
        return ret;
    }

private:
    int ret = 0;
    void DFS(std::vector<std::vector<char>>& grid, int r, int c){
        grid[r][c] = '0';
        if(r >= 1 && grid[r-1][c] == '1'){
            DFS(grid, r-1, c);
        }
        if(r < grid.size() - 1 && grid[r+1][c] == '1'){
            DFS(grid, r+1, c);
        }
        if(c >= 1 && grid[r][c-1] == '1'){
            DFS(grid, r, c-1);
        }
        if(c < grid[0].size() - 1 && grid[r][c+1] == '1'){
            DFS(grid, r, c+1);
        }
    }
};
// @lc code=end

