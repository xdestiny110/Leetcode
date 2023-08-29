/*
 * @lc app=leetcode.cn id=14 lang=rust
 *
 * [14] 最长公共前缀
 */

// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut min_len = strs[0].len();
        for s in strs.iter() {
            min_len = min_len.min(s.len());
        }

        let mut result = "".to_string();
        for idx in 0..min_len {
            let c = strs[0].chars().nth(idx).unwrap();
            let mut flag = true;
            for s in strs.iter() {
                if c != s.chars().nth(idx).unwrap() {
                    flag = false;
                    break;
                }
            }
            if !flag {
                break;
            }
            result.push(c);
        }
        return result;
    }
}
// @lc code=end

