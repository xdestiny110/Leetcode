/*
 * @lc app=leetcode.cn id=2678 lang=rust
 *
 * [2678] 老人的数目
 */

// @lc code=start
impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut older_cnt = 0;
        for detail in details {
            if detail[11..13].parse::<u32>().unwrap() > 60 {
                older_cnt += 1;
            }
        }
        return older_cnt;
    }
}
// @lc code=end

