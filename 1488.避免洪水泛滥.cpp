/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
#include <vector>
#include <set>
#include <unordered_map>

class Solution {
public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
        std::vector<int> result(rains.size(), 1);
        std::set<int> sunny_day;
        std::unordered_map<int, int> lake_idx_day_rain;
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] > 0) {
                if (lake_idx_day_rain.contains(rains[i])) {
                    // 注意：对于无法随机访问的有序容器需要使用自带的二分函数
                    // std::lower_bound对于无法随机访问的容器复杂度为o(n)
                    auto it = sunny_day.lower_bound(lake_idx_day_rain[rains[i]]);
                    if (it == sunny_day.end()) {
                        return {};
                    }
                    result[*it] = rains[i];
                    sunny_day.erase(it);
                }
                result[i] = -1;
                lake_idx_day_rain[rains[i]] = i;
            } else {
                sunny_day.insert(i);
            }
        }
        return result;
    }
};
// @lc code=end

