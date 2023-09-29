/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start

#include <vector>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int last_flower_idx = -1;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] > 0) {
                if (last_flower_idx > -1) {
                    count += (i - last_flower_idx - 2) / 2;
                } else {
                    count += i / 2;
                }
                last_flower_idx = i;
            }
        }
        if (last_flower_idx < 0) {
            count += (flowerbed.size() + 1) / 2;
        } else
            count += (flowerbed.size() - 1 - last_flower_idx) / 2;
        return count >= n;
    }
};
// @lc code=end

