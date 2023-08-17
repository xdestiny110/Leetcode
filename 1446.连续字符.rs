/*
 * @lc app=leetcode.cn id=1446 lang=rust
 *
 * [1446] 连续字符
 */

// @lc code=start
impl Solution {
    pub fn max_power(s: String) -> i32 {
        let mut max_count = 1;
        let mut current_char = &s[0..1];
        let mut current_count = 1;
        for idx in 1..s.len() {
            if &s[idx..idx + 1] == current_char {
                current_count += 1;
            } else {
                if current_count > max_count { 
                    max_count = current_count;
                }
                current_count = 1;
                current_char = &s[idx..idx + 1];
            }
        }
        if current_count > max_count { 
            max_count = current_count;
        }
        return max_count;
    }
}
// @lc code=end

