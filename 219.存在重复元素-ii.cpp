/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <cmath>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> m;
        m.reserve(nums.size());
        
        for(int i = 0; i < nums.size(); ++i){
            m[nums[i]].emplace_back(i);
            for(const auto& jt : m[nums[i]]){
                if(jt != i && std::abs(jt - i) <= k){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

