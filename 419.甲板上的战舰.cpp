/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int countBattleships(std::vector<std::vector<char>>& board) {
        int result = 0;
        auto row = board.size();
        auto col = board[0].size();
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (board[r][c] != 'X') {
                    continue;
                }
                board[r][c] = '.';
                auto dir = check_dir(board, r, c);
                if (dir == 'H') {
                    for (int cc = c + 1; cc < col && board[r][cc] == 'X'; ++cc) {
                        board[r][cc] = '.';
                    }
                } else if (dir == 'V') {
                    for (int rr = r + 1; rr < row && board[rr][c] == 'X'; ++rr) {
                        board[rr][c] = '.';
                    }
                }
                result++;
            }
        }
        return result;
    }

private:
    char check_dir(const std::vector<std::vector<char>>& board, int r, int c) const {
        if (c < board[0].size() - 1 && board[r][c + 1] == 'X') {
            return 'H';
        }
        if (r < board.size() - 1 && board[r + 1][c] == 'X') {
            return 'V';
        }
        return 'O';
    }
};
// @lc code=end

