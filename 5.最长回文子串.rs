/*
 * @lc app=leetcode.cn id=5 lang=rust
 *
 * [5] 最长回文子串
 */

// @lc code=start
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s.is_empty() {
            return "".to_string();
        }
        let mut f = [[0;1001];1001];
    
        let bytes = s.as_bytes();
        let mut result = String::new();
        for l in 0..s.len() {
            for start in 0..s.len() {
                if l == 0 {
                    f[start][start + l] = 1;
                    if f[start][start + l] > result.len() {
                        result = s[start..start + l + 1].to_string();
                    }
                } else if start + l < bytes.len() && bytes[start] == bytes[start + l] {
                    if start + 1 <= start + l - 1 && f[start + 1][start + l - 1] > 0 {
                        f[start][start + l] = f[start + 1][start + l - 1] + 2;
                        if f[start][start + l] > result.len() {
                            result = s[start..start + l + 1].to_string();
                        }
                    } else if start + 1 > start + l - 1 {
                        f[start][start + l] = 2;
                        if f[start][start + l] > result.len() {
                            result = s[start..start + l + 1].to_string();
                        }
                    }
                }
            }
        }
    
        return result;
    }
}
// @lc code=end

