/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        std::vector<int> result(code.size(), 0);
        if (k == 0) return result;
        int p = (k > 0) ? 1 : -1;
        for (int idx = 0; idx < code.size(); ++idx) {
            for (int offset = 1; offset <= std::abs(k); ++offset) {
                result[idx] += code[(idx + offset * p + code.size()) % code.size()];
            }
        }
        return result;
    }
};
// @lc code=end

