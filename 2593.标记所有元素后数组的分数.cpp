/*
 * @lc app=leetcode.cn id=2593 lang=cpp
 *
 * [2593] 标记所有元素后数组的分数
 */

// @lc code=start

#include <set>

class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto key_cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
            return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
        };
        std::set<std::pair<int, int>, decltype(key_cmp)> s(key_cmp);

        for (int i = 0; i < nums.size(); ++i) {
            s.insert({nums[i], i});
        }

        long long result = 0;
        while (!s.empty()) {
            result += s.begin()->first;
            auto t = *s.begin();
            s.erase(t);
            if (t.second - 1 >= 0) {
                s.erase({nums[t.second - 1], t.second - 1});
            }
            if (t.second + 1 < nums.size()) {
                s.erase({nums[t.second + 1], t.second + 1});
            }
        }
        return result;
    }
};
// @lc code=end

