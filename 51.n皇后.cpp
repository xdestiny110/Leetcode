/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        DFS(0,n);
        return result;
    }

private:
    std::unordered_map<int, int> chess;
    std::vector<std::vector<std::string>> result;

    void DFS(int layer, int n){
        if(layer >= n){
            print(n);
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

    void print(const int& n){
        std::vector<std::string> r;
        r.reserve(n);
        for(int i = 0; i < n; i++){
            r.emplace_back(n, '.');
            r[i][chess[i]] = 'Q';
        }
        result.emplace_back(r);
    }
};

