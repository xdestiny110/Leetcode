/*
 * @lc app=leetcode.cn id=36 lang=rust
 *
 * [36] 有效的数独
 */

// @lc code=start
use std::collections::HashSet;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row_used_nums = vec![HashSet::<char>::new(); 9];
        let mut cols_used_nums = vec![HashSet::<char>::new(); 9];
        let mut grid_used_nums = vec![HashSet::<char>::new(); 9];
        for row in 0..9 {
            for col in 0..9 {
                let c = board[row][col];
                if c != '.' {
                    if row_used_nums[row].contains(&c) || cols_used_nums[col].contains(&c) || grid_used_nums[row / 3 * 3 + col / 3].contains(&c) {
                        return false;
                    }
                    row_used_nums[row].insert(c);
                    cols_used_nums[col].insert(c);
                    grid_used_nums[row / 3 * 3 + col / 3].insert(c);
                }
            }
        }

        return true;
    }
}
// @lc code=end

