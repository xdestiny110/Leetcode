/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include <vector>
#include <unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        
        std::unordered_set<int> row, col;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    row.emplace(r);
                    col.emplace(c);
                }
            }
        }

        for(const auto& it : row){
            for(int c = 0; c < matrix[0].size(); c++){
                matrix[it][c] = 0;
            }
        }
        for(const auto& it : col){
            for(int r = 0; r < matrix.size(); r++){
                matrix[r][it] = 0;
            }
        }   
    }
};

