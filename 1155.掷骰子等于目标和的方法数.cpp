/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        constexpr int mod = 1e9 + 7;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
        dp[0][0] = 1;
        //骰子可以选的次数
        for (int i = 1; i <= n;i++){
            //需要凑够的点数大小
            for (int j = 0; j <= target; j++){
                //枚举所有的点数.
                for (int jj = 1; jj <= k; jj++){
                    if (j >= jj){
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - jj]) % mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

