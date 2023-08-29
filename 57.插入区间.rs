/*
 * @lc app=leetcode.cn id=57 lang=rust
 *
 * [57] 插入区间
 */

// @lc code=start
impl Solution {
    pub fn insert(mut intervals: Vec<Vec<i32>>, mut new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut start_idx = None;
        let mut end_idx = None;
        for idx in 0..intervals.len() {
            if intervals[idx][1] >= new_interval[0] {
                start_idx = Some(idx);
                break;
            }
        }
        if start_idx.is_none() {
            intervals.push(new_interval);
            return intervals;
        }

        for idx in (0..intervals.len()).rev() {
            if intervals[idx][0] <= new_interval[1] {
                end_idx = Some(idx);
                break;
            }
        }
        if end_idx.is_none() {
            intervals.insert(0, new_interval);
            return intervals;
        }

        new_interval[0] = new_interval[0].min(intervals[start_idx.unwrap()][0]);
        new_interval[1] = new_interval[1].max(intervals[end_idx.unwrap()][1]);
        let mut result = Vec::new();
        for idx in 0..start_idx.unwrap() {
            result.push(intervals[idx].clone());
        }
        result.push(new_interval);
        for idx in end_idx.unwrap() + 1..intervals.len() {
            result.push(intervals[idx].clone());
        }

        return result;
    }
}
// @lc code=end

