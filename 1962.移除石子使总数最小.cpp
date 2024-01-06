/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start

#include <queue>
#include <vector>

class Solution {
public:
    int minStoneSum(const std::vector<int>& piles, int k) {
        std::priority_queue<int> q;
        for (auto pile : piles) {
            q.push(pile);
        }

        for (int i = 0; i < k; ++i) {
            auto pile = q.top();
            q.pop();
            q.push(pile - pile / 2);
        }

        int result = 0;
        while (!q.empty()) {
            result += q.top();
            q.pop();
        }
        return result;
    }
};
// @lc code=end

