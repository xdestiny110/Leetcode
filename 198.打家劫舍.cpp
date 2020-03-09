/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.empty()) return 0;
        std::pair<int, int> last = {0, nums[0]};

        for(int i = 1; i < nums.size(); ++i){
            last = {
                std::max(last.first, last.second),
                last.first + nums[i]
            };
        }

        return std::max(last.first, last.second);
    }
};
// @lc code=end

