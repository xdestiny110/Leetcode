/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] 切披萨的方案数
 */

#include <vector>
#include <string>

// @lc code=start
class Solution {
public:
    int ways(std::vector<std::string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        std::vector<std::vector<int>> pre(m + 1, std::vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; --j) {
                cnt += pizza[i][j] == 'A';
                pre[i][j] = pre[i + 1][j] + cnt;
            }
        }
        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n, std::vector<int>(k, -1)));
        return dfs(pre, dp, 0, 0, k - 1);
    }

    int dfs(std::vector<std::vector<int>>& pre, std::vector<std::vector<std::vector<int>>>& dp, int x, int y, int k) {
        if (pre[x][y] == 0) return 0;
        if (k == 0) return 1;
        if (dp[x][y][k] != -1) return dp[x][y][k];
        int res = 0;
        for (int i = x + 1; i < pre.size(); ++i) {
            if (pre[x][y] - pre[i][y] > 0) {
                res = (res + dfs(pre, dp, i, y, k - 1)) % 1000000007;
            }
        }
        for (int j = y + 1; j < pre[0].size(); ++j) {
            if (pre[x][y] - pre[x][j] > 0) {
                res = (res + dfs(pre, dp, x, j, k - 1)) % 1000000007;
            }
        }
        return dp[x][y][k] = res;
    }
};
// @lc code=end

