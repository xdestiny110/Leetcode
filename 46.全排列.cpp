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
        std::vector<uint8_t> used(nums.size(), 0);
        std::vector<int> r;
        DFS(nums, used, r);
        return result;
    }

private:
    void DFS(const std::vector<int>& nums, std::vector<uint8_t>& used, std::vector<int>& r){
        if (r.size() == nums.size()) {
            result.push_back(r);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] > 0) continue;
            r.push_back(nums[i]);
            used[i] = 1;
            DFS(nums, used, r);
            r.pop_back();
            used[i] = 0;
        }
    }

    std::vector<std::vector<int>> result;
};

