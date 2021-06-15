/*
 * @lc app=leetcode.cn id=344 lang=rust
 *
 * [344] 反转字符串
 */

// @lc code=start
impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        for idx in 0..s.len() / 2 {
            let right = s.len() - idx - 1;
            s.swap(idx,right)
        }
    }
}
// @lc code=end

