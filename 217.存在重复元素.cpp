/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;
        for(const auto& it : nums){
            if(s.find(it) != s.end()) return true;
            s.insert(it);
        }
        return false;
    }
};
// @lc code=end

