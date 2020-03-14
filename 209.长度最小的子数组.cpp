/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) {
        if(nums.empty()) return 0;
        int windowLen = 1;
        std::vector<int> accSum;
        accSum.reserve(nums.size());
        accSum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            accSum[i] = nums[i] + accSum[i-1];
        }
        
        while(windowLen <= nums.size()){
            for(int start = 0; start <= nums.size() - windowLen; ++start){
                int end = start + windowLen - 1;
                int sum = accSum[end] - accSum[start] + nums[start];
                if(sum >= s) return windowLen;
            }
            windowLen++;
        }
        return 0;
    }
};
// @lc code=end

