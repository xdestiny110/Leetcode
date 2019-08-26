/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        unsigned char dir = 0;
        int r = 0, c = 0;
        int tMax = 0, bMax = n-1, lMax = 0, rMax = n-1;
        std::vector<std::vector<int>> result;
        for(int i = 0; i < n; i++)
            result.emplace_back(n);
        for(int i = 1; i <= n*n; i++){
            result[r][c] = i;
            switch(dir){
                case 0:
                    if(c == rMax){
                        tMax++;
                        dir++;
                        r++;
                    }
                    else
                        c++;
                break;
                case 1:
                    if(r == bMax){
                        rMax--;
                        dir++;
                        c--;
                    }
                    else
                        r++;
                break;
                case 2:
                    if(c == lMax){
                        bMax--;
                        dir++;
                        r--;
                    }
                    else
                        c--;
                break;
                default:
                    if(r == tMax){
                        lMax++;
                        dir = 0;
                        c++;
                    }
                    else
                        r--;
                break;
            }
        }
        return result;
    }
};

