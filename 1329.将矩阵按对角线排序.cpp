/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {
        size_t rows = mat.size();
        size_t cols = mat[0].size();
        std::vector<int> v;
        
        for (int c_start = cols; c_start >= 0; --c_start) {
            v.clear();
            for (size_t c = c_start, r = 0; r < rows && c < cols; ++c, ++r) {
                v.push_back(mat[r][c]);
            }
            std::sort(v.begin(), v.end());
            for (size_t c = c_start, r = 0, v_idx = 0; r < rows && c < cols && v_idx < v.size(); ++c, ++r, ++v_idx) {
                mat[r][c] = v[v_idx];
            }
        }
        for (size_t r_start = 1; r_start < rows; ++r_start) {
            v.clear();
            for (size_t c = 0, r = r_start; r < rows && c < cols; ++c, ++r) {
                v.push_back(mat[r][c]);
            }
            std::sort(v.begin(), v.end());
            for (size_t c = 0, r = r_start, v_idx = 0; r < rows && c < cols && v_idx < v.size(); ++c, ++r, ++v_idx) {
                mat[r][c] = v[v_idx];
            }
        }
        return mat;
    }
};
// @lc code=end

