/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 *
 * [2105] 给植物浇水 II
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB) {
        int waterA = capacityA;
        int waterB = capacityB;
        int resultCnt = 0;

        auto func = [](int& water, int plant, int capcity) -> int {
            int result = 0;
            if (water < plant) {
                result++;
                water = capcity;
            }
            water -= plant;
            return result;
        };

        int i = 0, j = plants.size() - 1;
        for (; i < j; ++i, --j) {
            resultCnt += func(waterA, plants[i], capacityA) + func(waterB, plants[j], capacityB);
        }
        if (i == j) {
            if (std::max(waterA, waterB) < plants[i]) {
                resultCnt++;
            }
        }
        return resultCnt;
    }
};
// @lc code=end

