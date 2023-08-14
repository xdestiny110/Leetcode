/*
 * @lc app=leetcode.cn id=350 lang=rust
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1_map = HashMap::new();
        for n in nums1 {
            let count = nums1_map.entry(n).or_insert(0);
            *count += 1;
        }
        
        let mut result : Vec<i32> = Vec::new();
        for n in nums2 {
            if let Some(cnt) = nums1_map.get_mut(&n) {
                if *cnt > 0 {
                    result.push(n);
                    *cnt -= 1;
                }
            }
        }
        return result;
    }
}
// @lc code=end

