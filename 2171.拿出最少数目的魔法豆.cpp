/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start

#include <vector>
#include <map>

class Solution {
public:
    long long minimumRemoval(std::vector<int>& beans) {
        std::map<int, long long, std::greater<>> bean_cnt; // bean个豆子的袋子有cnt个
        long long total_cnt = 0; // 豆子的总数
        for (auto bean : beans) {
            bean_cnt[bean]++;
            total_cnt += bean;
        }

        long long bean_presum = 0; // 已经统计了多少豆子
        long long bean_pre_cnt = 0; // 已经统计了多少袋子
        long long min_result = std::numeric_limits<long long>::max();
        for (const auto& [bean, cnt] : bean_cnt) {
            // 以当前数作为基准，后面的拿光，前面的改成相同
            auto result = bean_presum - bean_pre_cnt * bean;
            result += total_cnt - bean_presum - bean * cnt;
            min_result = std::min(result, min_result);
            bean_presum += bean * cnt;
            bean_pre_cnt += cnt;
        }
        return min_result;        
    }
};
// @lc code=end

