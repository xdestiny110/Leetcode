/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start

#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) {
        auto loc_hasher = [](const std::pair<int, int>& loc) {
            return std::hash<int>()(loc.first) ^ std::hash<int>()(loc.second);
        };
        std::unordered_set<std::pair<int, int>, decltype(loc_hasher)> queens_loc(10, loc_hasher);
        for (const auto& queen : queens) {
            queens_loc.insert({queen[0], queen[1]});
        }

        std::vector<std::vector<int>> result;
        // left-up
        int row_diff = -1;
        int col_diff = -1;
        std::pair<int, int> loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first >= 0 && loc_current.second >= 0) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // up
        row_diff = -1;
        col_diff = 0;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first >= 0) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // right-up
        row_diff = -1;
        col_diff = 1;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first >= 0 && loc_current.second < 8) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // right
        row_diff = 0;
        col_diff = 1;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.second < 8) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // right-down
        row_diff = 1;
        col_diff = 1;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first < 8 && loc_current.second < 8) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // down
        row_diff = 1;
        col_diff = 0;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first < 8) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // left-down
        row_diff = 1;
        col_diff = -1;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.first < 8 && loc_current.second >= 0) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        // left
        row_diff = 0;
        col_diff = -1;
        loc_current = {king[0] + row_diff, king[1] + col_diff};
        while (loc_current.second >= 0) {
            if (queens_loc.contains(loc_current)) {
                result.push_back({loc_current.first, loc_current.second});
                break;
            }
            loc_current.first += row_diff;
            loc_current.second += col_diff;
        }

        return result;
    }
};
// @lc code=end

