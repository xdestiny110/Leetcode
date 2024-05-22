/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start

#include <queue>
#include <vector>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        size_t fresh_cnt = 0;
        std::queue<std::pair<size_t, size_t>> rot_oranges;

        for (size_t r = 0; r < m; ++r) {
            for (size_t c = 0; c < n; ++c) {
                switch (grid[r][c]) {
                    case 1: {
                        fresh_cnt++;
                        break;
                    }
                    case 2: {
                        rot_oranges.push({r, c});
                        break;
                    }
                }
            }
        }

        int cost_time = 0;
        for (;;) {
            bool is_make_rot = false;
            decltype(rot_oranges) rot_oranges_new;
            while (!rot_oranges.empty()) {
                auto [rot_coor_r, rot_coor_c] = rot_oranges.front();
                rot_oranges.pop();

                if (rot_coor_r > 0 && grid[rot_coor_r - 1][rot_coor_c] == 1) {
                    is_make_rot = true;
                    grid[rot_coor_r - 1][rot_coor_c] = 2;
                    rot_oranges_new.push({rot_coor_r - 1, rot_coor_c});
                    fresh_cnt--;
                }
                if (rot_coor_c > 0 && grid[rot_coor_r][rot_coor_c - 1] == 1) {
                    is_make_rot = true;
                    grid[rot_coor_r][rot_coor_c - 1] = 2;
                    rot_oranges_new.push({rot_coor_r, rot_coor_c - 1});
                    fresh_cnt--;
                }
                if (rot_coor_r < m - 1 && grid[rot_coor_r + 1][rot_coor_c] == 1) {
                    is_make_rot = true;
                    grid[rot_coor_r + 1][rot_coor_c] = 2;
                    rot_oranges_new.push({rot_coor_r + 1, rot_coor_c});
                    fresh_cnt--;
                }
                if (rot_coor_c < n - 1 && grid[rot_coor_r][rot_coor_c + 1] == 1) {
                    is_make_rot = true;
                    grid[rot_coor_r][rot_coor_c + 1] = 2;
                    rot_oranges_new.push({rot_coor_r, rot_coor_c + 1});
                    fresh_cnt--;
                }
            }
            if (is_make_rot) {
                cost_time++;
                std::swap(rot_oranges_new, rot_oranges);
            }
            else
                break;
        }
        return fresh_cnt > 0 ? -1 : cost_time;
    }
};
// @lc code=end

