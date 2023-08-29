/*
 * @lc app=leetcode.cn id=37 lang=rust
 *
 * [37] 解数独
 */

// @lc code=start

use std::collections::HashSet;

fn next_x_y(board: &mut Vec<Vec<char>>, x: usize, y: usize) -> Option<(usize, usize)> {
    for next_y in y..9 {
        for next_x in 0..9 {
            if board[next_y][next_x] == '.' {
                return Some((next_x, next_y));
            }
        }
    }
    None 
}

fn dfs(board: &mut Vec<Vec<char>>, x: usize, y: usize, flag: &mut bool) {
    let mut used_nums = HashSet::new();
    for i in 0..9 {
        if board[y][i] != '.' {
            used_nums.insert(board[y][i]);
        }
        if board[i][x] != '.' {
            used_nums.insert(board[i][x]);
        }
    }
    for i in 0..3 {
        for j in 0..3 {
            if board[y / 3 * 3 + i][x / 3 * 3 + j] != '.' {
                used_nums.insert(board[y / 3 * 3 + i][x / 3 * 3 + j]);
            }
        }
    }

    for num in '1'..='9' {
        if !used_nums.contains(&num) {
            board[y][x] = num;
            if let Some((next_x, next_y)) = next_x_y(board, x, y) {
                dfs(board, next_x, next_y, flag);
                if *flag {
                    return;
                }
            } else {
                *flag = true;
                return;
            }
        }
    }
    board[y][x] = '.';
}

impl Solution {
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        if let Some((next_x, next_y)) = next_x_y(board, 0, 0) {
            let mut flag = false;
            dfs(board, next_x, next_y, &mut flag);
        }
    }
}
// @lc code=end

