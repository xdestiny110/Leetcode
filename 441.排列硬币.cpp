/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
#include <numeric>

class Solution {
public:
    int arrangeCoins(int n) {
        uint32_t head = 1, tail = 65536;
        while (head < tail - 1) {
            auto mid = (head + tail) / 2;
            uint64_t sum = mid * (mid + 1) / 2;
            if (sum == n) {
                return mid;
            }
            if (sum > n) {
                tail = mid;
            } else {
                head = mid;
            }
        }
        return head;
    }
};
// @lc code=end

