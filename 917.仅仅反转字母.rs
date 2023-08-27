/*
 * @lc app=leetcode.cn id=917 lang=rust
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
fn is_eng_char(c: char) -> bool {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

impl Solution {
    pub fn reverse_only_letters(mut s: String) -> String {
        let mut head : i32 = 0;
        let mut tail : i32 = (s.len() - 1) as i32;
        let bytes = unsafe { s.as_bytes_mut() };
        while head < tail {
            while head < bytes.len() as i32 && !is_eng_char(bytes[head as usize] as char) {
                head += 1;
            }
            if head >= bytes.len() as i32 {
                break;
            }
            while tail >= 0 && !is_eng_char(bytes[tail as usize] as char) {
                tail -= 1;
            }
            if tail < 0 {
                break;
            }
            if head >= tail {
                break;
            }
            bytes.swap(head as usize, tail as usize);
            head += 1;
            tail -= 1;
        }
        return s;
    }
}
// @lc code=end

