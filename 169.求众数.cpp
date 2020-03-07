/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */

// @lc code=start

#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for(const auto& it : nums){
            auto t = m[it];
            m[it] = t + 1;
            if(t + 1 > nums.size() / 2){
                return it;
            }
        }
        return std::max_element(m.begin(), m.end(), [](const auto& it, const auto& jt){
            return it.second > jt.second;
        })->first;
    }
};
// @lc code=end

