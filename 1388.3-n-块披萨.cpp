/*
 * @lc app=leetcode.cn id=1388 lang=cpp
 *
 * [1388] 3n 块披萨
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int m = n / 3;
        vector<int> slices1(slices.begin(), slices.end() - 1);
        vector<int> slices2(slices.begin() + 1, slices.end());
        return max(maxSize(slices1, m), maxSize(slices2, m));
    }

private:
    int maxSize(vector<int>& slices, int m) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(m, i); ++j) {
                if (i == 1) {
                    dp[i][j] = slices[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

