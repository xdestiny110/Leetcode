/*
 * @lc app=leetcode.cn id=56 lang=rust
 *
 * [56] 合并区间
 */

// @lc code=start
impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort_unstable_by(|a, b| {
            return a[0].partial_cmp(&b[0]).unwrap();
        });
    
        let mut results = Vec::new();
        for s_e in intervals {
            if results.is_empty() {
                results.push(s_e);
            } else {
                let result = results.last_mut().unwrap();
                if result[1] >= s_e[0] {
                    result[1] = result[1].max(s_e[1]);
                } else {
                    results.push(s_e);
                }
            }
        }
    
        return results;
    }
}
// @lc code=end

