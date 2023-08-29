/*
 * @lc app=leetcode.cn id=33 lang=rust
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if nums.len() == 1 {
            return if nums[0] == target { 0 } else { -1 };
        }
        let mut head = 0;
        let mut tail = nums.len() - 1;
        if nums[head] == target {
            return head as i32;
        }
        if nums[tail] == target {
            return tail as i32;
        }

        while head < tail - 1 {
            let mid = (head + tail) / 2;
            if nums[mid] == target {
                return mid as i32;
            }
            if nums[head] > target && nums[mid] > target {
                if nums[mid] > nums[head] {
                    head = mid;
                } else {
                    tail = mid;
                }
            } else if nums[head] > target && nums[mid] < target {
                head = mid;
            } else if nums[head] < target && nums[mid] < target {
                if nums[mid] > nums[head] {
                    head = mid;
                } else {
                    tail = mid;
                }
            } else {
                tail = mid;
            }
        }
        if nums[head] == target {
            return head as i32;
        }
        if nums[tail] == target {
            return tail as i32;
        }

        return -1;
    }
}
// @lc code=end

