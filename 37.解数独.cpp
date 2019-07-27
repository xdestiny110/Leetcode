/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <vector>
#include <unordered_set>
#include <utility>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        rowRecord.resize(9);
        colRecord.resize(9);
        quadRecord.resize(9);

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                const auto& ch = board[r][c];
                if(ch != '.'){
                    rowRecord[r].insert(ch);
                    colRecord[c].insert(ch);
                    quadRecord[r/3*3+c/3].insert(ch);
                }
            }
        }

        DFS(std::forward<std::vector<std::vector<char>>>(board), 0);
    }
private:

    void DFS(std::vector<std::vector<char>>&& board, int idx){
        if(idx >= 81){
            flag = true;
            return;
        }

        int r = idx / 9;
        int c = idx - r*9;
        const auto& ch = board[r][c];

        if(ch != '.'){
            DFS(std::forward<std::vector<std::vector<char>>>(board), idx+1);
            return;
        }
        else{
            auto& rowRec = rowRecord[r];
            auto& colRec = colRecord[c];
            auto& quadRec = quadRecord[r/3*3+c/3];
            for(char select = '1'; select <= '9'; select++){
                if(rowRec.find(select) == rowRec.end()
                    && colRec.find(select) == colRec.end()
                    && quadRec.find(select) == quadRec.end())
                {
                    rowRec.insert(select);
                    colRec.insert(select);
                    quadRec.insert(select);
                    board[r][c] = select;
                    DFS(std::forward<std::vector<std::vector<char>>>(board), idx+1);
                    if(flag){
                        return;
                    }
                    rowRec.erase(select);
                    colRec.erase(select);
                    quadRec.erase(select);
                    board[r][c] = '.';
                }
            }
        }
    }

    std::vector<std::unordered_set<char>> rowRecord;
    std::vector<std::unordered_set<char>> colRecord;
    std::vector<std::unordered_set<char>> quadRecord;
    bool flag = false;
};

