/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include <vector>
#include <array>
#include <map>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if(n == 0){
            return tasks.size();
        }
        std::array<size_t, 26> task_counts;
        std::fill(task_counts.begin(), task_counts.end(), 0);
        for(auto task : tasks){
            task_counts[task - 'A'] += 1;
        }
        std::sort(task_counts.begin(), task_counts.end(), std::greater<>{});
        int total = (n + 1) * (task_counts[0] - 1) + 1;
        for (int i = 1; i < task_counts.size(); ++i) {
            if(task_counts[i] == task_counts[0]){
                total++;
            }
        }
        return total > tasks.size() ? total : tasks.size();
    }
};
// @lc code=end

