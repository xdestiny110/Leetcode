/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        return pow_fast(x, n);
    }

private:
    double pow_fast(double a, int b) const {
        if (b == 0) return 1;
        auto b_abs = std::abs(b);
        double result = 1.0;
        while (b_abs > 0) {
            if (b_abs % 2 != 0) {
                result *= a;
            }
            a *= a;
            b_abs /= 2;
        }
        return (b > 0) ? result : 1.0 / result;
    }
};
// @lc code=end

