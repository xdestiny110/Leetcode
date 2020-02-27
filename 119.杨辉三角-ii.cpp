/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ret(rowIndex + 1);
        std::vector<int> t(rowIndex + 1);
        for(int i = 0; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    t[j] = 1;
                }
                else{
                    t[j] = ret[j-1] + ret[j];
                }
            }
            std::swap(ret, t);
        }
        return ret;
    }
};
// @lc code=end

