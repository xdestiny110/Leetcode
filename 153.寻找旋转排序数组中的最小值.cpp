/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        return *binarySearch(nums.begin(), nums.end());
    }

private:
    std::vector<int>::const_iterator binarySearch(std::vector<int>::const_iterator left, std::vector<int>::const_iterator right) const{
        auto dis = std::distance(left, right);
        if(dis <= 1){
            return left;
        }
        if(dis == 2){
            return (*left < *(right-1))?left:right-1;
        }

        auto mid = left + dis / 2;
        if(*mid > *left && *(right-1) > *left){
            return left;
        }
        else if(*mid < *left && *(right-1) < *left){
            return binarySearch(left, mid + 1);
        }
        return binarySearch(mid, right);
    }

};
// @lc code=end

