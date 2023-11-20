/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start

#include <string>

class Solution {
public:
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (is_punishment(std::to_string(i * i), i))
                result += i * i;
        }
        return result;
    }

private:
    bool is_punishment(const std::string& s, int target) {
        for (int sep = 0; sep <= s.size() - 1; ++sep) {
            if (dfs(sep, 0, s, target)) {
                return true;
            }
        }
        return false;
    }

    bool dfs(int sep_cnt, int sum, const std::string& s, int target) {
        if (sep_cnt == 0) {
            sum += std::stoi(s);
            return sum == target;
        }
        for (int i = 1; i <= s.size() - sep_cnt; ++i) {
            if (dfs(sep_cnt - 1, sum + std::stoi(s.substr(0, i)), s.substr(i), target)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

