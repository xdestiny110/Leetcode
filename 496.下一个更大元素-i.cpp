/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> record;
        std::stack<int> s;
        for (auto it = nums2.rbegin(); it != nums2.rend(); ++it) {
            while (!s.empty() && s.top() < *it) {
                s.pop();
            }
            record[*it] = s.empty() ? -1 : s.top();
            s.push(*it);
        }

        std::vector<int> result;
        for (auto num1 : nums1) {
            result.push_back(record[num1]);
        }
        return result;
    }
};
// @lc code=end

