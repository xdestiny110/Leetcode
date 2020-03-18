/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        std::vector<int> area(matrix[0].begin(), matrix[0].end());
        int maxArea = *std::max_element(area.begin(), area.end());
        for(int i = 1; i < matrix.size(); ++i){
            std::vector<int> currentArea(matrix[i].size());
            currentArea[0] = matrix[i][0];
            maxArea = std::max(maxArea, currentArea[0]);
            for(int j = 1; j < matrix[i].size(); ++j){
                if(matrix[i][j] > '0'){
                    auto minArea = std::min(std::min(area[j], area[j-1]), currentArea[j-1]);
                    currentArea[j] = minArea + 1;
                    maxArea = std::max(maxArea, currentArea[j]);
                }
                else{
                    currentArea[j] = '0';
                }
            }
            area = std::move(currentArea);
        }

        maxArea -= '0';
        return maxArea * maxArea;
    }

};
// @lc code=end

