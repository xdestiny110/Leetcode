/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start

#include <set>
#include <vector>
#include <cmath>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        std::set<long long> s;

        for(int i = 0; i < nums.size(); ++i){
            if(i > k){
                s.erase(nums[i-k-1]);
            }
            auto it = s.lower_bound(static_cast<long long>(nums[i]) - t);
            if(it != s.end() && std::abs(static_cast<long long>(nums[i]) - *it) <= t){
                return true;
            }
            s.emplace(nums[i]);
        }

        return false;
    }
};
// @lc code=end

