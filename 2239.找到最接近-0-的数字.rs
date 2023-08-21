/*
 * @lc app=leetcode.cn id=2239 lang=rust
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
impl Solution {
    pub fn find_closest_number(nums: Vec<i32>) -> i32 {
        let mut result: i32 = 1000000;
        for num in nums {
            if num.abs() < result.abs() {
                result = num;
            } else if num.abs() == result.abs() {
                result = result.max(num);
            }
        }
        return result;
    }
}
// @lc code=end

