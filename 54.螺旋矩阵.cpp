/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        int r = 0, c = 0;
        int lBorder = 0, rBorder = matrix[0].size()-1,
            tBorder = 0, bBorder = matrix.size()-1;
        unsigned char flag = 0;
        std::vector<int> result(matrix.size() * matrix[0].size());
        for(int n = 0; n < result.size(); n++){
            result[n] = matrix[r][c];
            switch (flag)
            {
            case 0:
                if(c == rBorder){
                    flag++;
                    r++;
                    tBorder++;
                }
                else
                    c++;
                break;
            case 1:
                if(r == bBorder){
                    flag++;
                    c--;
                    rBorder--;
                }
                else
                    r++;
                break;
            case 2:
                if(c == lBorder){
                    flag++;
                    r--;
                    bBorder--;
                }
                else
                    c--;
                break;
            case 3:
                if(r == tBorder){
                    flag = 0;
                    c++;
                    lBorder++;
                }
                else
                    r--;
                break;
            default:
                break;
            }
        }
        return result;
    }
};

