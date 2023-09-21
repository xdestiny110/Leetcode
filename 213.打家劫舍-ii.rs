/*
 * @lc app=leetcode.cn id=213 lang=rust
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return nums[0].max(0);
        }
        // 不偷第一间
        let mut f = vec![[0;2];nums.len()];
        // 不偷最后一间
        let mut g = vec![[0;2];nums.len()];
        g[0][1] = nums[0];
    
        for idx in 1..nums.len() {
            f[idx][0] = f[idx - 1][1].max(f[idx - 1][0]);
            f[idx][1] = f[idx - 1][0] + nums[idx];
        }
        for idx in 1..nums.len() - 1 {
            g[idx][0] = g[idx - 1][1].max(g[idx - 1][0]);
            g[idx][1] = g[idx - 1][0] + nums[idx];
        }
    
        f[nums.len() - 1][0].max(f[nums.len() - 1][1]).max(g[nums.len() - 2][0]).max(g[nums.len() - 2][1])
    }
}
// @lc code=end

