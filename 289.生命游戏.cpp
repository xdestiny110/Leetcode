/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        if(board.empty()) return;
        int rows = board.size(), cols = board[0].size();
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                int liveCnt = 0;
                // dead->dead: 00b
                // live->live: 11b
                // live->dead: 01b
                // dead->live: 10b
                if(r - 1 >= 0 && c - 1 >= 0 && (board[r - 1][c - 1] & 1))
                    liveCnt++;
                if(r - 1 >= 0 && (board[r - 1][c] & 1))
                    liveCnt++;
                if(r - 1 >= 0 && c + 1 < cols && (board[r - 1][c + 1] & 1))
                    liveCnt++;
                if(c - 1 >= 0 && (board[r][c - 1] & 1))
                    liveCnt++;
                if(c + 1 < cols && (board[r][c + 1] & 1))
                    liveCnt++;
                if(r + 1 < rows && c + 1 < cols && (board[r + 1][c + 1] & 1))
                    liveCnt++;
                if(r + 1 < rows && (board[r + 1][c] & 1))
                    liveCnt++;
                if(r + 1 < rows && c - 1 >= 0 && (board[r + 1][c - 1] & 1))
                    liveCnt++;
                if(board[r][c] & 1){
                    if(liveCnt == 2 || liveCnt == 3){
                        board[r][c] = 3;
                    }
                }
                else if(liveCnt == 3){
                    board[r][c] = 2;
                }
            }
        }

        for(auto&& it : board){
            for(auto&& jt : it){
                jt >>= 1;
            }
        }
    }
};
// @lc code=end

