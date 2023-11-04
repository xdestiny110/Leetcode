/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start

#include <queue>
#include <cmath>

class Solution {
public:
    long long pickGifts(const std::vector<int>& gifts, int k) const {
        uint64_t left_gifts = 0;
        std::priority_queue<int> gifts_queue;
        for (auto gift : gifts) {
            gifts_queue.push(gift);
            left_gifts += gift;
        }

        for (int i = 0; i < k; ++i) {
            auto gift = gifts_queue.top();
            auto left_gift = static_cast<int>(std::sqrt(gift));
            if (left_gift == gift) break;
            left_gifts -= (gift - left_gift);
            gifts_queue.pop();
            gifts_queue.push(left_gift);
        }
        return left_gifts;
    }
};
// @lc code=end

