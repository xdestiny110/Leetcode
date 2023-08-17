/*
 * @lc app=leetcode.cn id=2682 lang=rust
 *
 * [2682] 找出转圈游戏输家
 */

// @lc code=start

use std::collections::HashSet;

impl Solution {
    pub fn circular_game_losers(n: i32, k: i32) -> Vec<i32> {
        let mut ball_count = HashSet::new();
        ball_count.insert(0);
    
        let mut current_idx = 0;
        loop {
            current_idx += k * (ball_count.len() as i32);
            current_idx %= n;
            if ball_count.contains(&current_idx) {
                break;
            }
            ball_count.insert(current_idx);
        }
        
        let mut result = Vec::<i32>::new();
        for idx in 0..n {
            if !ball_count.contains(&idx) {
                result.push((idx + 1) as i32);
            }
        }
        return result;
    }
}
// @lc code=end

