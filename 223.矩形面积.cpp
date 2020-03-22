/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
#include <algorithm>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        bool isNotOverlap = (C <= E) || (G <= A) || (D <= F) || (H <= B);
        auto s = (static_cast<long long>(C-A))*(D-B)+(G-E)*(H-F);
        if(isNotOverlap) return s;
        s -= (std::min(C,G) - std::max(A,E)) * (std::min(D,H) - std::max(B,F));
        return s;
    }
};
// @lc code=end

