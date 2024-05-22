/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::array<int, 100000 + 1> lose_cnt;
        std::fill(lose_cnt.begin(), lose_cnt.end(), -1);
        int max_idx = 0;
        for (const auto& m : matches) {
            max_idx = std::max(max_idx, std::max(m[0], m[1]));
            lose_cnt[m[0]] = lose_cnt[m[0]] < 0 ? 0 : lose_cnt[m[0]];
            lose_cnt[m[1]] = lose_cnt[m[1]] < 0 ? 1 : lose_cnt[m[1]] + 1;
        }

        std::vector<std::vector<int>> result(2);
        for (int i = 1; i <= max_idx; ++i) {
            switch (lose_cnt[i])
            {
            case 0:
                result[0].push_back(i);
                break;
            case 1:
                result[1].push_back(i);
                break;
            default:
                break;
            }
        }

        return result;
    }
};
// @lc code=end

