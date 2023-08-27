/*
 * @lc app=leetcode.cn id=849 lang=rust
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
impl Solution {
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        let mut max_val = 0;
        let mut last_idx: Option<usize> = None;
    
        for idx in 0..seats.len() {
            if seats[idx] == 1 {
                if let Some(last_idx) = last_idx {
                    max_val = max_val.max((idx - last_idx) / 2);
                } else if idx != 0 {
                    max_val = max_val.max(idx);
                }
                last_idx = Some(idx);
            }
        }

        if let Some(last_idx) = last_idx {
            max_val = max_val.max(seats.len() - last_idx - 1);
        }

        return max_val as i32;
    }
}
// @lc code=end

