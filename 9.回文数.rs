/*
 * @lc app=leetcode.cn id=9 lang=rust
 *
 * [9] 回文数
 */

// @lc code=start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let x_str = x.to_string();
        let x_str_bytes = x_str.as_bytes();
        let mut head = 0;
        let mut tail = x_str.len() - 1;
        while head < tail {
            if x_str_bytes[head] != x_str_bytes[tail] {
                return false;
            }
            head += 1;
            tail -= 1;
        }
        return true;
    }
}
// @lc code=end

