/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <algorithm>

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++){
            DFS(0, i, nums, {}, std::string(""));
        }
        std::vector<std::vector<int>> ret;
        for(auto&& it : record){
            ret.emplace_back(std::move(it.second));
        }
        return ret;
    }
private:
    void DFS(int idx, int maxLayer, const std::vector<int>& nums, std::vector<int>&& ret, std::string&& key){
        if(ret.size() >= maxLayer){
            if(record.find(key) == record.end()){
                record[key] = ret;
            }   
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            ret.emplace_back(nums[i]);
            key.push_back('0' + nums[i]);
            DFS(i + 1, maxLayer, nums, std::move(ret), std::move(key));
            ret.pop_back();
            key.pop_back();
        }
    }
    std::unordered_map<std::string, std::vector<int>> record;
};
// @lc code=end

