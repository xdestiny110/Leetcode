/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start

#include <vector>
#include <queue>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> q;
        for (auto num : nums) {
            q.push(num);
        }

        uint64_t result = 0;
        for (int i = 0; i < k; ++i) {
            auto num = q.top();
            q.pop();
            result += num;
            q.push(num / 3 + ((num % 3 > 0) ? 1 : 0));
        }
        return result;
    }
};
// @lc code=end

