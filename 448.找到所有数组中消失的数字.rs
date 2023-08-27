/*
 * @lc app=leetcode.cn id=448 lang=rust
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
impl Solution {
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        for idx in 0..nums.len() {
            let mut v = nums[idx] as usize;
            while v - 1 != idx && nums[v - 1] != v as i32 {
                nums.swap(idx, v - 1);
                v = nums[idx] as usize;
            }
        }
        
        let mut result = Vec::<i32>::new();
        for idx in 0..nums.len() {
            if nums[idx] -1 != idx as i32 {
                result.push((idx + 1) as i32);
            }
        }
        return result;
    }
}
// @lc code=end

