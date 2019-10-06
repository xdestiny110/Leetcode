/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> result(m+n);
        int i = 0, j = 0;
        for(; i < m && j < n;){
            if(nums1[i] < nums2[j]){
                result[i+j] = nums1[i];
                i++;
            }
            else{
                result[i+j] = nums2[j];
                j++;
            }
        }
        
        if(i >= m){
            std::copy(nums2.begin() + j, nums2.begin() + n, result.begin() + i + j);
        }
        else{
            std::copy(nums1.begin() + i, nums1.begin() + m, result.begin() + i + j);
        }
        std::copy(result.begin(), result.end(), nums1.begin());
    }
};
// @lc code=end

