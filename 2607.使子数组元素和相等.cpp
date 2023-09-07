/*
 * @lc app=leetcode.cn id=2607 lang=cpp
 *
 * [2607] 使子数组元素和相等
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    long long makeSubKSumEqual(std::vector<int> &arr, int k)
    {
        long long result = 0;
        std::unordered_set<int> equal_pos;
        for (int pos = 0; pos < arr.size(); ++pos)
        {
            if (equal_pos.contains(pos)) continue;
            auto p = pos;
            std::vector<int> nums;
            do
            {
                equal_pos.insert(p);
                nums.push_back(arr[p]);
                p += k;
                p %= arr.size();
            } while (!equal_pos.contains(p));
            std::sort(nums.begin(), nums.end());
            auto mid_num = (nums.size() % 2 == 0) ? (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2 : nums[nums.size() / 2];
            for (auto num : nums) {
                result += std::abs(num - mid_num);
            }
        }
        return result;
    }
};
// @lc code=end
