/*
 * @lc app=leetcode.cn id=342 lang=rust
 *
 * [342] 4的幂
 */

// @lc code=start
use std;
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if (n == 0){
            return false;
        } 
        let p = (n as f64).log(4.0);
        return p - (((p + 1e-12) as i32) as f64) < 2e-12;
    }
}
// @lc code=end

