/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> f(n + 1, std::numeric_limits<int>::max());
        f[0] = 1; f[1] = 1;
        for(int i = 2; i <= n; ++i){
            int sq = sqrt(i);
            if(i - sq * sq == 0){
                f[i] = 1;
                continue;
            }
            for(int j = 1; j <= sqrt(i); ++j){
                f[i] = std::min(f[i- j*j], f[i]);
            }
            f[i]++;
        }
        return f.back();
    }
};
// @lc code=end

