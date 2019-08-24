/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        result.reserve(intervals.size()+1);
        unsigned char flag = 0;
        for(const auto& it : intervals){
            switch (flag)
            {
            case 0:
                if(isOverlap(it, newInterval)){
                    result.emplace_back(std::vector<int>{std::min(it[0], newInterval[0]), std::max(it[1], newInterval[1])});
                    flag++;
                }
                else{
                    if(newInterval[1] < it[0]){
                        result.emplace_back(newInterval);
                        flag++;
                    }
                    result.emplace_back(it);
                }
                break;
            case 1:
                if(isOverlap(it, result.back())){
                    result.back()[0] = std::min(it[0], result.back()[0]);
                    result.back()[1] = std::max(it[1], result.back()[1]);
                }
                else{
                    result.emplace_back(it);
                    flag++;
                }
                break;
            default:
                result.emplace_back(it);
                break;
            }
        }
        if(flag == 0)
            result.emplace_back(newInterval);
        return result;
    }

private:
    bool isOverlap(const std::vector<int>& a, const std::vector<int>& b) const {
        if(a[0] < b[0])
            return b[0] <= a[1];
        return a[0] <= b[1];
    }
};

