/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        std::vector<int> f(n);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < n; i++)
            f[i] = f[i-1]+f[i-2];
        return f.back();
    }
};

