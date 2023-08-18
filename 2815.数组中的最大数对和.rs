/*
 * @lc app=leetcode.cn id=2815 lang=rust
 *
 * [2815] 数组中的最大数对和
 */

// @lc code=start
use std::{collections::HashMap};

impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut max_digits = HashMap::<i32, [i32;2]>::new();
        for num in nums {
            let mut current_num = num.clone();
            let mut max_digit = 0;
            while current_num > 0 {
                if current_num % 10 > max_digit {
                    max_digit = current_num % 10;
                }
                current_num /= 10;
            }
            
            if max_digits.contains_key(&max_digit) {
                let v = max_digits.get_mut(&max_digit).unwrap();
                if num > v[1] {
                    v[1] = num;
                }
                if v[1] > v[0] {
                    v.swap(0, 1);
                }
            } else {
                max_digits.insert(max_digit, [num, 0]);
            }
        }

        let mut max_result = -1;
        for (_, nums) in &max_digits {
            if nums[1] == 0 {
                continue;
            }
            let result = nums[0] + nums[1];
            if result > max_result {
                max_result = result;
            }
        }

        return max_result;
    }
}
// @lc code=end

