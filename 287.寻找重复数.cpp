/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(true){
            auto mid = (left + right) / 2;
            int small = 0, big = 0, equal = 0;
            for(const auto& it : nums){
                if(it >= left && it <= right){
                    if(it == mid)
                        equal++;
                    else if(it < mid)
                        small++;
                    else if(it > mid)
                        big++;
                }
            }
            if(equal > 1) return mid;
            if(small > big){
                right = mid - 1;
            }
            else if(small < big) {
                left = mid + 1;
            }
            else if(mid - left < right - mid){
                right = mid;
            }
            else{
                left = mid;
            }
        }
    }
};
// @lc code=end

