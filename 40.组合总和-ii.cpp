/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> temp;
        DFS(0, target, candidates, 0, std::forward<std::vector<int>>(temp));
        return result;
    }

private:
    std::vector<std::vector<int>> result;

    void DFS(int layer, int target, const std::vector<int>& candidates, int sum, std::vector<int>&& r){
        for(int i = layer; i < candidates.size(); i++){

            if(i > layer && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] + sum == target){
                r.push_back(candidates[i]);
                result.push_back(r);
                r.pop_back();
                return;
            }

            if(candidates[i] + sum > target)
                return;
            
            r.push_back(candidates[i]);
            DFS(i+1, target, candidates, sum+candidates[i], std::forward<std::vector<int>>(r));
            r.pop_back();
        }
    }
};

