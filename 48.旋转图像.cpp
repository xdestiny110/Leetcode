/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r < n / 2; ++r){
            for(int c = r; c < n - 2 * r - 1 + r; ++c){
                std::swap(matrix[r][c], matrix[c][n - r - 1]);
                std::swap(matrix[r][c], matrix[n - r - 1][n - c - 1]);
                std::swap(matrix[r][c], matrix[n - c - 1][r]);
            }
        }
    }
};
// @lc code=end

