/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        for(int i = 0; i <= nums.size(); i++){
            DFS(0, i, nums, {});
        }
        return result;
    }

private:
    std::vector<std::vector<int>> result;

    void DFS(int layer, int maxCnt, const std::vector<int>& nums, std::vector<int>&& r){
        if(r.size() == maxCnt){
            result.emplace_back(r);
            return;
        }

        for(int i = layer; i < nums.size(); i++){
            r.emplace_back(nums[i]);
            DFS(i+1, maxCnt, nums, std::move(r));
            r.pop_back();
        }
    }
};
// @lc code=end

