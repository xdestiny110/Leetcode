/*
 * @lc app=leetcode.cn id=228 lang=rust
 *
 * [228] 汇总区间
 */

// @lc code=start

fn insert_result(result: &mut Vec<String>, start_num: i32, last_num: i32) {
    if start_num == last_num {
        result.push(start_num.to_string());
    } else {
        result.push(format!("{}->{}", start_num, last_num));
    }
}

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut result = Vec::<String>::new();
        if nums.len() == 0 {
            return result;
        }
        let mut last_num = nums[0];
        let mut start_num = nums[0];
        for idx in 1..nums.len() {
            if nums[idx] != last_num + 1 {
                insert_result(&mut result, start_num, last_num);
                start_num = nums[idx];
                last_num = nums[idx];
            } else {
                last_num += 1;
            }
        }

        insert_result(&mut result, start_num, last_num);
        return result;
    }
}
// @lc code=end

