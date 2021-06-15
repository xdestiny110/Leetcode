/*
 * @lc app=leetcode.cn id=326 lang=rust
 *
 * [326] 3的幂
 */

// @lc code=start

use std::num;

impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        let p = (n as f64).log(3.0);
        return ((p - ((p + 1e-12) as i32) as f64).abs() < 2e-12);
    }
}
// @lc code=end

