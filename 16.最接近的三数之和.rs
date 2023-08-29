/*
 * @lc app=leetcode.cn id=16 lang=rust
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
// -5 -5 -4 0 0 3 3 4 5

impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort_unstable();
        let mut result: Option<i32> = None;
        for idx in 0..nums.len() {
            let mut head = idx + 1;
            let mut tail = nums.len() - 1;
            while head < tail {
                let t = nums[head] + nums[tail] + nums[idx];
                if let Some(result) = result.as_mut() {
                    if (target - t).abs() < (target - *result).abs() {
                        *result = t;
                    }
                } else {
                    result = Some(t);
                }
                if t > target {
                    tail -= 1;
                } else if t < target {
                    head += 1;
                } else {
                    return result.unwrap();
                }
            }
        }
        return result.unwrap();
    }
}
// @lc code=end

