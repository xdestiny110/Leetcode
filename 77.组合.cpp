/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0)
            return {};
        _n = n;
        _k = k;
        DFS(0);
        return result;
    }

private:
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    int _n, _k;

    void DFS(int layer){
        if(layer >= _k){
            result.emplace_back(temp);
            return;
        }

        for(int i = temp.empty()?1:temp.back()+1; i <= _n; i++){
            temp.emplace_back(i);
            DFS(layer+1);
            temp.pop_back();
        }
    }
};

