/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        std::vector<std::vector<int>> result;
        result.reserve(intervals.size());
        for(const auto& it : intervals){
            if(result.empty())
                result.emplace_back(it);
            else{
                if(result.back()[1] < it[0])
                    result.emplace_back(it);
                else
                    result.back()[1] = std::max(it[1], result.back()[1]);
            }
        }
        return result;
    }
};

