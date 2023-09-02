/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
#include <vector>
#include <numeric>

class Solution
{
public:
    int nthSuperUglyNumber(int n, std::vector<int> &primes)
    {
        int k = primes.size();
        std::vector<uint64_t> dp(1, 1);
        std::vector<uint64_t> index(k, 0);
        int x = n;
        while (--x)
        {
            uint64_t ans = std::numeric_limits<uint64_t>::max();
            for (int i = 0; i < k; i++)
            {
                ans = std::min<uint64_t>(ans, dp[index[i]] * primes[i]);
            }
            dp.push_back(ans);
            for (int i = 0; i < k; i++)
            {
                if (ans >= dp[index[i]] * primes[i])
                    index[i]++;
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
