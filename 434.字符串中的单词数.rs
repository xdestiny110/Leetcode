/*
 * @lc app=leetcode.cn id=434 lang=rust
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
impl Solution {
    pub fn count_segments(s: String) -> i32 {
        let mut result = 0;
        let mut is_space = true;
        for c in s.chars() {
            if c == ' ' {
                is_space = true;
            } else {
                if is_space {
                    result += 1;
                }
                is_space = false;
            }
        }
        return result;
    }
}
// @lc code=end

