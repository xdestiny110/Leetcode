/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto l_it = std::lower_bound(nums.begin(), nums.end(), target);
        auto r_it = std::upper_bound(nums.begin(), nums.end(), target);
        std::vector<int> result(2, -1);
        if (l_it != nums.end() && *l_it == target) {
            result[0] = std::distance(nums.begin(), l_it);
            std::advance(r_it, -1);
            result[1] = std::distance(nums.begin(), r_it);
        }
        return result;
    }
};

