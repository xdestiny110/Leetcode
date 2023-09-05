/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

// @lc code=start

#include <vector>
#include <set>

class Solution
{
public:
    int minNumber(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::set<int> nums1_set, nums2_set;
        for (auto num : nums1)
        {
            nums1_set.insert(num);
        }

        int result = 100;
        for (auto num : nums2)
        {
            if (nums1_set.find(num) != nums1_set.end())
            {
                result = std::min(result, num);
            }
            nums2_set.insert(num);
        }

        if (result < 100)
        {
            return result;
        }

        return *nums1_set.begin() > *nums2_set.begin() ? *nums2_set.begin() * 10 + *nums1_set.begin() : *nums1_set.begin() * 10 + *nums2_set.begin();
    }
};
// @lc code=end
