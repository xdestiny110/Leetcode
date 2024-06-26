/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 *
 * [2748] 美丽下标对的数目
 */

// @lc code=start

#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    int countBeautifulPairs(std::vector<int>& nums) {
        std::vector<int> nums_i, nums_j;
        nums_i.reserve(nums.size());
        nums_j.reserve(nums.size());
        for (auto num : nums) {
            nums_i.push_back(std::to_string(num).front() - '0');
            nums_j.push_back(std::to_string(num).back() - '0');
        }

        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (std::gcd(nums_i[i], nums_j[j]) == 1) {
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

