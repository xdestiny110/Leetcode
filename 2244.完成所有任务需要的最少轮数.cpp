/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start

#include <vector>
#include <unordered_map>

class Solution {
public:
    int minimumRounds(std::vector<int>& tasks) {
        std::unordered_map<int, size_t> lv_cnt;
        for (auto task : tasks) {
            lv_cnt[task]++;
        }

        int cost_times = 0;
        for (auto [_, cnt] : lv_cnt) {
            if (cnt <= 1) {
                return -1;
            }
            switch (cnt % 3)
            {
            case 0:
                cost_times += cnt / 3;
                break;
            case 1:
            case 2:
                cost_times += cnt / 3 + 1;
                break;
            default:
                return -1;
            }
        }
        return cost_times;
    }
};
// @lc code=end

