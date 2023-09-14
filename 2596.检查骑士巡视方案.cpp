/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_set>

struct Node {
    int step_;
    int row_;
    int col_;

    bool operator>(const Node& rhs) const {
        return step_ > rhs.step_;
    }
};

class Solution {
public:
    bool checkValidGrid(std::vector<std::vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                q.push(Node {
                    .step_ = grid[row][col],
                    .row_ = row,
                    .col_ = col,
                });
            }
        }

        int current_row = q.top().row_;
        int current_col = q.top().col_;
        q.pop();
        while (!q.empty()) {
            auto diff_row = std::abs(q.top().row_ - current_row);
            switch (diff_row)
            {
            case 1: {
                if (std::abs(q.top().col_ - current_col) != 2) {
                    return false;
                }
                break;
            }
            case 2: {
                if (std::abs(q.top().col_ - current_col) != 1) {
                    return false;
                }
                break;
            }
            default:
                return false;
            }
            current_row = q.top().row_;
            current_col = q.top().col_;
            q.pop();
        }
        return true;
    }
};
// @lc code=end

