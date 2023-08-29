/*
 * @lc app=leetcode.cn id=15 lang=rust
 *
 * [15] 三数之和
 */

// -2 -1 0 1 2 3
 
// @lc code=start
impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        if nums.len() < 3 {
            return result;
        }
        nums.sort();

        for idx in 0..(nums.len() - 2) {
            if idx > 0 && nums[idx] == nums[idx - 1] {
                continue;
            }
            let mut head = idx + 1;
            let mut tail = nums.len() - 1;
            while head < tail {
                let sum = nums[idx] + nums[head] + nums[tail];
                if sum == 0 {
                    result.push(vec![nums[idx], nums[head], nums[tail]]);
                    head += 1;
                    while head < nums.len() && nums[head] == nums[head - 1] {
                        head += 1;
                    }
                    if head >= nums.len() {
                        break;
                    }
                    tail -= 1;
                    while tail > idx && nums[tail] == nums[tail + 1] {
                        tail -= 1;
                    }
                    if tail <= idx {
                        break;
                    }
                } else if sum < 0 {
                    head += 1;
                    while head < nums.len() && nums[head] == nums[head - 1] {
                        head += 1;
                    }
                    if head >= nums.len() {
                        break;
                    }
                } else {
                    tail -= 1;
                    while tail > idx && nums[tail] == nums[tail + 1] {
                        tail -= 1;
                    }
                    if tail <= idx {
                        break;
                    }
                }
            }
        }

        return result;
    }
}
// @lc code=end

