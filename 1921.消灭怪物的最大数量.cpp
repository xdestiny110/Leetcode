/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        std::vector<int> time(dist.size(), 0);
        for (size_t i = 0; i < dist.size(); ++i) {
            time[i] = dist[i] / speed[i] + (dist[i] % speed[i] == 0 ? 0 : 1);
        }

        std::sort(time.begin(), time.end());
        size_t t = 0;
        while (t < time.size()) {
            if (t >= time[t]) {
                break;
            }
            t++;
        }
        return t;
    }
};
// @lc code=end

