/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <vector>
#include <unordered_set>
#include <utility>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {

        std::vector<std::unordered_set<char>> rowRecord(9);
        std::vector<std::unordered_set<char>> colRecord(9);
        std::vector<std::unordered_set<char>> quadRecord(9);
        
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board.size(); c++){
                auto ch = board[r][c];
                if(ch == '.')
                    continue;
                
                if(!(checkExist(std::move(rowRecord[r]), ch)
                     && checkExist(std::move(colRecord[c]), ch)
                     && checkExist(std::move(quadRecord[r/3*3+c/3]), ch)))
                {
                    return false;
                }
            }
        }

        return true;
    }
private:
    template<typename T>
    bool checkExist(std::unordered_set<T>&& s, const T& target){
        if(s.find(target) != s.end())
            return false;
        s.insert(target);
        return true;
    }
};

