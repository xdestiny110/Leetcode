/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        if(arr.size() <= 2) return true;
        std::sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); ++i){
            if(arr[i] - arr[i-1] != diff) return false;
        }
        return true;
    }
};
// @lc code=end

