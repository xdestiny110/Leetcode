/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        std::vector<int> result;
        size_t row = 0, col = 0;
        bool dir = true;
        while (true) {
            result.push_back(mat[row][col]);
            if (row == mat.size() - 1 && col == mat[0].size() - 1) {
                break;
            }
            if (dir) {
                if (row == 0 && col != mat[0].size() - 1) {
                    col++;
                    dir = false;
                } else if (col == mat[0].size() - 1) {
                    row++;
                    dir = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (col == 0 && row != mat.size() - 1) {
                    row++;
                    dir = true;
                } else if (row == mat.size() - 1) {
                    col++;
                    dir = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

