/*
 * @lc app=leetcode.cn id=6 lang=rust
 *
 * [6] N 字形变换
 */

// @lc code=start

// 2->1
// 3->3
// 4->5

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 || s.len() <= 1 {
            return s;
        }
        let mut strs = vec!["".to_string(); num_rows as usize];
        let mut current_rows = 0;
        let mut is_inc = true;
        for c in s.chars() {
            strs[current_rows].push(c);
            if current_rows == 0 {
                current_rows = 1;
                is_inc = true;
            } else if current_rows == num_rows as usize - 1 {
                current_rows = current_rows - 1;
                is_inc = false;
            } else {
                current_rows = if is_inc { current_rows + 1 } else { current_rows - 1 };
            }
        }
    
        let mut result = "".to_string();
        for st in strs {
            result += &st;
        }
        return result;
    }
}
// @lc code=end

