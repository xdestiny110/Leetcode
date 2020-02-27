/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret(numRows);
        for(int i = 0; i < numRows; i++){
            ret[i].resize(i + 1);
            for(int j = 0; j <= i; j++){
                if((j == 0) || (j == i)){
                    ret[i][j] = 1;
                }
                else{
                    ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
                }
            }
        }

        return ret;
    }
};
// @lc code=end

