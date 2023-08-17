/*
 * @lc app=leetcode.cn id=598 lang=rust
 *
 * [598] 范围求和 II
 */

// @lc code=start
impl Solution {
    pub fn max_count(m: i32, n: i32, ops: Vec<Vec<i32>>) -> i32 {
        if ops.len() == 0 {
            return m * n;
        }
        let mut x_min = i32::MAX;
        let mut y_min = i32::MAX;
        for op in ops {
            x_min = if op[0] < x_min {op[0]} else {x_min};
            y_min = if op[1] < y_min {op[1]} else {y_min};
        }
        return x_min * y_min;
    }
}
// @lc code=end

