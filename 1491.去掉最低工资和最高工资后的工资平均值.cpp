/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    double average(std::vector<int>& salary) {
        auto [max_it, min_it] = std::minmax_element(salary.begin(), salary.end());
        auto total_salary = std::accumulate(salary.begin(), salary.end(), 0) - *max_it - *min_it;
        return total_salary * 1.0 / (salary.size() - 2);
    }
};
// @lc code=end

