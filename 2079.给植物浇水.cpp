/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        int step = 1;
        int water = capacity;
        water -= plants[0];
        for (size_t idx = 1; idx < plants.size(); ++idx) {
            if (water < plants[idx]) {
                water = capacity;
                step += idx * 2;
            }
            step++;
            water -= plants[idx];
        }
        return step;
    }
};
// @lc code=end

