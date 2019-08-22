/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

#include <unordered_map>

class Solution {
public:
    int totalNQueens(int n) {
        DFS(0, n);
        return result;
    }
    
private:
    std::unordered_map<int, int> chess;
    int result = 0;

    void DFS(int layer, int n){
        if(layer >= n){
            result++;
            return;
        }

        for(int i = 0; i < n; i++){
            if(checkQueen(layer, i)){
                chess[layer] = i;
                DFS(layer+1, n);
                chess.erase(layer);
            }
        }

    }

    bool checkQueen(int r, int c){
        for(const auto& it : chess){
            if((r == it.first) || (c == it.second) || (std::abs(static_cast<float>(r-it.first)/(c-it.second)) == 1.f))
                return false;
        }
        return true;
    }
};

