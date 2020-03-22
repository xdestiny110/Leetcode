/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if(nums.empty()) return {};
        std::vector<std::string> r;
        int f = nums[0];
        int start = f;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != f + 1){
                insertResult(start, f, r);
                start = nums[i];
            }
            f = nums[i];
        }
        insertResult(start, f, r);
        return r;
    }

private:
    void insertResult(int start, int f, std::vector<std::string>& r) const{
        if(start == f){
            r.emplace_back(std::to_string(f));
        }
        else{
            r.emplace_back(std::to_string(start) + "->" + std::to_string(f));
        }
    }
};
// @lc code=end

