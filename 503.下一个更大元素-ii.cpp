/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start

#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        if (nums.size() == 1) return { -1 };
        std::stack<std::pair<int, size_t>> s;
        s.push({nums[0], 0});
        std::vector<int> result(nums.size(), -2);
        
        for (size_t idx = 1; !s.empty(); idx = (idx + 1) % nums.size()) {
            while (!s.empty() && (nums[idx] > s.top().first || idx == s.top().second)) {
                result[s.top().second] = idx == s.top().second ? -1 : nums[idx];
                s.pop();
            }
            if (result[idx] == -2) {
                s.push({nums[idx], idx});
                result[idx] = -1;
            }
        }

        return result;
    }
};
// @lc code=end

