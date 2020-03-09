/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        if(nums.empty() || k == 0) return;
        int n = nums.size();
        do{
            for(int i = 0; i < k; ++i){
                std::swap(nums[i + nums.size() - n], nums[nums.size() - k + i]);
            }
            n -= k;
            if(n == 0) break;
            k %= n;
        }while(n > 0 && k > 0);
    }
};
// @lc code=end

