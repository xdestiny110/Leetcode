/*
 * @lc app=leetcode.cn id=70 lang=rust
 *
 * [70] 爬楼梯
 */

// @lc code=start
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if  n == 1 {
            return 1;
        }
        if n == 2 {
            return 2;
        }
        let mut dp = vec![0; n as usize];
        dp[0] = 1;
        dp[1] = 2;
        for i in 2..n {
            dp[i as usize] = dp[i as usize - 1] + dp[i as usize - 2];
        }
        dp[n as usize - 1]
    }
}
// @lc code=end

