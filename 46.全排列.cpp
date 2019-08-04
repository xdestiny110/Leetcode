/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
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

