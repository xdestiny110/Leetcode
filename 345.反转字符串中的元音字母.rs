/*
 * @lc app=leetcode.cn id=345 lang=rust
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
pub fn is_aeiou(c: char) -> bool {
    return c.to_lowercase().any(|ch| {
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
    });
}

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut chs : Vec<_> = s.chars().collect();
        let mut left = 0;
        let mut right = chs.len() - 1;
        while left < right {
            while left < right && !is_aeiou(chs[left]) {
                left+=1;
            }
            while left < right && !is_aeiou(chs[right]) {
                right-=1;
            }
            if left < right {
                chs.swap(left, right);
                left += 1;
                right -= 1;
            }
        }
        let result : String = chs.iter().collect();
        return result;
    }
}
// @lc code=end

