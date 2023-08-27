/*
 * @lc app=leetcode.cn id=3 lang=rust
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
use std::collections::HashSet;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        if s.len() <= 1 {
            return s.len() as i32;
        }
    
        let mut head = 0;
        let mut tail = 1;
        let bytes = s.as_bytes();
        let mut chars_collection = HashSet::new();
        chars_collection.insert(bytes[0]);
        let mut result = 1;
        while tail < bytes.len() {
            if !chars_collection.contains(&bytes[tail]) {
                chars_collection.insert(bytes[tail]);
                result = result.max(chars_collection.len());
                tail += 1;
            } else {
                chars_collection.remove(&bytes[head]);
                head += 1;
            }
        }
        return result as i32;
    }
}
// @lc code=end

