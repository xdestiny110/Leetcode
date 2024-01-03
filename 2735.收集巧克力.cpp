/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 *
 * [2735] 收集巧克力
 */

// @lc code=start

#include <list>
#include <vector>
#include <numeric>

class Solution {
public:
    long long minCost(std::vector<int>& nums, int x) {
        std::list<int> nums_list(nums.begin(), nums.end());
        std::vector<int> nums_min(nums.begin(), nums.end());
        auto result = std::accumulate(nums_min.begin(), nums_min.end(), 0LL);
        for (int i = 1; i < nums.size(); ++i) {
            auto front = nums_list.front();
            nums_list.pop_front();
            nums_list.push_back(front);
            auto it = nums_list.begin();
            auto j = 0;
            for (;it != nums_list.end(); ++it, ++j) {
                nums_min[j] = std::min(nums_min[j], *it);
            }
            result = std::min(result, std::accumulate(nums_min.begin(), nums_min.end(), 0LL) + 1LL * x * i);
        }
        return result;
    }
};
// @lc code=end

