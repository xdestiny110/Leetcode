/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start

#include <vector>
#include <cmath>
#include <numeric>

class Solution {
public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        long long head = 1, tail = std::numeric_limits<long long>::max();
        while (head < tail - 1) {
            auto mid = head + (tail - head) / 2;
            if (valid(ranks, cars, mid)) {
                tail = mid;
            } else {
                head = mid;
            }
        }
        return valid(ranks, cars, head) ? head : tail;
    }

private:
    bool valid(const std::vector<int>& ranks, int cars, long long time) const {
        for (auto r : ranks) {
            cars -= static_cast<long long>(std::sqrt(time / r));
            if (cars <= 0) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

