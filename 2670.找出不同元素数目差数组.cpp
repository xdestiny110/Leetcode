/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 *
 * [2670] 找出不同元素数目差数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> distinctDifferenceArray(std::vector<int>& nums) {
        std::unordered_map<int, int> prefix;
        std::unordered_map<int, int> suffix;
        for (auto num : nums) {
            suffix[num]++;
        }
        std::vector<int> result(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix[nums[i]]++;
            if (suffix[nums[i]] == 1) {
                suffix.erase(nums[i]);
            } else {
                suffix[nums[i]]--;
            }
            result[i] = prefix.size() - suffix.size();
        }
        return result;
    }
};
// @lc code=end

