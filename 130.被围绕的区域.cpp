/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

#include <vector>
#include <unordered_set>

struct pairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if(board.empty())
            return;
        for(int i = 0; i < board.size(); ++i){
            fill(board, {0, i});
            fill(board, {board[0].size() - 1, i});
        }
        for(int i = 0; i < board[0].size(); ++i){
            fill(board, {i, 0});
            fill(board, {i, board.size() - 1});
        }

        for(int y = 0; y < board.size(); ++y){
            for(int x = 0; x < board[y].size(); ++x){
                if(board[y][x] == 'O' && record.find({x,y}) == record.end()){
                    board[y][x] = 'X';
                }
            }
        }
    }

private:
    std::unordered_set<std::pair<int, int>, pairHash> record;
    void fill(const std::vector<std::vector<char>>& board, const std::pair<int, int>& nowXY){
        
        if(board[nowXY.second][nowXY.first] == 'O' && record.find(nowXY) == record.end()){
            record.insert(nowXY);
            auto nextXY = nowXY;

            nextXY.first -= 1;
            if(nextXY.first >= 0 && record.find(nextXY) == record.end()){
                fill(board, nextXY);
            }
            nextXY.first += 1;

            nextXY.first += 1;
            if(nextXY.first < board[0].size() && record.find(nextXY) == record.end()){
                fill(board, nextXY);
            }
            nextXY.first -= 1;

            nextXY.second -= 1;
            if(nextXY.second >= 0 && record.find(nextXY) == record.end()){
                fill(board, nextXY);
            }
            nextXY.second += 1;

            nextXY.second += 1;
            if(nextXY.second < board.size() && record.find(nextXY) == record.end()){
                fill(board, nextXY);
            }
            nextXY.second -= 1;
        }
    }
};
// @lc code=end

