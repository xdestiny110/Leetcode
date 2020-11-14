/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int left = 1, right = n;
        while(true){
            auto mid = (right - left) / 2 + left;
            if(isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid;
            }
            if(right - left <= 1) return right;
        }
    }
};
// @lc code=end

