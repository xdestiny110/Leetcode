/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        if(nums.empty()) return {};
        // 最多有两个
        // 因此记录两个摩尔投票结果
        std::pair<int, int> r0, r1;
        for(const auto& it : nums){
            if(it == r0.first){
                r0.second++;
            }
            else if(it == r1.first){
                r1.second++;
            }
            else if(r0.second == 0){
                r0.first = it;
                r0.second = 1;
            }
            else if(r1.second == 0){
                r1.first = it;
                r1.second = 1;
            }
            else{
                r0.second--;
                r1.second--;
            }
        }

        std::vector<int> r;
        // 有可能second大于0但不满足条件
        int cnt = 0;
        if(r0.second > 0){
            for(const auto& it : nums){
                if(it == r0.first) cnt++;
            }
        }
        if(cnt > nums.size() / 3) r.emplace_back(r0.first);

        cnt = 0;
        if(r1.second > 0){
            for(const auto& it : nums){
                if(it == r1.first) cnt++;
            }
        }
        if(cnt > nums.size() / 3) r.emplace_back(r1.first);
        return r;
    }
};
// @lc code=end

