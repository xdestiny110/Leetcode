/*
 * @lc app=leetcode.cn id=53 lang=rust
 *
 * [53] 最大子数组和
 */

// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut dp = vec![0; nums.len()];
        dp[0] = nums[0];
        let mut max_sum = dp[0];
        for i in 1..nums.len() {
            dp[i] = (nums[i] + dp[i - 1]).max(nums[i]);
            max_sum = max_sum.max(dp[i]);
        }
        max_sum
    }
}
// @lc code=end

