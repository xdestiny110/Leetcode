/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 *
 * [1267] 统计参与通信的服务器
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        std::unordered_map<int, int> x, y;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    y[j]++;
                    x[i]++;
                }
            }
        }

        int count = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1 && (x[i] > 1 || y[j] > 1)) {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

