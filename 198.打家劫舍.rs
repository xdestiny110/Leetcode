/*
 * @lc app=leetcode.cn id=198 lang=rust
 *
 * [198] 打家劫舍
 */

// @lc code=start
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let mut dp = vec![[0;2];nums.len()];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for idx in 1..nums.len() {
            dp[idx][0] = dp[idx - 1][0].max(dp[idx - 1][1]);
            dp[idx][1] = dp[idx - 1][0] + nums[idx];
        }
        return dp[dp.len() - 1][0].max(dp[dp.len() - 1][1]);
    }
}
// @lc code=end

