/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // 从右上角出发
        // 大于target则往左
        // 否则往下
        // 有序可以考虑二分
        if(matrix.empty() || matrix[0].empty()) return false;

        int r = 0, c = matrix[0].size()-1;
        while(r >= 0 && r < matrix.size() && c >=0 && c < matrix[0].size()){
            if(matrix[r][c] > target){
                auto it = std::upper_bound(matrix[r].begin(), matrix[r].begin() + c + 1, target);
                c = std::distance(matrix[r].begin(), it) - 1;
            }
            else if(matrix[r][c] < target){
                int cnt = matrix.size() - r;
                while(cnt > 0){
                    int step = cnt / 2;
                    if(matrix[r + step][c] < target){
                        cnt -= step+1;
                        r += step+1;
                    }
                    else{
                        cnt = step;
                    }
                }
            }
            else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

