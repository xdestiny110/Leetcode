/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        DFS(std::forward<std::vector<int>>(nums), {});
        return result;
    }

private:
    void DFS(std::vector<int>&& nums, std::vector<int>&& r){
        if(nums.empty()){
            result.push_back(r);
            return;
        }

        for(auto it = nums.begin(); it != nums.end(); it++){
            if(it != nums.begin() && *(it-1) == *it)
                continue;
            auto temp = *it;
            r.push_back(temp);
            it = nums.erase(it);
            DFS(std::forward<std::vector<int>>(nums), std::forward<std::vector<int>>(r));
            nums.insert(it, temp);
            r.pop_back();
        }
    }

    std::vector<std::vector<int>> result;
};

