/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        DFS(0, target, candidates, 0, std::vector<int>());
        return result;
    }

private:
    std::vector<std::vector<int>> result;

    void DFS(int layer, int target, const std::vector<int>& candidates, int sum, std::vector<int>&& r){
        for(int i = layer; i < candidates.size(); i++){

            if(candidates[i] + sum == target){
                r.push_back(candidates[i]);
                result.push_back(r);
                r.pop_back();
                return;
            }

            if(candidates[i] + sum > target)
                return;
            
            r.push_back(candidates[i]);
            DFS(i, target, candidates, sum+candidates[i], std::move(r));
            r.pop_back();
        }
    }

};

