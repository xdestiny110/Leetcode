/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> d1, d2;
        for(const auto& it : nums1){
            d1.emplace(it);
        }
        for(const auto& it : nums2){
            d2.emplace(it);
        }

        std::vector<int> result;
        for(const auto& it : d1){
            if(d2.find(it) != d2.end())
                result.emplace_back(it);
        }
        return result;
    }
};
// @lc code=end

